#include <iostream>
#include <string>
using namespace std;

string decimalToBinary8bit(int n)
{
	string bin;
	for (int i=0; i<8; i++)
	{
		bin=to_string(n%2)+bin;
		n=n/2;
	}
	return bin;
}

int main()
{
	string bin=decimalToBinary8bit(5);
	cout<<bin<<endl;
	return 0;
}
