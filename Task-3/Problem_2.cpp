#include<stdlib.h> 
#include<stdio.h> 
#include <iostream>
#include <string>
using namespace std;

int randomGenerator(int lowerLimit, int upperLimit)
{
	int randomNumber = 0;
	randomNumber = (rand() % (upperLimit-lowerLimit + 1)) + lowerLimit;
	return randomNumber;
}

void birthdayGenerator(int birthday[])
{

	for (int i=0;i<1000;i++)
	{
		birthday[i]= (randomGenerator(1,12) * 10000) + (randomGenerator(1,28) * 100) + (randomGenerator(0,4)); 
	}	
}

void hashtTable(int birthday[], int m)
{
	int collisions[m];

	for (int i=0;i<m;i++)
	{
		collisions[i]=0;
	}

	for (int j=0;j<1000;j++)
	{
		collisions[birthday[j]%m]++;
	}

	int minimum=collisions[0];
	int maximum=collisions[0];
	int mean=0;
	int variance=0;
	int sum=0;

	for (int i=0;i<m;i++)
	{
		if (minimum>collisions[i])
		{
			minimum=collisions[i];
		}

		if (maximum<collisions[i])
		{
			maximum=collisions[i];
		}
		sum=sum+collisions[i];
	}
	mean=sum/m;
	
	for (int i=0;i<m;i++)
	{
		variance = variance + ((collisions[i] - mean) * (collisions[i] - mean));
	}

	variance=variance/m;

	cout << "------------------------------------------------------" << endl;
	cout << "Hash table with size --> " << m << endl;
	cout << "Minimum --> " << minimum << endl;
	cout << "Maximum --> " << maximum << endl;
	cout << "Mean --> " << mean << endl;
	cout << "Variance --> " << variance << endl;
	cout << "Maximum Number of collisions --> " << maximum-1 << endl;
}

int main()
{
	int birthday[1000];
	int m1=64;
	int m2=66;
	int m3=67;
	int m4[]={47,53, 59, 61};
	
	birthdayGenerator(birthday);

	hashtTable(birthday,m1);
	hashtTable(birthday,m2);
	hashtTable(birthday,m3);
	int size = sizeof(m4)/sizeof(m4[0]);

	for (int i=0;i<size;i++)
	{
		hashtTable(birthday,m4[i]);
	}

	return 0;
}