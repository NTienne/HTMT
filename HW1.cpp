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

string sign_magnitude(int decimal)
{
	if (abs(decimal) > 127)
		return "overflow";
	
	string s_mgt = decimalToBinary8bit(abs(decimal));
	if (decimal < 0)
	{
		s_mgt[0] = '1';
	}
	return s_mgt;
}

int main()
{
	int decimal;
	cout << "Input: ";
	cin >> decimal;
	
	cout <<  "Output a: " << sign_magnitude(decimal) << endl;
	return 0;
}
