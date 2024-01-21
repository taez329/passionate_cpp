#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER}; //enum을 쓰면 CLERK 부터 0, 1, 2, 3의 값이 주어짐 
	
	void ShowWorkInfo(int work)
	{
		switch(work)
		{
			case CLERK:
				cout<<"사원"<<endl;
				break;
			case SENIOR:
				cout<<"주임"<<endl;
				break;
			case ASSIST:
				cout<<"대리"<<endl;
				break;
			case MANAGER:
				cout<<"과장"<<endl;
		}
	}
}
class NameCard
{
private:
	char * name;
	char * company;
	char * number;
	int work;

public:
	NameCard(const char * e_name, const char * e_company, const char * e_number, int e_work)
		: work(e_work)
	{
		name=new char[strlen(e_name)+1];
		strcpy(name, e_name);
		company=new char[strlen(e_company)+1];
		strcpy(company, e_company);
		number=new char[strlen(e_number)+1];
		strcpy(number, e_number);
	}
	
	NameCard(const NameCard& copy) : work(copy.work)
	{
		name=new char[strlen(copy.name)+1];
		strcpy(name, copy.name);
		company=new char[strlen(copy.company)+1];
		strcpy(company, copy.company);
		number=new char[strlen(copy.number)+1];
		strcpy(number, copy.number);
	} 
	// 깊은 복사를 위한 복사 생성자의 정의
	// 메모리 공간 할당후 문자열 복사, 그리고 할당된 메모리의 주소 값을 멤버에 저장시킨다.
	// 얕은 복사면 하나의 문자열을 두 개의 객체가 동시에 참조해버림
	
	void ShowNameCardInfo()
	{
		cout<<"이름: "<<name<<'\n';
		cout<<"회사: "<<company<<'\n';
		cout<<"전화번호: "<<number<<'\n';
		cout<<"직급: ";
		COMP_POS::ShowWorkInfo(work);
		cout<<'\n';
	}
	~NameCard()
	{
		delete []name;
		delete []company;
		delete []number;
	}
};

int main()
{
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1=manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2=manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();

	return 0;
}