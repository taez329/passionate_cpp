/*
	작성자: 박태정
	파일버전 0.7
	
	이렇게 파일 별로 버전을 관리해야 변경사항에 대한 확인이 용이하다.
	각각의 클래스마다 선언은 .h 파일에 정의는 .cpp 파일에 저장하는 것이 좋다.
	프로그램 관리에 용이, 클래스의 구성이 한눈에 들어오기 때문에 프로그램의 내용을 파악하기도 수월해진다.
*/
//main 함수가 있는 소스파일
//include < >와 " "의 차이 : < >은  기본적으로 주어져 있는 헤더파일을 인클루드 할 때, " "은 개발자가 직접 만든 헤더파일을 인클루드 할 때

#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main()
{
	AccountHandler manager;
	int choice;
	
	while(1)
	{
		manager.ShowMenu();
		cout<<"선택: ";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				manager.MakeAccount();
				break;
			case INPUT:
				manager.InputMoney();
				break;
			case OUTPUT:
				manager.OutputMoney();
				break;
			case PRINT:
				manager.PrintInfo();
				break;
			case EXIT:	
				return 0;
			default:
				cout<<"알맞은 입력이 필요합니다."<<endl; //잘못된 입력이 있을때 처리
		}
	}
}