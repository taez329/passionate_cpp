#include <iostream>
using namespace std;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numofApples;
	int myMoney;
	
public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE=price;
		numofApples=num;
		myMoney=money;
	}
	int SaleApples(int money)
	{
		if (money<0)
		{
			cout<<"금액이 잘못되어 판매하지못합니다.";
			return 0;
		}
		//money가 조건에 맞지 않을 때 출력문
		int num=money/APPLE_PRICE;
		numofApples-=num;
		myMoney+=money;
		return num;
	}
	void ShowSalesResult() const //함수의 안정성을 위해
	{
		cout<<"남은 사과: "<<numofApples<<'\n';
		cout<<"판매 수익: "<<myMoney<<'\n'<<'\n';

	}
};

class FruitBuyer
{
private:		
	int myMoney;
	int numofApples;
	
public:
	void InitMembers(int money)
	{
		myMoney=money;
		numofApples=0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		if (money<0)
		{
			cout<<"금액이 잘못되어 판매하지 못합니다.";
		}
	
		numofApples+=seller.SaleApples(money);
		myMoney-=money;
	}
	void ShowBuyResult() const
	{
		cout<<"현재 잔액: "<<myMoney<<'\n';
		cout<<"사과 개수: "<<numofApples<<'\n'<<'\n';
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, -1000);
	
	cout<<"과일 판매자의 현황"<<'\n';
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<'\n';
	buyer.ShowBuyResult();
	return 0;
}