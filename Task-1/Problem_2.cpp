/* Name: Tushar Goel
Student_id: 001356901
*/

#include <iostream>
#include <stdio.h>
using namespace std;

int main ()
{
	int x = 1, y = 9;
	int *p1, *p2;
	p1 = &x;
	p2 = &y;
	int i=0;

	cout << "\nInitially" << endl;
	cout << "pointer p1 points to " << *p1 << " and " << " pointer p2 points to " << *p2 << endl; // Prints "1 and 9"
	cout << "value of x --> " << x << " and " << "value of y --> " << y << endl; // Prints "1 and 9"

	int *temp1;
	
	temp1=p1;
	p1=p2;
	p2=temp1;
	cout << "\nAfter the operation" << endl;
	cout << "pointer p1 points to " << *p1 << " and " << " pointer p2 points to " << *p2 << endl; // Prints "9 and 1"
	cout << "value of x --> " << x << " and " << "value of y --> " << y << endl; // Prints "1 and 9"
	cout <<"\n";		
	return 0;
}