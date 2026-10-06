#pragma once
#include "StdLibs.h"
class Transport // цей клас буде у нас надалі як БАЗОВИЙ ( = батьківський =  суперклас)
{

public:
	const string& getBrand() const;
	void setBrand(const string& brand);
	Transport(const string& brand = "No Brand", int year = 2000);
	virtual void move() const = 0;
	virtual void info() const;
	~Transport();
protected:
	int year; // не видиме зовні, але  похідні типи  БАЧАТЬ
private:
	string brand; // не видиме зовні, і похідні типи теж НЕ бачать


};

