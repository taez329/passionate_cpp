#include <iostream>
#include <cstring>
using namespace std;

class Employee
{
private:
	char name[100];
public:
	Employee(char* name)
	{
		strcpy(this->name, name);
	}
	void ShowYourName() const
	{
		cout<<"name: "<<name<<endl;
	}
	virtual int GetPay() const=0; //순수 가상함수 선언 따라서 Employee 클래스는 추상클래스가 되었다
	virtual void ShowSalaryInfo() const=0;
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(char* name, int money)
		: Employee(name), salary(money)
	{ }
	int GetPay() const
	{
		return salary;
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

class TemporaryWorker : public Employee
{
   //생략, 문제에서 쓰이지 않음
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;
	double bonusRatio;
public:
	SalesWorker(char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value)
	{
		salesResult+=value;
	}
	int GetPay() const
	{
		return PermanentWorker::GetPay() //PermanentWorer의 GetPay() 함수 호출
					+ (int)(salesResult*bonusRatio);
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
};

namespace RISK_LEVEL
{
	enum {RISK_A=30, RISK_B=20, RISK_C=10}; //enum을 이용해서 각각 문구에 값 넣기
	//enum={   } 이렇게 쓰는 거 아니다 기억하자
}

class ForeignSalesWorker : public SalesWorker 
{
private:
	const int riskratio; //enum로 변수를 상수화 했으므로 const로 명시해주자
public:
	ForeignSalesWorker(char* name, int money, double ratio, int risk) //enum으로 바꿔놓은 걸 매개변수로 바꿀때는 바꾼 값의 자료형으로 받으면 됨 여기서는 int risk로 받음
		: SalesWorker(name, money, ratio), riskratio(risk)
	{ }
	int riskpay() const
	{
		return (int) (SalesWorker::GetPay() * riskratio/100.0); 
		//해외 영업직의 위험수당 계산함수
		//혹시 모를 오류를 대비해 (int) 형변환과 100.0으로 표시를 해놓은 것
		// return (SalesWorker::GetPay() * riskratio/100); 이 코드로도 가능하긴 한데 위와같이 표시하는 습관 기르자
	}
	int GetPay() const 
	{
		return SalesWorker::GetPay() + riskpay(); //총급여계산
	}
	void ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<SalesWorker::GetPay()<<endl;
		cout<<"risk pay: "<<riskpay()<<endl;
		cout<<"sum: "<<GetPay()<<endl<<endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++]=emp;
	}
	void ShowAllSalaryInfo() const
	{
		for(int i=0; i<empNum; i++)
			empList[i]->ShowSalaryInfo();
		//Employee 클래스에 가상함수 선언을 해놨기에 가능
		//배열을 구성하는 포인터 변수가 Employee형 포인터 변수이므로, Employee 클래스의 멤버가 아닌
		//GetPay, ShowSalaryInfo 함수 호출에서 컴파일 에러 발생
		//Employee형 포인터 변수로 호출할 수 있게 Employee 클래스에 가상함수로 선언
	}
	void ShowTotalSalary() const
	{
		int sum=0;
		for(int i=0; i<empNum; i++)
			sum+=empList[i]->GetPay(); //위와 동일
		cout<<"salary sum: "<<sum<<endl;
	}
	~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
			delete empList[i];
	}
};

int main()
{
	EmployeeHandler handler;
	
	/*
	SalesWorker * seller=new SalesWorker("Park", 1000, 0.1);
	seller->AddSalesResult(6000);
	handler.AddEmployee(seller);
	문제해결 전 정상작동 확인을 위해서 사용
	*/
	
	ForeignSalesWorker * fseller1=new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller1);
	
	ForeignSalesWorker * fseller2=new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller2);
	
	ForeignSalesWorker * fseller3=new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000); // 영업실적 7000
	handler.AddEmployee(fseller3);
	
	handler.ShowAllSalaryInfo();
	handler.ShowTotalSalary();
	return 0;
}