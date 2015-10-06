#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//BAD nth Fibonacci number
/*int nthFib(int n, int k, int p)
{
	if(n > 0)
	{
		return nthFib(n - 1, p, k + p);
	}
	return p;
}*/

//Good nthFib
int nthFib(int n)
{
	if(n <= 1)
	{
		return 1;
	}
	else 
	{
		return nthFib(n-1) + nthFib(n-2);
	}
}

int BinarySearch(int array[], int toFind, int high, int low)
{
	if(array[(high + low)/2] == toFind)
	{
		return array[(high + low)/2];
	}
	else if(array[(high + low)/2] > toFind)
	{
		return BinarySearch(array, toFind, (high + low)/2 - 1, low);
	}
	else if(array[(high + low)/2] < toFind)
	{
		return BinarySearch(array, toFind, high, (high + low)/2 + 1)
	}
}

//nth prime number (up till 290 though :()
/*int nthPrime(int n, int k = 3, int j = 3)
{
	if(n == 1 && k == 3)
	{
		return 2;
	}
	if(n == 2 && k == 3)
	{
		return 3;
	}
	if(n > 2 && k == 3)
	{
		return nthPrime(n - 1, k + 2);
	}
	if(((k/2) + 1 == j) || ((k/2) == j) && n != 1)
	{
		return nthPrime(n - 1, k + 2);
	}
	else if(k % j != 0 && n != 1)
	{
		return nthPrime(n, k, j + 2);
	}
	else if(k % j == 0 && n != 1)
	{
		return nthPrime(n, k + 2);
	}
	else if(n == 1)
	{
		return k - 2;
	}
}*/

//creates a lit of the first n prime numbers
int primeList(int prime[], int n)
{
	int j = 3, k = 1;
	prime[0] = 2;
	for(int i = 0; i < n/2; i++)
	{
		if(j % prime[i] == 0)
		{
			j += 2;
			i = 0;
		}
		else if(j % prime[i] != 0 && i == k - 1)
		{
			prime[k] = j;
			k++;
		}
	}
	return prime[n - 1];
}

//Gives the Nth Trianle number
int nthTriangleNumber(int n)
{
	return (double)n * (n + 1)/2;
}

//Gives the number of Divisors a number has
int numDivisors(int x)
{
	int y = 0;
	for(int i = 1; i < (int)sqrt(x); i++)
	{
		if(x % i == 0)
		{
			y += 2;
		}
	}
	if(x % (int)sqrt(x) == 0)
	{
		y += 1;
	}
	return y;
}

//gives the length of a number
int lengthOfInt(int x)
{
	int length = 0;
	do
	{
		x /= 10;
		length ++;
	}while(x != 0);
	return length;
}

//flips a number
int flipNum(int x)
{
	int z = lengthOfInt(x);
	int total = 0;
	for(int i = 1; i <= z; i++)
	{
		total += (x % 10) * round(pow(10, z - i));
		x /= 10;
	}
	return total;
}

//tests if a number is a palindrome
bool isPalindrome(int x)
{
	if(x == flipNum(x))
		return true;
	return false;
}

//gives the factorial of a number
long long factorial(int n)
{
	if(n == 1)
		return 1;
	return n * factorial(n - 1);
}

//The number of terms in a Collatz Sequence
int collatzSequenceChain(long long x, int y)
{
	if(x % 2 == 0)
	{
		return collatzSequenceChain(x/2, y + 1);
	}
	if(x == 1)
	{
		return y;
	}
	if(x % 2 == 1)
	{
		return collatzSequenceChain(3*x + 1, y + 1);
	}
}

//Sum of digits
int sumOfDigits(int n)
{
	int total = 0;
	for(int x = 1; x <= lengthOfInt(n); x++)
	{
		cout << lengthOfInt(n) << endl;
		total += n % 10;
		n /= 10;
	}
	return total;
}

int divSum(int x)
{
	int total = 0;
	for(int i = 1; i <= sqrt(x); i++)
	{
		if(i == 1 && i < x)
		{
			total ++;
		}
		else if(i == sqrt(x) && i < x)
		{
			total += i;
		}
		else if(x % i == 0 && i < x)
		{
			total += (i + (x/i));
		}
	}
	return total;
}

bool amicableNum(int x)
{
	if(x == divSum(divSum(x)) && x != divSum(x))
	{
		return true;
	}
	return false;
}

//Not perfect but work
int problem10()
{
	ifstream start;
	int temp, result = 0;
	int grid[20][20];
	start.open("problem10.txt");
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			start >> grid[i][j];
		}
	}
	start.close();
	//3, 17
	//3 , 17
	for(int k = 3; k < 17; k++)
	{
		for(int l = 3; l < 17; l++)
		{
			temp = grid[k][l] * grid[k+1][l+1] * grid[k+2][l+2] * grid[k+3][l+3];
			if(temp > result)
				result = temp;
			temp = grid[k][l] * grid[k][l+1] * grid[k][l+2] * grid[k][l+3];
			if(temp > result)
				result = temp;
			temp = grid[k][l] * grid[k+1][l] * grid[k+2][l] * grid[k+3][l];
			if(temp > result)
				result = temp;
			temp = grid[k][l] * grid[k-1][l-1] * grid[k-2][l-2] * grid[k-3][l-3];
			if(temp > result)
				result = temp;
			temp = grid[k][l] * grid[k-1][l+1] * grid[k-2][l+2] * grid[k-3][l+3];
			if(temp > result)
				result = temp;
			temp = grid[k][l] * grid[k+1][l-1] * grid[k+2][l-2] * grid[k+3][l-3];
			if(temp > result)
				result = temp;
		}
	}
	return result;
}

double problem13()
{
	ifstream start;
	double total = 0;
	start.open("Problem13.txt");
	double x[100];
	for(int i = 0; i < 100; i++)
	{
		start >> x[i];
	}
	start.close();
	for(int j = 0; j < 100; j++)
	{
		total += x[j];
	}
	return total;
}

//counting Sundays
int problem19()
{
	int dayOfWeek = 2, count = 0;
	for(int year = 1901; year <= 2000; year++)
	{
		if(year % 4 == 0)
		{
			for(int month = 1; month <= 12; month++)
			{
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					for(int days = 1; days <= 31; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
				else if(month == 2)
				{
					for(int days = 1; days <= 29; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
				else
				{
					for(int days = 1; days <= 30; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
			}
		}
		else
		{
			for(int month = 1; month <= 12; month++)
			{
				if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
				{
					for(int days = 1; days <= 31; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
				else if(month == 2)
				{
					for(int days = 1; days <= 28; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
				else
				{
					for(int days = 1; days <= 30; days++)
					{
						if(dayOfWeek == 7 && days == 1)
						{
							count++;
							dayOfWeek = 0;
						}
						else if(dayOfWeek == 7)
						{
							dayOfWeek = 0;
						}
						dayOfWeek++;
					}
				}
			}
		}
	}
	return count;
}

int main()
{
	int total = 0;
	for(int i = 1; i < 10000; i++)
	{
		if(amicableNum(i))
		{
			total += i;
		}
	}
	cout << total << endl;
	return 0;
}