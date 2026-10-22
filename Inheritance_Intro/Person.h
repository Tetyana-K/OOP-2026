#pragma once
#include <string>
using std::string;
class Human // буде як базовий для класу Developer 
{
public:
	Human(const string& name = "Noname", int age = 0);

	const string& getName() const
	{
		return name;
	}
	void walk() const;
	void eat() const;
	virtual void learn() const;
	void learn(int hours) const;
	~Human();
private: // приватні поля та методи будуть видимі ТІЛЬКИ у межах цього класу, похідні типи НЕ бачать напряму приватної частини
	string name;
protected: // захищені поля та методи видимі тут, У ПОХІДНИХ ТИПАХ ТЕЖ, НЕ видимі ззовні
	int age;
};

