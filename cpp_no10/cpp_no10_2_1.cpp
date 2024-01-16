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
	Point operator- ()
	{
		Point pos(-xpos, -ypos);
		return pos;
	} 
	//반환값에서만 부호가 바뀌게
	//기존은 변화 X
};

int main()
{
	Point pos1(10, 20);
	
	Point pos3 = -pos1;
	pos1.ShowPosition();
	pos3.ShowPosition();
	return 0;
}