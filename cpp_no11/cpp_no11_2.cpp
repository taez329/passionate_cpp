#include <iostream>
#include <cstring>
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) { }
	friend ostream& operator<<(ostream& os, const Point* pos); //friend 선언 함수도 바꾸고
};
/*
ostream& operator<<(ostream& os, const Point& pos) 참조자로 받던 것을 20행에서처럼 포인터로 받음
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}
*/
ostream& operator<<(ostream& os, const Point* pos) //포인터로 받음
{
	/*
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl; 이렇게 쓰면 안된다.
	< .와 ->의 차이 >
	.은 클래스 멤버에 대한 직접접근
	->은 포인터를 통한 멤버 간접접근 a->b는 (*a).b와 동일하다
	*/
	os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
	return os;
}

typedef Point * POINT_PTR;

class BoundCheckPointArray
{
private:
	POINT_PTR * arr;
	int arrlen;

	BoundCheckPointArray(const BoundCheckPointArray& arr) { }
	BoundCheckPointArray& operator=(const BoundCheckPointArray& arr) { }
	
public:
	BoundCheckPointArray(int len) : arrlen(len)
	{
		arr=new POINT_PTR[len];
	}
	POINT_PTR& operator[] (int idx)
	{
		if(idx<0||idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[] (int idx) const
	{
		if(idx<0||idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrLen() const { return arrlen; }
	~BoundCheckPointArray() { delete []arr; }
};

int main()
{
	BoundCheckPointArray arr(3);
	arr[0]=new Point(1, 2);
	arr[1]=new Point(3, 4);
	arr[2]=new Point(5, 6);
	
	for (int i=0; i<arr.GetArrLen(); i++)
		cout<<arr[i]; //*(arr[i])였던 것을 이렇게 바꿈 이러면 주소값이 가니까 포인터로 받으면 됨
	
	delete arr[0];
	delete arr[1];
	delete arr[2];
}