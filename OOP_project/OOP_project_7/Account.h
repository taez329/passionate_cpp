/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#ifndef __ACCOUNT_H__ 
// 다수의 소수코드에서 include된 헤더파일이 여러번 포함되는 것을 막기위해 #ifndef, #define, #endif의 구조
// '__ACCOUNT_H__가 정의되지 않았으면' 라는 뜻 (if not define)
// 직접 만드는 헤더파일은 #ifndef, #define, #endif의 구조를 가져야 한다.
// __ACCOUNT_H__ 와 같은 것을 헤더 구분자라 하는데 이의 명명규칙이 있다.
// 모든 알파벳은 대문자로 바꾸고 앞과 뒤에는 __를 추가, .은 _로 바꾼다.
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
	
	int GetId() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowInfo() const;
	~Account();
};
#endif