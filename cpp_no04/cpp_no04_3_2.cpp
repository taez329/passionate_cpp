#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
	enum {CLERK, SENIOR, ASSIST, MANAGER}; //enum을 쓰면 CLERK 부터 0, 1, 2, 3의 값이 주어짐 
	
	void ShowWorkInfo(int work)
	{
		if (work==0)
			cout<<"사원"<<'\n';
		else if (work==1)
			cout<<"주임"<<'\n';
		else if (work==2)
			cout<<"대리"<<'\n';
		else if (work==3)
			cout<<"과장"<<'\n';
	}
	
	/*
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
	*/
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
		// strcpy=(name, e_name); 이게 무슨 짓이야 태정아...
		strcpy(name, e_name);
		company=new char[strlen(e_company)+1];
		strcpy(company, e_company);
		number=new char[strlen(e_number)+1];
		strcpy(number, e_number);
	}
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
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMP_POS::ASSIST); //c++에서는 문자열 리터럴이 상수이기에 char * 로 받으면 경고 뜸
	//const char * 로 받으면 해결
	manClerk.ShowNameCardInfo();
	manSENIOR.ShowNameCardInfo();
	manAssist.ShowNameCardInfo();
	return 0;
}