#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	/* void Init(int x, int y)
	{
		xpos=x;
		ypos=y;
	}*/
	Point (int x, int y)
		: xpos(x), ypos(y) //멤버 이니셜라이저로 Init 함수 대신하기, 이때 ;(세미콜론)은 쓰지 않는다.
	{
	}
	void ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<'\n';
	}
};

class Circle
{
private:
	Point pnt;
	int radius;
public:
	/* void Init(int x, int y, int rad)
	{
		radius=rad;
		pnt.Init(x, y);
	} */
	Circle (int x, int y, int rad)
		: pnt(x, y)
	{
		radius=rad;
	}
	
	void ShowCircleInfo() const
	{
		cout<<"radius: "<<radius<<endl;
		pnt.ShowPointInfo();
	}
};

class Ring
{
private:
	Circle InnerCircle;
	Circle OutterCircle;
public:
	/*void Init(int x1, int y1, int rad1, int x2, int y2, int rad2) //변수 사용시 어디에 쓰는지 알수 있게 이름 짓는 연습하기!
	{
		InnerCircle.Init(x1, y1, rad1);
		OutterCircle.Init(x2, y2, rad2);
	}
	*/
	Ring (int x1, int y1, int rad1, int x2, int y2, int rad2) //변수 사용시 어디에 쓰는지 알수 있게 이름 짓는 연습하기!
		:InnerCircle(x1, y1, rad1), OutterCircle(x2, y2, rad2)
	{
	}
	void ShowRingInfo() const
	{
		cout<<"Inner Circle Info..."<<endl;
		InnerCircle.ShowCircleInfo();
		cout<<"outter Circle Info..."<<endl;
		OutterCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring(1, 1, 4, 2, 2, 9); //생성자로 이니셜라이징 하기위한 멤버변수 선언하며 값 입력하기
	ring.ShowRingInfo();
	return 0;
}


