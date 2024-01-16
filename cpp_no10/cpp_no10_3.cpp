#include <iostream> //필수
using namespace std;

class Point
{
private:
	int xpos, ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y)
	{ }
	void ShowPosition()
	{
		cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
	}
	friend ostream& operator<<(ostream&, const Point&);
	friend istream& operator>>(istream&, Point&);
};

ostream& operator<<(ostream& os, const Point &pos)
{
	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
	return os;
}
//결과 확인을 위한 << 연산자 오버로딩

istream& operator>>(istream& is, Point &ref) //값 변경하기에 const 선언 x
//cin이 istream 클래스안에 있음
//istream은 <iostream>헤더파일에 있음	
{
	is>>ref.xpos>>ref.ypos;
	return is; //?? 무슨 의미일까
}

int main()
{
	Point pos1;
	cout<<"x, y 좌표 순으로 입력: ";
	cin>>pos1;
	cout<<pos1;
	
	Point pos2;
	cout<<"x, y 좌표 순으로 입력: ";
	cin>>pos2;
	cout<<pos2;
}