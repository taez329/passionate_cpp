#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
	char * title;
	char * isbn;
	int price;
public:
	Book(char* __title, char* __isbn, int __price) //장꾸형이 알려준 꿀팁 표기법 char* A 헷갈리지 않도록
	//매개변수로 멤버변수 초기화 시키는 과정에서 이름짓기에 골치가 아프다면 this포인터를 이용하자!
	//멤버변수는 this->title 이런식으로 표시 멤버변수는 title 이런 식으로 표시
		: price(__price)
	{
		title=new char[strlen(__title)+1];
		strcpy(title, __title);
		isbn=new char[strlen(__isbn)+1];
		strcpy(isbn, __isbn);
		//this->title=new char(strlen(title)+1); 이런 식으로 this 포인터 이용 가능
	}
	void ShowBookInfo()
	{
		cout<<"제목: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"가격: "<<price<<endl;
	}
	~Book()
	{
		delete []title;
		delete []isbn;
	}
};

class EBook : public Book
{
private:
	char * DRMKey;
public:
	EBook(char* _title, char* _isbn, int _price, char* _DRMKey)
		:Book(_title, _isbn, _price) //상위 클래스의 생성자를 호출해서 멤버변수 초기화
	{
		DRMKey=new char[strlen(_DRMKey)+1];
		strcpy(DRMKey, _DRMKey);
	}
	
	void ShowEBookInfo()
	{
		ShowBookInfo(); //상위 클래스에 있는 함수 쓰기
		cout<<"인증키: "<<DRMKey<<endl;
	}
	~EBook()
	{
		delete []DRMKey;
	}
};

int main()
{
	Book book("좋은 c++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	EBook ebook("좋은 c++", "555-12345-890-1", 10000, "fdx9woi8kiw");
	ebook.ShowEBookInfo();
	
	return 0;
}