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