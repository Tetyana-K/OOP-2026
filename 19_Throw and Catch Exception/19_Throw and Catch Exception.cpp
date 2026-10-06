
#include <iostream>
using namespace std;
double div(double a, double b)
{
	if (b == 0)
		throw "Error division by  zero\n"; // кидається виняток типу const  char*  із  значенням "Error division by  zero\n"
	if (b > 1'000'000)
		throw b; // кидається виняток типу double із значенням b 
	if (b < -1'000'000)
		throw (int)b; // кидається виняток типу int  із  значенням (int)b 
	return a / b;
}
//void terminate() // перекрити terminate()можна однойменної своєю функцією
//{
//	cout << "Error! My  terminate has worked\n";
//	exit(EXIT_FAILURE);
//}
void my_terminate() // перекрити terminate()можна однойменної своєю функцією
{
	cout << "Error! My  terminate has worked\n";
	exit(EXIT_FAILURE);
}
int main()
{
	//set_terminate(my_terminate);
	double a, b;
	//cout << "Enter two  numbers : ";
	//cin >> a >> b;
	//try  // захищений блок, тут викликаємо функції, які можуть викидати винятки
	//{
	//	cout << "result  = " << div(a, b) << endl;
	//}
	//catch (int error)
	//{
	//	cout << "Caught int error : " << error << endl;
	//}
	//catch (const char * error)// обробник винятку
	//{
	//	cout << "Caught : " << error << endl;
	//}
	//cout << "Enter two  numbers : ";
	
	while (cout << "Enter two  numbers : ", cin >> a >> b) // працює доки ввід  коректний
	{
		try
		{
			cout << a << " / " << b << " = " << div(a, b) << endl;
		}
		catch (const char* ex)// блок обробки помилки типу const  char*
		{
			cout << "Caught const char  * : " << ex << endl;
		}
		catch (double errValue)// блок обробки помилки типу double
		{
			cout << "Caught double : too big divisor " << errValue << endl;
		}
		catch(int errValue)
		{
			cout << "Caught int : too small divisor " << errValue << endl;

		}
		catch (...) // обробить всі інші помилки, дефолнтий catch,  розміщуємо останнім
		{
			cout << "Caught ...\n";
		}
	}
}


