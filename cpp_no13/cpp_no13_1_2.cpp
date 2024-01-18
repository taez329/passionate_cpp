#include <iostream>
using namespace std;

template <typename T> //템플릿 정의방법
T SumArray(T arr[], int len) //특정하고 싶지 않은 반환형, 자료형에 typename으로 선언한 T를 작성
{
	T sum=0;
	for(int i=0; i<len; i++)
		sum+=arr[i];
	return sum;
}

int main()
{
	int arr1[]={10, 20, 30}; //배열 초기화 방법 알아서 크기는 3으로 할당됨
	double arr2[]={10.5, 20.2, 30.7};
	cout<<SumArray(arr1, sizeof(arr1)/sizeof(int))<<endl;
	cout<<SumArray(arr2, sizeof(arr2)/sizeof(double))<<endl;
}