#include <iostream>
using namespace std;


void SwapPointer(int* &ref1, int* &ref2) //포인터 변수를 참조자 선언할 때는 *, * 붙여서
{
	//int* temp;
	//temp=ref1;
	int * temp=ref1;
	ref1=ref2;
	ref2=temp;
}

int main(void)
{
	int num1=5;
	int *ptr1=&num1;
	int num2=10;
	int *ptr2=&num2;
	
	SwapPointer(ptr1, ptr2);
	cout << *ptr1 <<" "<< *ptr2 << endl;
	return 0;
}