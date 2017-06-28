#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif // !_USE_MATH_DEFINES

#include <iostream>
#include <cmath>



using namespace std;

constexpr double test() { return M_PI * 2; };
int firstnumber = 2;

int multiplication()
{
	//int firstnumber = 2;
	double secondnumber = 4;
	int result = firstnumber * secondnumber;
	return result;
}

int main()
{

	double pitest = test();
	double pi = M_PI;
	int testvariable{ 100000 };
	int testtrunck = testvariable;
	//short int test  = testtrunck;
	double  x = sizeof(int);
	int y = sizeof(short int);
	int z;
	cout << "Multiply " << endl;
	int result = multiplication();
	cout << "Result is " << result << endl;
	cout << firstnumber;

}

