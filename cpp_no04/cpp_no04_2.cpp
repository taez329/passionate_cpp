#include <iostream>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	void Init(int x, int y)
	{
		xpos=x;
		ypos=y;
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
	void Init(int rad)
	{
		radius=rad;
	}
	// void pnt(int x, int y) 객체변수 pnt와 함수명 pnt가 겹치면 안됨 따라서 사용불가.
	void center(int x, int y)
	{
		pnt.Init(x, y);
	}
	/*void Init(int x, int y, int rad)
	{
		radius=rad;
		pnt.Init(x, y);
	} 로 간단히 표현 가능 */
	
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
	void Init(int x1, int y1, int rad1, int x2, int y2, int rad2)
	{
		InnerCircle.Init(rad1);
		InnerCircle.center(x1, y1);
		OutterCircle.Init(rad2);
		OutterCircle.center(x2, y2);
		//InnerCircle.Init(x1, y1, rad1); 으로 더 간단하게 표현 가능
	}
	void ShowRingInfo() const
	{
		/*
		cout<<"Inner Circle Info..."<<endl;
		cout<<"radius: "<<InnerCircle.radius<<endl;
		InnerCircle.pnt.ShowPointInfo();
		cout<<"Outter Circle Info..."<<endl;
		cout<<"radius: "<<OutterCircle.radius<<endl;
		OutterCircle.pnt.ShowPointInfo();
		*/
		//***********************************************
 		//radius와 pnt가 private이어서 여기서 호출이 불가하다!
		//하위 클래스의 함수는 호출이 가능, 따라서 하위 클래스의 함수에 private 선언된 변수와 관련된 기능을 넣고 그 함수를 호출하면된다.
		//즉, 함수를 한단계 더 거쳐서 private 된 변수를 사용해야한다.
		cout<<"Inner Circle Info..."<<endl;
		InnerCircle.ShowCircleInfo();
		cout<<"outter Circle Info..."<<endl;
		OutterCircle.ShowCircleInfo();
	}
};

int main()
{
	Ring ring;
	ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	return 0;
}