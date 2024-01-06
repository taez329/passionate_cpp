#include <iostream>
using namespace std;

int main()
{
	int n;
	int i = 0;
	
	cin >> n;
	
	while (i++ < 9)
		cout << n <<"*" << i<< "="<< n * i << endl;
	
	return 0;
}