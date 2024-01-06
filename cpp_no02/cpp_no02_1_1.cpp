#include <iostream>
using namespace std;

/*int ref_plus(int &ref1)
{
	ref1++;
	return ref1;
}
증가, 부호변환의 기능만 해주면 됨, 값을 원하는 함수가 아님 return 안 시켜도됨
*/

void ref_plus(int &ref1)
{
	ref1++;
}
void ref_changesign(int &ref2)
{
	ref2 *= -1;
}

int main()
{
	int num1 = 10; 
	int num2 = 5;
	
	//num1 = ref_plus(num1); 
	//num2 = ref_changesign(num2); 이미 함수를 통과하면서 값이 바뀌므로 저장할 필요 x
	ref_plus(num1);
	ref_changesign(num2);
	cout << "num1: "<< num1 << endl;
	cout << "num2: "<< num2 << endl;
	return 0;

}