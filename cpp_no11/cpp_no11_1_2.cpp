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
	Book(char* __title, char* __isbn, int __price)
		: price(__price)
	{
		title=new char[strlen(__title)+1];
		strcpy(title, __title);
		isbn=new char[strlen(__isbn)+1];
		strcpy(isbn, __isbn);
	}
	Book(const Book &ref) // 복사생성자
		: price(ref.price)
	{
		title=new char[strlen(ref.title)+1];
		strcpy(title, ref.title);
		isbn=new char[strlen(ref.isbn)+1];
		strcpy(isbn, ref.isbn);
	}
	Book& operator=(const Book &ref) // 대입연산자
	{
		delete []title;
		delete []isbn;
		
		title=new char[strlen(ref.title)+1];
		strcpy(title, ref.title);
		isbn=new char[strlen(ref.isbn)+1];
		strcpy(isbn, ref.isbn);
		
		price=ref.price;
		return *this;
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
		:Book(_title, _isbn, _price)
	{
		DRMKey=new char[strlen(_DRMKey)+1];
		strcpy(DRMKey, _DRMKey);
	}
	EBook(const EBook &ref) : Book(ref) // 복사생성자, 상속하는 클래스에 넘겨서 복사생성자가 실행되게함
	{
		DRMKey=new char[strlen(ref.DRMKey)+1];
		strcpy(DRMKey, ref.DRMKey);
	}
	EBook& operator=(const EBook &ref) // 대입연산자
	{
		Book::operator=(ref); // 클래스의 상속을 이용해 간단히 표현
		delete []DRMKey;
		
		DRMKey=new char[strlen(ref.DRMKey)+1];
		strcpy(DRMKey, ref.DRMKey);
		
		return *this;
	}
	void ShowEBookInfo()
	{
		ShowBookInfo();
		cout<<"인증키: "<<DRMKey<<endl;
	}
	~EBook()
	{
		delete []DRMKey;
	}
};

int main()
{
	EBook ebook1("좋은 c++", "555-12345-890-1", 17000, "fdx9woi8kiw");
	EBook ebook2(ebook1);
	ebook2.ShowEBookInfo();
	cout<<endl;
	
	EBook ebook3("dumy", "dumy", 0, "dumy");
	ebook3=ebook2;
	ebook3.ShowEBookInfo();
	return 0;
}