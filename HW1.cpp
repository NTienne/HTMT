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


string complement1s(int n)
{
	if (n>=-127 && n<=127)
	{
		if (n>=0) return decimalToBinary8bit(n);
		else return decimalToBinary8bit(abs(n) ^ 255);
	}
	else
	{
		cout<<"Overflow"<<endl;
		return "";
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
		cout<<"Overflow"<<endl;
		return "";
	}
	
}

int main()
{
	string bin=complement1s(-128);
	cout<<bin<<endl;
	bin=complement2s(-128);
	cout<<bin<<endl;
	return 0;
}
