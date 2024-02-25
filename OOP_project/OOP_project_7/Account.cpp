/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#include "BankingCommonDecl.h" // 기본세팅 헤더파일 <iostream>, <cstring>, enum, using namespace std 등등
#include "Account.h" // 함수의 선언이 있는 클래스 추가


Account::Account(int id, char * _name, int money) // 함수의 정의
		: account_id(id), balance(money)
	{
		name=new char[strlen(_name)+1];
		strcpy(name, _name);
	}
	
Account::Account(const Account &ref)
		: account_id(ref.account_id), balance(ref.balance)
	{
		name=new char[strlen(ref.name)+1];
		strcpy(name, ref.name);
	}
	
int Account::GetId() const { return account_id; }
	
	
void Account::Deposit(int money) //virtual은 한번 선언하면 계속 virtual
	{
		balance+=money; 
	}
	
int Account::Withdraw(int money)
	{
		if(money>balance)
			return 0;
		balance-=money;
		return money;
	}

void Account::ShowInfo() const
	{
		cout<<"계좌ID: "<<account_id<<endl;
		cout<<"이 름: "<<name<<endl;
		cout<<"잔 액: "<<balance<<endl;
	}

Account::~Account() { delete []name; } //소멸자