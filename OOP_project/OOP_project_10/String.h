/*
	작성자: 박태정
	파일버전 0.1
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#ifndef __STRING_H__
#define __STRING_H__

#include "BankingCommonDecl.h"

class String
{
private:
	int len;
	char * str;
public:
	String(); // NULL을 넣는 생성자
	String(const char *s); // 생성자
	String(const String& s); // 복사생성자
	~String(); // 소멸자
	String& operator= (const String& s); // 대입연산자
	String& operator+= (const String& s);
	bool operator== (const String& s);
	String operator+ (const String& s);
	
	friend ostream& operator<< (ostream& os, const String& s);
	friend istream& operator>> (istream& is, String& s);
};
#endif