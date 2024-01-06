#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand(time(NULL)); //srand를 이용해 seed에 따라 rand 함수가 무작위 값을 갖도록, 이때 시드는 time으로 설정
	for (int i=1; i<6; i++)
		cout<<"Random Number "<<i<<":"<<rand()%100<<endl; //범위가 100까지 이므로 %100 사용
	
	return 0;
}