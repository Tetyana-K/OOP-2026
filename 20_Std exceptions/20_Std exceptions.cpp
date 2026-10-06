// 02_std exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
int main()
{
    //exception ex ("Some error"); // exception - базовий клас для стандарних винятків, має  метод what(), який повертає повідомлення про помилку
    //cout << "What : " << ex.what() << endl;

    //invalid_argument ex2("error argument");// invalid_argument  -  клас стандартного винятку, який позначає помилки невірного аргумента
    //cout << "What : " << ex2.what() << endl;
    // throw ex2;

   
    string str = "Hello std exceptions";
    //try 
    //{
    //    cout << "Fragment : " << str.substr(30, 10) << endl;
    //}
    //catch (exception& ex)
    //{
    //    cout << "Caught : " << typeid(ex).name() << endl; // typeid(ex).name() - поверене фактичний тип помилки
    //    cout << "Substr error : " << ex.what() << endl;
    //}
   
    str = "1234545";
    str = "12345.45";
    str = "12345457878787878";
    str = "abc22222";
    try
    {
        int value = stoi(str); // функція перетворення рядка у ціле число може  викидати винток(и)
        cout << "Value converted : " << value << endl;
    }
    catch (out_of_range& ex) // out_of_range - клас стандартного винятку, який позначає помилку виходу за межі діапазону
    {
        cout << "Too big ot to small int number : " << ex.what() << endl;
    }
    catch (invalid_argument& ex)
    {
        cout << "Not  int number : " << ex.what() << endl;
    }
}

