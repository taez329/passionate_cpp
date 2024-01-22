/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/
//기본 세팅 헤더파일
#ifndef __BANKING_COMMON_H__
#define __BANKING_COMMON_H__

#include <iostream>
#include <cstring>

#define NAME_LEN 20
using namespace std;

enum {MAKE=1, INPUT, OUTPUT, PRINT, EXIT}; //프로그램 사용자의 선택메뉴

enum {CREDIT_A=7, CREDIT_B=4, CREDIT_C=1}; //신용등급

//enum을 쓸 경우 이게 뭘 뜻하는 것인지 주석을 달아주는 것이 좋다.
#endif

