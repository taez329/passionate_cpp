//멤버함수에 const 선언 추가해서 안정성 더하기
#include <iostream>
#include <cstring>
#define NAME_LEN 20
using namespace std;

void ShowMenu();
void MakeAccount();
void InputMoney();
void OutputMoney();
void PrintInfo();

enum {MAKE=1, INPUT, OUTPUT, PRINT, EXIT};

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
		//new char(strlen(ref.name)+1); 
		// 이런식으로 하면 원칙상 문자 하나를 저장하기 위한 동적할당이기에 부적절하다
		strcpy(name, ref.name);
	}
	int GetId() { return account_id; } const //객체의 id 반환, const 추가
	void Deposit(int money) // 입금
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

Account * accArr[100]; //Account 클래스의 객체 저장을 위한 배열
int accNum=0;

void ShowMenu()
{
	cout<<"-----Menu------"<<endl;
	cout<<"1. 계좌개설"<<endl;
	cout<<"2. 입 금"<<endl;
	cout<<"3. 출 금"<<endl;
	cout<<"4. 계좌정보 전체 출력"<<endl;
	cout<<"5. 프로그램 종료"<<endl;
}

void MakeAccount()
{
	int id;
	char name[NAME_LEN];
	int money;
	
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌 ID: "; cin>>id;
	cout<<"이 름: "; cin>>name;
	cout<<"입금액: "; cin>>money;
	
	accArr[accNum++]=new Account(id, name, money);
}

void InputMoney()
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

void OutputMoney()
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

void PrintInfo()
{
	for (int i=0; i<accNum; i++)
	{
		accArr[i]->ShowInfo();
		cout<<endl;
	}
}

int main()
{
	int choice;
	
	while(1)
	{
		ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				MakeAccount();
				break;
			case INPUT:
				InputMoney();
				break;
			case OUTPUT:
				OutputMoney();
				break;
			case PRINT:
				PrintInfo();
				break;
			case EXIT:
				for(int i=0; i<accNUm; i++)
					delete accArr[i] //프로그램 끝내기 전에 동적할당했던 메모리 공간 누수 없애기				
				return 0;
			default:
				cout<<"알맞은 입력이 필요합니다."<<endl; //잘못된 입력이 있을때 처리
		}
	}
}

