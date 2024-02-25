/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#include "BankingCommonDecl.h" // 기본세팅 헤더파일 <iostream>, <cstring>, enum, using namespace std 등등
#include "NormalAccount.h" // 함수의 선언이 있는 클래스 추가

NormalAccount::NormalAccount(int id, char* _name, int money, int _interest)
		:Account(id, _name, money), interest(_interest)
	{ }

void NormalAccount::Deposit(int money)
	{
		Account::Deposit(money); //원금추가
		Account::Deposit(money*(interest/100.0)); //이자추가
	}