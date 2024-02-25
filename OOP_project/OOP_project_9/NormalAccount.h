/*
	작성자: 박태정
	파일버전 0.8
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account // 보통예금계좌
{
private:
	int interest;
public:
	// NormalAccount(int id, char* _name, int money, int _interest);
	NormalAccount(int id, String _name, int money, int _interest);
	virtual void Deposit(int money);
};
#endif