#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char string[30];
public:
	void SetString(char *s);
	void ShowString();
};

void Printer::SetString(char *s)
{
	strcpy(string, s);
	/*
	int num=0;
	int i=0;
	while (s[i]!='\0')
	{
		num++;
		i++;
	}
	char * str = new char[num];
	while (*s!='\0')
	{
		*string = *s;
		string++;
		s++;
	}
	*string='\0';
	*/
	//아 이거 무조건 성공시킨다 cstring 헤더 안 쓰고 풀기
}

void Printer::ShowString()
{
	cout<<string<<'\n';
}

int main()
{
	Printer pnt;
	pnt.SetString("Hello World!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
	return 0;
}