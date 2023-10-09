#include <iostream>
#include <string>
#include <cmath>
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
		return "Overflow";
	
	string s_mgt = decimalToBinary8bit(abs(decimal));
	if (decimal < 0)
	{
		s_mgt[0] = '1';
	}
	return s_mgt;
}

string complement1s(int n)
{
	if (n>=-127 && n<=127)
	{
		if (n>=0) return decimalToBinary8bit(n);
		else return decimalToBinary8bit(abs(n) ^ 255);
	}
	else
	{
		return "Overflow";
	}
}

string complement2s(int n)
{
	if (n>=-128 && n<=127)
	{
		if (n>=0) return decimalToBinary8bit(n);
		else
		{
			string bin=decimalToBinary8bit(abs(n) ^ 255);
			int i;
			for (i=bin.size()-1; bin[i] !='0' && i>0 ; i--)
				bin[i]='0';
			bin[i] = '1';
			return bin;
		}
	}
	else
	{
		return "Overflow";
	}
	
}

int main()
{
	int decimal;
	cout << "Input: ";
	cin >> decimal;
	
	cout << "Output a: " << sign_magnitude(decimal) << endl;
	cout << "Output b: " << complement1s(decimal) << endl;
	cout << "Output c: " << complement2s(decimal) << endl;
	return 0;
}
