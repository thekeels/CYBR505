#include <iostream>
using namespace std;

int firstnumber = 2;

int multiplication()
{
	//int firstnumber = 2;
	int secondnumber = 4;
	int result = firstnumber * secondnumber;
	return result;
}

int main()
{
	cout << "Multiply " << endl;
	int result = multiplication();
	cout << "Result is " << result << endl;
	cout << firstnumber;

}

