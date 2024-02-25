/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/
//이 클래스는 너무 짧아서 그냥 선언과 정의를 동시에 썼음
#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount // 신용신뢰계좌
{
private:
	int credit;
public:
	HighCreditAccount(int id, char* _name, int money, int _interest, int _credit);
	virtual void Deposit(int money);
};
#endif