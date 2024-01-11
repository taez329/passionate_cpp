#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo
{
private:
	char * name;
	int age;
public:
	MyFriendInfo(char * _name, int _age)
		: age(_age)
	{
		name=new char(strlen(_name)+1); // 동적할당 해줬으면 무조건 해제 해 줘 야 함
		strcpy(name, _name);
	}
	void ShowMyFriendInfo()
	{
		cout<<"이름: "<<name<<endl;
		cout<<"나이: "<<age<<endl;
	}
	~MyFriendInfo() // 소멸자 없어도 오류가 안남 그렇기에 더욱더 주의! 메모리 누수발생하지 않도록
	{
		delete []name;
		cout<<"~MyFriendInfo()"<<endl;
	}
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
	char * addr;
	char * phone;
public:
	MyFriendDetailInfo(char * _addr, char * _phone, char * _name, int _age)
		: MyFriendInfo(_name, _age) // 상위 클래스의 생성자를 통한 초기화
	{
		addr=new char(strlen(_addr)+1);
		strcpy(addr, _addr);
		phone=new char(strlen(_phone)+1);
		strcpy(phone, _phone);
	}
	void ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout<<"주소: "<<addr<<endl;
		cout<<"전화: "<<phone<<endl<<endl;
	}
	~MyFriendDetailInfo()
	{
		delete []addr;
		delete []phone;
		cout<<"~MyFriendDetailInfo()"<<endl;
	}
};

int main()
{
	MyFriendDetailInfo fnd("서울", "010-1234-5678", "홍길동", 23);
	fnd.ShowMyFriendDetailInfo();
	
	return 0;
}