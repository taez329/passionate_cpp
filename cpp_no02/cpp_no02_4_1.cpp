#include <iostream>
#include <cstring> // c의 헤더를 사용할때는 뒤의 .h를 떼고 앞에 c를 붙인다.
using namespace std;

int main()
{
	char *str1="ABCD";
	char *str2="123456789";
	char str3[50];
	
	cout<<strlen(str1)<<endl;
	cout<<strlen(str2)<<endl;
	//cout<<strcat(str1, str2)<<endl; strcat은 뒤에 덧붙이는 기능만 있는 함수, 값이 출력되지 x
	//cout<<strcpy(str3, str2)<<endl; strcpy도 문자열 복사의 기능만 있는 함수, 값이 출력되지 x
	strcat(str3, str1);
	cout<<str3<<endl;
	
	strcat(str3, str2);
	cout<<str3<<endl;
	
	strcpy(str3, str1);
	cout<<str3<<endl;
	
	if (strcmp(str1, str2)==0)
		cout<<"같다"<<endl;
	else
		cout<<"다르다"<<endl;
	return 0;
}
