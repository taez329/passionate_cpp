/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/
//컨트롤 클래스 헤더파일
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler // 컨트롤 클래스
{
private:
	Account * accArr[100];
	int accNum;
public:
	AccountHandler(); // 헤더파일에는 함수의 선언만
	void ShowMenu() const;
	void MakeAccount();
	void InputMoney();
	void OutputMoney();
	void PrintInfo() const;
	~AccountHandler();
protected:
	void MakeNormalAccount();
	void MakeHighCreditAccount();
};
#endif