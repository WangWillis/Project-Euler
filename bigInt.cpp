#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class bigInteger
{
public:
	string numb;
	short number[100000];
	void print();
	void convert(short*);
	int length();
	bigInteger add(bigInteger, bigInteger);
	bigInteger subtract(short*, short*, short*);
	bigInteger multiply(short*, short*, short*);
	bigInteger divide(short*, short*, short*);
};

void bigInteger::print()
{
	convert(number);
	for(int i = 0; i < numb.size(); i++)
	{
		cout << number[i];
	}
}

int bigInteger::length()
{
	return numb.size();
}

void bigInteger::convert(short number[])
{
	for(int i = 0; i < numb.size(); i++)
	{
		number[i] = (short)numb[i] - 48;
	}
}

bigInteger bigInteger::add(bigInteger number1, bigInteger number2)
{
	
}

int main()
{
	bigInteger test;
	test.numb = "12345678911121314151617181920212223242252627282930";
	test.print();
	return 0;
}