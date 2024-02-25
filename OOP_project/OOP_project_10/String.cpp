/*
	작성자: 박태정
	파일버전 0.1
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/

#include "String.h"

String::String()
{
	len=0;
	str=NULL;
}

String::String(const char* s)
{
	len=strlen(s)+1;
	str=new char[len];
	strcpy(str, s);
}

String::String(const String& s)
{
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
}

String::~String()
{
	if(str!=NULL)
		delete []str;
}

String& String::operator= (const String& s)
{
	if(str!=NULL)
		delete []str;
	len=s.len;
	str=new char[len];
	strcpy(str, s.str);
	return *this;
}

String& String::operator+= (const String& s)
{
	len+=(s.len-1);
	char* tempstr=new char[len];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	if(str!=NULL)
		delete []str;
	str=tempstr;
	return *this;
}

bool String::operator== (const String& s)
{
	return strcmp(str, s.str) ? false : true;
}

String String::operator+ (const String& s)
{
	char* tempstr=new char[len + s.len-1];
	strcpy(tempstr, str);
	strcat(tempstr, s.str);
	
	String temp(tempstr);
	delete []tempstr;
	return temp;
}

ostream& operator<< (ostream& os, const String& s)
{
	os<<s.str;
	return os;
}

istream& operator>> (istream& is, String& s)
{
	char str[100];
	is>>str;
	s=String(str);
	return is;
}