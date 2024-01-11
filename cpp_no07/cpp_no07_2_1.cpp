#include <iostream>
using namespace std;

class Rectangle
{
private:
	int x;
	int y;
public:
	Rectangle(int _x, int _y) : x(_x), y(_y)
	{ }
	void ShowAreaInfo()
	{
		cout<<"면적: "<<x*y<<endl;
	} //sqr.ShowAreInfo로 호출해도 기초 클래스의 public이기 때문에 호출가능
};

class Square : public Rectangle 
{
private:
	int side;
public:
	Square(int _side) : Rectangle(_side, _side); // 상위클래스가 하위 클래스보다 큰 범위임을 이용하기
	{ }
};

int main()
{
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo(); //sqr.ShowAreInfo로 호출해도 기초 클래스의 public이기 때문에 호출가능
	 
	return 0;
}