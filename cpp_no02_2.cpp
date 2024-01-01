#include <iostream>
using namespace std;

int main()
{
	const int num=12;
	const int *ptr=&num;
	const int *(&ref)=ptr; //상수화된 변수에 대해 포인터로 가리키거나 참조자 선언을 할 때는 const를 붙여주어야한다.
	
	cout<<*ptr<<endl;
	//cout<<ref<<endl; 포인터에 대한 참조자 선언시 똑같은 포인터기에 값 출력을 위해선 * 붙여야함
	cout<<*ref<<endl;
 	return 0;
	
}