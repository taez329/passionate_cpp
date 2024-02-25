/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#include "BankingCommonDecl.h" // 기본세팅 헤더파일 <iostream>, <cstring>, enum, using namespace std 등등
#include "HighCreditAccount.h" // 함수의 선언이 있는 클래스 추가

HighCreditAccount::HighCreditAccount(int id, String _name, int money, int _interest, int _credit)
		: NormalAccount(id, _name, money, _interest), credit(_credit)
	{ }

void HighCreditAccount::Deposit(int money)
	{
		NormalAccount::Deposit(money); //원금과 이자추가
		Account::Deposit(money*(credit/100.0)); //신용등급에 따른 이자 추가
	}