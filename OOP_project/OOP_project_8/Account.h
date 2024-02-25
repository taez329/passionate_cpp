/*
	작성자: 박태정
	파일버전 0.8
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#ifndef __ACCOUNT_H__ 
#define __ACCOUNT_H__

class Account
{
private:
	char* name;
	int account_id;
	int balance;
public:
	Account(int id, char * _name, int money); //함수의 선언만 해놓는다.
	Account(const Account &ref);
	Account& operator=(const Account &ref); // 추가된 문장, 대입연산자도 깊은 복사가 진행되도록
	
	int GetId() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowInfo() const;
	~Account();
};
#endif