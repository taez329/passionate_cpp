#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot()
	{
		cout<<"BANG!"<<endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff)
		: handcuffs(bcuff)
	{
		if(bnum>0)
			pistol=new Gun(bnum);
		else
			pistol=NULL; // 권총이 없음을 표현
	}
	Police(const Police &pol) //복사생성자
		: handcuffs(pol.handcuffs)
	{
		if(pol.pistol!=NULL)
			pistol=new Gun(*(pol.pistol)); //새로운 Police 객체 생성하며 pistol에 대한 정보 복사
		else
			pistol=NULL;
	}
	Police& operator=(const Police &ref) //대입연산자
	{
		handcuffs=ref.handcuffs;
		if(pistol!=NULL)
			delete pistol; //원래 있던 권총에 대한 정보 삭제
		if(ref.pistol!=NULL)
			pistol=new Gun(*(ref.pistol));
		else
			pistol=NULL;
		return *this;
	}
	void PutHandcuff()
	{
		cout<<"SNAP!"<<endl;
		handcuffs--;
	}
	void Shot()
	{
		if(pistol==NULL)
			cout<<"Hut BBANG!"<<endl;
		else
			pistol->Shot();
	}
	~Police()
	{
		if(pistol!=NULL)
			delete pistol;
	}
};

int main()
{
	Police pol1(5, 3);
	Police pol2(pol1);
	pol2.PutHandcuff();
	pol2.Shot();
	
	Police pol3(7, 4);
	pol1=pol3;
	pol1.PutHandcuff();
	pol1.Shot();
	return 0;
}