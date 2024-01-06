#include <iostream>
using namespace std;

typedef struct __Point
{
	int xpos;
	int ypos;	
} Point; //2차원 평면상에서의 좌표를 표현할 수 있는 구조체

Point& PntAdder(const Point &p1, const Point &p2) //두 점의 합을 계산하는 함수, 덧셈결과는 함수의 반환을 통해
{
	Point * pptr=new Point;
	pptr->xpos=p1.xpos+p2.xpos;
	pptr->ypos=p1.ypos+p2.ypos;
	
	return *pptr;
}

int main()
{
	Point *pptr1=new Point;
	pptr1 ->xpos=5;
	pptr1 ->ypos=7;
	
	Point *pptr2=new Point;
	pptr2 ->xpos=8;
	pptr2 ->ypos=2;
	
	Point &pref=PntAdder(*pptr1, *pptr2);
	cout<<"["<<pref.xpos<<", "<<pref.ypos<<"]"<<endl;
	
	delete pptr1;
	delete pptr2;
	delete &pref;
	return 0;

}