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
	friend Point operator-(const Point &pos1, const Point &pos2); 
	//private 멤버로의 접근허용
	//Point 클래스는 -연산에 대해 연산자 오버로딩이 되어있구나! 라는 것을 알 수 있다.
};

Point operator-(const Point &pos1, const Point &pos2) //새로운 객체에 연산값을 넣는 것이기에 const
{
	Point pos(pos1.xpos-pos2.xpos, pos1.ypos-pos2.ypos);
	return pos;
}
//전역함수에 의한 연산자 오버로딩

int main()
{
	Point pos1(10, 20);
	Point pos2(3, 4);
	Point pos3=pos1-pos2;
	
	pos1.ShowPosition();
	pos2.ShowPosition();
	pos3.ShowPosition();
	return 0;
}

