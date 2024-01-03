#include <iostream>
using namespace std;

class Calculator
{
private:
	// double num1;
	// double num2; 함수 선언하면서 어차피 생김
	int AddCount;
	int DivCount;
	int MinCount;
	int MulCount;
public:
	void Init();
	double Add(double num1, double num2);
	double Div(double num1, double num2);
	double Min(double num1, double num2);
	double Mul(double num1, double num2);
	void ShowOpCount(); // 클래스 안에는 함수의 선언만 해주기 void는 기능만 하는 함수, double은 값을 반환하는 함수
}; //클래스, 구조체 선언 후 ; 세미콜론 찍어주기

void Calculator::Init() //변수 초기값 0으로 세팅
{
	AddCount=0;
	DivCount=0;
	MinCount=0;
	MulCount=0;
} 

double Calculator::Add(double num1, double num2) //매개변수 받을 때 값만 연산해서 반환해주면 되므로 같은 변수 위치에 값 저장될 필요 x
{
	AddCount++;
	return num1+num2;
}

double Calculator::Div(double num1, double num2)
{
	DivCount++;
	return num1/num2;
}

double Calculator::Min(double num1, double num2)
{
	MinCount++;
	return num1-num2;
}

double Calculator::Mul(double num1, double num2)
{
	MulCount++;
	return num1*num2;
}

void Calculator::ShowOpCount()
{
	cout<<"덧셈: "<<AddCount<<' ';
	cout<<"뺼셈: "<<MinCount<<' ';
	cout<<"곱셈: "<<MulCount<<' ';
	cout<<"나눗셈: "<<DivCount<<'\n';
}

int main()
{
	Calculator cal;
	cal.Init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<'\n';
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<'\n';
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<'\n';
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<'\n';
	cal.ShowOpCount();
	return 0;
}