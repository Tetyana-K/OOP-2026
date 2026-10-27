// Multi inheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// Базовий клас 1: Writer
class Writer
{
protected:
	string name; // name у похідному типі буде ВИДИМИЙ

public:
	Writer(const string& name = "Noname")// 2 in 1
		: name(name)
	{
		cout << "\t\tCtor Writer " << name << endl;
	}
public:
	void write() const
	{
		cout << "Writing an article." << endl;
	}
	void show()const
	{
		cout << "Writer's name is " << name << endl;
	}
	~Writer()
	{
		cout << "\t\tDtor Writer " << name << endl;
	}
};

// Базовий клас 2: Photographer
class Photographer
{
protected:
	int experience;

public:
	Photographer(int experience = 1)
		: experience(experience)
	{
		cout << "\t\tCtor Photographer with  experience of " << this->experience << " year(s)" << endl;
	}
	void takePhoto() const
	{
		cout << "Taking a photo." << endl;
	}
	void show()const
	{
		cout << "Photographer has experience " << experience << " year(s)" << endl;
	}
	~Photographer()
	{
		cout << "\t\tDtor Photographer with experience " << experience << endl;

	}
};

// Клас Photojournalist, який успадковує властивості і поведінку від Writer і Photographer
class Photojournalist : public Writer, public Photographer
{
	// успадкували name as protected &  experience as protected;
	// також успадкували публічні методи  write(), takePhoto() як public
public:
	// конструктор 
	Photojournalist(const string& name = "Noname", int experience = 1)
		: Writer(name), Photographer(experience)  // викликаємо конструктори базових класів
	{

		cout << "\t\tCtor Photojouranalist name : " << this->name <<
			" experience : " << this->experience << " year(s)" << endl;
	}
	void report()const
	{
		cout << "\n____________Reporting from " << Writer::name << endl;
		write();
		takePhoto();
		cout << "__________________________________\n\n";
	}
	//void show() const //  цей метод ПЕРЕКРИЄ два успадковних show() від Writer, Photographer
	//{
	//	cout << "::PhotoJournalist Info::\n";
	//	Writer::show();
	//	Photographer::show();
	//}
	~Photojournalist()
	{
		cout << "\t\tDtor Photojournalist " << Writer::name << endl;
	}
};

int main()
{

	Writer anna("Anna");
	anna.show();

	Photographer igor(3);
	igor.show();

	Photojournalist pj("Danylo", 2);// PhotoJournalist---> ctor Writer, ctor  Photographer 
	pj.report();
	//pj.show(); // помилка компіляції, якщо не перекривали у класі Photojournalist метод show(), не зрозуміло яку show() хочемо викликати (є дві - від класу Writer, Photographer)
	cout << ">>>> Call pj.Writer::show()\n";
	pj.Writer::show(); // уточнюємо з якого класу хочемо викликати show()
	cout << ">>>> Call pj.Photographer::show()\n";
	pj.Photographer::show();
	return 0;
	Writer& writer = pj; // посиланню на базовий клас = посилання на фотожурналіста pj 
	writer.write(); // працюємо з обєктом pj тільки як з представником класу Writer

	Photographer* photographer = &pj;  // вказівнику  на  інший базовий клас = вказівник на фотожурналіста pj 
	photographer->takePhoto(); // можемо напряму звертатися тільки до методів класу Photograph

	cout << ">>>>>>>>>>>>>>>>\n";
	static_cast<Photojournalist*> (photographer)->report(); // можемо перетвореннм типів назав повернутися до типу     Photojournalist pj("Danylo", 2);// PhotoJournalist---> ctor Writer, ctor  Photographer 


	return 0;
}