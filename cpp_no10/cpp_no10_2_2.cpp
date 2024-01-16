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
	friend Point operator~ (const Point &); //Point 클래스는 ~단항 연산자에 대해 연산자 오버로딩 되었구나!

Point operator~ (const Point &ref)
{
	//Point pos(ypos, xpos); 이게 뭐야 태정아... 클래스 외부니까 ref.xpos, ref.ypos로 해야지
	Point pos(ref.ypos, ref.xpos);
	return pos;
	//반환을 이런 식으로 해서 참조자로 받은 객체의 값 변화 안 시키고 연산자 오버로딩 하기
}

int main()
{
	Point pos1(10, 20);
	
	Point pos3 = ~pos1;
	pos1.ShowPosition();
	pos3.ShowPosition();
	return 0;
}