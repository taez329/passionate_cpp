#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
	char* arr;
	int len;
public:
	String() 
	//문자열을 입력받을 목적으로 객체를 생성할 때 쓰는 생성자
	//NULL과 len=0으로 초기화
	{
		arr=NULL;
		len=0;
	}
	String(char* s) //생성자
	{
		len=strlen(s)+1;
		arr=new char[len];
		strcpy(arr, s);
	}
	String& operator= (const String &str) //대입연산자, 이때 깊은 복사가 되도록 함
	{
		if (arr!=NULL) //arr가 NULL일 수도 있기에 검사후 delete
			delete []arr;
		len=str.len;
		arr=new char[len];
		strcpy(arr, str.arr);
		return *this;
	}
	String(const String &ref) //복사 생성자, 이때 깊은 복사가 되도록 함
	{
		arr=new char[strlen(ref.arr)+1];
		strcpy(arr, ref.arr);
	}
	~String() //소멸자
	{
		if (arr!=NULL) //arr가 NULL일 수도 있기에 검사후 delete
			delete[] arr;
	}
	String operator+(const String &s);
	String& operator+=(const String &s);
	friend bool operator==(const String &s1, const String &s2); //선언 후 클래스 외부에서 연산자 오버로딩 하겠다. 멤버함수에 의한 연산자 오버로딩
	
	friend ostream& operator<< (ostream &os, const String &s);
	friend istream& operator>> (istream &is, String &s); //전역함수에 의한 <<, >>연산자 오버로딩
};

String String::operator+(const String &s) //멤버함수지만 class밖에서 정의
{
	char* temp=new char[len+s.len-1]; //문자열이 두개면 끝에 있는 NULL이 두 개니까 하나 제거를 위해 -1
	strcpy(temp, arr);
	strcat(temp, s.arr); //temp라는 문자열에 붙여놓고 얘를 이용해서 String 객체를 만듦
	
	String str(temp); //String str=temp; 와 동일 String 객체로 반환하기 위해서
	delete []temp; //이제 사용하지 않기에 delete
 	return str;
}

String& String::operator+=(const String &s)
{
	len+=s.len-1;
	char* temp=new char[len];
	strcpy(temp, arr);
	strcat(temp, s.arr);
	
	if (arr!=NULL) //arr가 NULL일 수도 있기에 검사후 delete
		delete []arr;
	arr=temp;
	return *this;
}
/*
다음과 같이 +=연산자 오버로딩 가능
단 이때 덧셈의 과정에서 추가 객체가 생성된다는 단점이 있음
String& String::operator+=(const String &s)
{
	*this=*this+s;
	return *this;
}
*/

bool operator==(const String &s1, const String &s2)
{
	if (s1.arr==s2.arr)
		return true;
	else
		return false;
	//strcmp 함수를 통해 간단히 표현가능
	//return strcmp(arr, s.arr) ? false : true;
	//이 코드를 쓸 경우 friend 선언 필요 x 매개변수도 (const String &s)로 하나만 받으면 됨
}

ostream& operator<< (ostream& os, const String &s)
{
	os<<s.arr;
	return os;
}

istream& operator>> (istream& is, String &s)
{
	char str[100];
	is>>str;
	s=String(str);
	return is;
}

int main()
{
	String str1="I like ";
	String str2="string class";
	String str3=str1+str2;
	
	cout<<str1<<endl;
	cout<<str2<<endl;
	cout<<str3<<endl;
	
	str1+=str2;
	if(str1==str3)
		cout<<"동일 문자열"<<endl;
	else
		cout<<"다른 문자열"<<endl;
	
	String str4;
	cout<<"문자열 입력: "<<endl;
	cin>>str4;
	cout<<"입력한 문자열: "<<str4<<endl;
	return 0;
}