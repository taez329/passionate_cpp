//상속클래스의 추가
#include <iostream>
#include <cstring>
#define NAME_LEN 20
using namespace std;

enum {MAKE=1, INPUT, OUTPUT, PRINT, EXIT};

enum {CREDIT_A=7, CREDIT_B=4, CREDIT_C=1};

class Account
{
private:
	char* name;
	int account_id;
	int balance;
public:
	Account(int id, char * _name, int money) //생성자
		: account_id(id), balance(money)
	{
		name=new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	Account(const Account &ref)
		: account_id(ref.account_id), balance(ref.balance)
	{
		name=new char[strlen(ref.name)+1];
		strcpy(name, ref.name);
	}
	int GetId() const { return account_id; } //객체의 id 반환, const 추가
	/*
	여기서 별표 백만개!!!!! Acount를 상속할 NormalAccount와 HighCreditAccount에서
		함수를 재정의하고 쓰고 싶으므로(함수 오버라이딩을 하고싶을때) "virtual" 이라는 가상함수 임을 알리는
		예약어를 써서 재정의가 가능하게 해야한다
		virtual : 파생 클래스에서 재정의할 것으로 기대하는 멤버 함수
	*/
	virtual void Deposit(int money) // 입금, 재정의할 것이기에 virtual 예약어
	{
		balance+=money; 
	}
	int Withdraw(int money) //조건에 맞으면 출금 
	{
		if(money>balance)
			return 0;
		balance-=money;
		return money;
	}
	void ShowInfo() const //고객의 정보 출력, const 추가
	{
		cout<<"계좌ID: "<<account_id<<endl;
		cout<<"이 름: "<<name<<endl;
		cout<<"잔 액: "<<balance<<endl;
	}
	~Account() { delete []name; } //소멸자
	
};

class NormalAccount : public Account // 보통예금계좌
{
private:
	int interest;
public:
	NormalAccount(int id, char* _name, int money, int _interest)
		:Account(id, _name, money), interest(_interest)
	{ }
	virtual void Deposit(int money)
	{
		Account::Deposit(money); //원금추가
		Account::Deposit(money*(interest/100.0)); //이자추가
	}
};

class HighCreditAccount : public NormalAccount // 신용신뢰계좌
{
private:
	int credit;
public:
	HighCreditAccount(int id, char* _name, int money, int _interest, int _credit)
		: NormalAccount(id, _name, money, _interest), credit(_credit)
	{ }
	virtual void Deposit(int money)
	{
		NormalAccount::Deposit(money); //원금과 이자추가
		Account::Deposit(money*(credit/100.0)); //신용등급에 따른 이자 추가
	}
};

class AccountHandler // 컨트롤 클래스
{
private:
	Account * accArr[100]; //Account 클래스의 객체 저장을 위한 배열
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void InputMoney();
	void OutputMoney();
	void PrintInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount(); //protected로 선언하는 것이 더 안전
};

AccountHandler::AccountHandler() : accNum(0)
{ }

AccountHandler::~AccountHandler()
{
	for(int i=0; i<accNum; i++)
		delete accArr[i];
} // 소멸자에서 메모리 누수 막기 위해 해제

void AccountHandler::ShowMenu() const
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void AccountHandler::MakeAccount()
{
	int n;
	
	cout<<"[계좌종류선택]"<<endl;
	cout<<"1.보통예금계좌 2.신용신뢰계좌"<<endl;
	cout<<"선택: "; cin>>n;
	if (n==1)
	{
		AccountHandler::MakeNormalAccount();
		return;
	}
	else if(n==2)
	{
		AccountHandler::MakeHighCreditAccount();
		return;
	}
	cout<<"올바르지 않은 입력입니다."<<endl;
}

void AccountHandler::MakeNormalAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	int interest;
	
	cout<<"[보통예금계좌개설]"<<endl;
	cout<<"계좌 ID: "; cin>>id;
	cout<<"이 름: "; cin>>name;
	cout<<"입금액: "; cin>>money;
	cout<<"이자율: "; cin>>interest;
	
	accArr[accNum++]=new NormalAccount(id, name, money, interest);
}

void AccountHandler::MakeHighCreditAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	int interest;
	int credit;
	
	cout<<"[신용신뢰계좌개설]"<<endl;
	cout<<"계좌 ID: "; cin>>id;
	cout<<"이 름: "; cin>>name;
	cout<<"입금액: "; cin>>money;
	cout<<"이자율: "; cin>>interest;
	cout<<"신용등급(1toA, 2toB, 3toC): "; cin>>credit;
	
	switch(credit)
	{
	case 1:
		accArr[accNum++]=new HighCreditAccount(id, name, money, interest, CREDIT_A);
		break;
	case 2:
		accArr[accNum++]=new HighCreditAccount(id, name, money, interest, CREDIT_B);
		break;
	case 3:
		accArr[accNum++]=new HighCreditAccount(id, name, money, interest, CREDIT_C);
		break;
	}
}

void AccountHandler::InputMoney()
{
	int id;
	int input;
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"입금액: "; cin>>input;
	
	for (int i=0; i<accNum; i++)
	{
		if (accArr[i]->GetId()==id)
		{
			accArr[i]->Deposit(input);
			cout<<"입금완료"<<endl;
			return;
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl;
}

void AccountHandler::OutputMoney()
{
	int id;
	int output;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: "; cin>>id;
	cout<<"출금액: "; cin>>output;
	
	for (int i=0; i<accNum; i++)
	{
		if (accArr[i]->GetId()==id)
		{
			if(accArr[i]->Withdraw(output)==0) //출금하는 함수 실행, 만약 0이 리턴되면 잔액이 부족한걸로 설정해서 안내문 출력
			{
				cout<<"계좌잔액이 부족합니다"<<endl;
				return;
			}
			cout<<"출금완료"<<endl; //어쨌든 if문 안의 함수가 실행되기에
			return;
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl;
}

void AccountHandler::PrintInfo() const
{
	for (int i=0; i<accNum; i++)
	{
		accArr[i]->ShowInfo();
		cout<<endl;
	}
}

int main()
{
	AccountHandler manager;
	int choice;
	
	while(1)
	{
		manager.ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				manager.MakeAccount();
				break;
			case INPUT:
				manager.InputMoney();
				break;
			case OUTPUT:
				manager.OutputMoney();
				break;
			case PRINT:
				manager.PrintInfo();
				break;
			case EXIT:	
				return 0;
			default:
				cout<<"알맞은 입력이 필요합니다."<<endl; //잘못된 입력이 있을때 처리
		}
	}
}