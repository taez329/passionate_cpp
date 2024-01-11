#include <iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car(int _gasolineGauge) : gasolineGauge(_gasolineGauge)
	{ }
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car // CAr이 상위 클래스 HybridCar가 하위 클래스
{
private:
	int electricGauge;
public:
	HybridCar(int _electricGauge, int _gasolineGauge)
		: Car(_gasolineGauge), electricGauge(_electricGauge)
	{ }
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int _waterGauge, int _electricGauge, int _gasolineGauge)
		: HybridCar(_electricGauge, _gasolineGauge), waterGauge(_waterGauge) 
	// 상위 클래스의 생성자를 호출하면서 초기화
	// 해당 클래스는 멤버에 바로 초기화
	{ }
	void ShowCurrentGauge()
	{
		cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
		cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
		cout<<"잔여 워터량: "<<waterGauge<<endl;
	}
};

int main()
{
	HybridWaterCar HWC(10, 20, 30);
	HWC.ShowCurrentGauge();
	
	return 0;
}
