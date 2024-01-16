#include <iostream>
using namespace std;

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
	friend bool operator==(const Point &, const Point &);
	friend bool operator!=(const Point &, const Point &);
	//private 멤버변수로의 접근을 위한 friend 선언
	//전역함수를 통한 연산자 오버로딩에선 class내의 friend선언 필수이다
};

bool operator==(const Point &pos1, const Point &pos2) //true or false 반환이므로 bool로 반환형
{
	if (pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
		return true;
	else 
		return false;
}

bool operator!=(const Point &pos1, const Point &pos2)
{
	return !(pos1==pos2); //오버로딩된 opeartator==를 호출해서 표현
}
/*
Point operator!=(const Point pos1, const Point pos2)
{
	if (pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos)
		return false;
	else 
		return true;
}
*/

int main()
{
	Point pos1(10, 20);
	Point pos2(10, 20);
	Point pos3(5, 15);
	
	if (pos1==pos2)
		cout<<"same"<<endl;
	else
		cout<<"not same"<<endl;
	
	if (pos1!=pos3)
		cout<<"not same"<<endl;
	else
		cout<<"same"<<endl;
	return 0;
}