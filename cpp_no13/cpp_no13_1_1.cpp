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
};

template <typename T>
void SwapData(T& a, T& b) // 참조자로 받아야 변경된 값이 적용됨
{
	T temp=a;
	a=b;
	b=temp;
}

int main()
{
	Point pos1(5, 2);
	Point pos2(3, 8);
	SwapData(pos1, pos2);
	pos1.ShowPosition();
	pos2.ShowPosition();
}