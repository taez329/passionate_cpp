//구글은 함수는 NameFunc 이런 식으로 변수는 variable_type 이런 식으로 쓴다함 이케 해봐야지
#include <iostream>
#define NAME_LEN 20 //책에서는 const int NAME_LEN=20; 이케 함
using namespace std;

void ShowMenu();
void MakeAccount();
void InputMoney();
void OutputMoney();
void PrintInfo();

enum {MAKE=1, INPUT, OUTPUT, PRINT, EXIT};

typedef struct Account
{
	char name[NAME_LEN];
	int account_id;
	int balance;
} Account;

Account accArr[100];
int accNum=0; //전역변수로해서 계좌 개설한 사람의 인원수를 샐 수 있도록 순차적으로 배열의 한 인덱스씩 차지

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
	cout<<"[계좌개설]"<<endl;
	cout<<"계좌 ID: "; cin>>accArr[accNum].account_id;
	cout<<"이 름: "; cin>>accArr[accNum].name;
	cout<<"입금액: "; cin>>accArr[accNum].balance;
	accNum++; // 다른 사람의 정보는 다음 배열에 저장
}

void InputMoney()
{
	int acc_id;
	int input;
	
	cout<<"[입 금]"<<endl;
	cout<<"계좌ID: "; cin>>acc_id;
	cout<<"입금액: "; cin>>input;
	
	for (int i=0; i<accNum; i++)
	{
		if (acc_id==accArr[i].account_id)
		{
			accArr[i].balance+=input;
			cout<<"입금완료"<<endl;
			return; //정상입금이면 return 되게 하고
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl; // 유효하지 않을 경우 안내문 출력!!
	//정상일 경우 거기서 return, 아닐 경우를 대비해 return 되지않으면 예외 안내문 출력하는 형식
}

void OutputMoney()
{
	int acc_id;
	int output;
	
	cout<<"[출 금]"<<endl;
	cout<<"계좌ID: "; cin>>acc_id;
	cout<<"출금액: "; cin>>output;
	
	for (int i=0; i<accNum; i++)
	{
		/*
		if (acc_id==accArr[i].account_id && output<=accArr[i].balance)
		{
			accArr[i].balance-=output;
			cout<<"출금완료"<<endl;
			return;
		} 이렇게 하면 각각 조건이 맞지 않을 경우 예외 안내문 출력이 어려워진다
		*/
		if (acc_id==accArr[i].account_id)
		{
			if (output<=accArr[i].balance)
			{
				accArr[i].balance-=output;
				cout<<"출금완료"<<endl;
				return;
			}
			cout<<"계좌잔액이 부족합니다"<<endl; //계좌에 잔액이 부족할 경우
			return;
		}
	}
	cout<<"유효하지 않은 ID입니다."<<endl; //계좌 ID부터 맞지 않을 경우
	
	//이렇게 하는 이유는 첫번째 조건이 맞아야 두번째 조건이 의미가 생기기 때문
	//애초에 id를 다르게 입력하면 자기 계좌가 아니기에 잔액이 충분한지를 따질 이유조차 없음
}

void PrintInfo()
{
	for (int i=0; i<accNum; i++)
	{
		cout<<"계좌ID: "<<accArr[i].account_id<<endl;
		cout<<"이 름: "<<accArr[i].name<<endl;
		cout<<"잔 액: "<<accArr[i].balance<<endl<<endl;
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
				return 0;
		}
	}
}

