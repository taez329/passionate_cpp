/*
	작성자: 박태정
	파일버전 0.9
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#ifndef __ACCOUNT_H__ 
#define __ACCOUNT_H__

#include "String.h" // 여기에 복사생성자와 대입연산자에 썼던 깊은 복사를 구현해서 다른 곳에서 복사생성자, 대입연산자 정의가 필요 x
// "적절한 클래스의 등장은 다른 클래스의 정의를 간결하게 해준다."

class Account
{
private:
	String name; // char* name;을 대체
	int account_id;
	int balance;
public:
	Account(int id, String _name, int money); //_name을 String형으로 받기
	// Account(int id, char * _name, int money);
	// String에 깊은 복사를 넣으면서 복사생성자, 대입연산자를 따로 쓸 필요x
	// Account(const Account &ref);
	// Account& operator=(const Account &ref);
	
	int GetId() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowInfo() const;
	// ~Account();
};
#endif