/*
	작성자: 박태정
	파일버전 0.8
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/
//컨트롤 클래스 소스파일
#include "BankingCommonDecl.h" // 기본세팅 헤더파일 <iostream>, <cstring>, enum, using namespace std 등등
#include "AccountHandler.h" // 컨트롤 클래스 함수의 선언이 있는 헤더파일 추가
#include "Account.h" //계좌 클래스의 함수의 선언이 있는 헤더파일 추가
#include "NormalAccount.h" // 보통예금계좌 클래스 함수 선언이 있는 헤더파일 추가
#include "HighCreditAccount.h" // 신용신뢰계좌 클래스 함수 선언이 있는 헤더파일 추가
#include "String.h" // string 클래스 추가

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
	// char name[NAME_LEN]; String형으로 name 선언
	String name;
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