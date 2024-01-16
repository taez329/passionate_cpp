#include <iostream>
using namespace std;
//멤버함수에 의한 연산자 오버로딩에서는 예를들어 '+' 를 나타낸다면
//pos1+pos2가 pos1.operator+(pos2);라는 함수 호출로 바뀜
class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition() const
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
	Point& operator+=(const Point &ref) //반환형을 참조형으로 설정하고
	{
		xpos+=ref.xpos;
		ypos+=ref.ypos;
		return *this; //자기 자신을 반환하기 위해 this 포인터로 반환
	}
	Point& operator-=(const Point &ref) //반환형을 참조형으로 설정하고
	{
		xpos-=ref.xpos;
		ypos-=ref.ypos;
		return *this; //자기 자신을 반환하기 위해 this 포인터로 반환
	}
	//멤버함수에 의한 연산자 오버로딩
};

int main()
{
	Point pos1(10, 20);
	Point pos2(7, 17);
	Point pos3(4, 9);
	
	(pos1+=pos2).ShowPosition(); //반환형이 참조형이라 함수호출 가능
	(pos2-=pos3).ShowPosition(); //반환형이 참조형이라 함수호출 가능
	return 0;
}