#include <iostream>
using namespace std;

struct Point
{
	int xpos;
	int ypos;
	
	void MovePos(int x, int y) // 점의 좌표이동
	{
		xpos=xpos+x;
		ypos=ypos+y; //구조체 안의 함수이기 때문에 구조체 이름.변수 할 필요없이 바로 변수 사용
	}
	
	void AddPoint(const Point &pos) // 점의 좌표증가
	{
		xpos=xpos+pos.xpos;
		ypos=ypos+pos.ypos; //&pos 참조자로 매개변수를 받으므로 구조체 이름이 pos가 되는 것 따라서 pos.멤버변수로 불러오면 된다.
	}
	
	void ShowPosition() // 현재 x, y 좌표정보 출력
	{
		cout<<"("<<xpos<<", "<<ypos<<")"<<'\n';
	}
	
};

int main()
{
	Point pos1={12, 4};
	Point pos2={20, 30};
	
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();
	
	pos1.AddPoint(pos2);
	pos1.ShowPosition();
	return 0;
	
}