// 01_Exception.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double div(double a, double b)
{
	if (b == 0)
		throw invalid_argument("Error division by  zero\n"); // кидається виняток типу  invalid_argument
	if (b > 1'000'000)
		throw overflow_error("Too big divisor(> 1'000'000)"); // кидається виняток типу overflow_error
	if (b < -1'000'000)
		throw underflow_error("Too small divisor(< -1'000'000)"); // кидається виняток типу 		throw underflow_error("Too small divisor(< -1'000'000)"); // кидається виняток типу double  із  значенням b 

	return a / b;
}

int main()
{
	double a;
	double b;
	
	while (cout << "Enter two  numbers : ", cin >> a >> b)
	{
		try
		{
			cout << a << " / " << b << " = " << div(a, b) << endl;
		}
		catch (overflow_error& ex) // потрібно  спочатку розміщувати обробники більш  спеціалізовані, потім більш  загальні
		{
			cout << "Caught overflow_error : " << ex.what() << endl;
		}
		catch (underflow_error& ex)
		{
			cout << "Caught " << typeid(ex).name() << " : " << ex.what() << endl;
		}
		catch (exception& ex/*invalid_argument &  ex*/) // default catch
		{
			cout << "***Caught exception "<< typeid(ex).name() <<" : " << ex.what() << endl;
		}
	}
}


