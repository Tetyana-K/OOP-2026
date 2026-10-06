#pragma once

template<typename T = int,  unsigned size = 10> //типований параметр шаблону T, фактичний параметр для T може бути  тип int, double, string, Person 
//НЕтипований параметр шаблону size, фактичний параметр для size може бути  const типу unsigned 
class FArray
{
public:
	FArray() = default;
	FArray(const T& value);
	void fill(const T& value); // заповнює певним значенням масив
	void  print() const;
	T array[size]{}; // поле - масив фіксованого розміру (size) з елементів Т
	T& operator[] (int index);
	bool isValidIndex(int index) const;
private:

	template<typename U, unsigned len>
	friend ostream& operator << (ostream& out, const FArray<U, len>& obj);
};

template<typename T, unsigned size>
inline FArray<T, size>::FArray(const T& value)
{
	fill(value); //заповнили масив однаковим значенням value
}
// кожен метод шаблонного класу =  шаблонна функція !
template<typename U, unsigned size>
inline void FArray<U, size>::fill(const U& value)
{
	for (size_t i = 0; i < size; i++)
	{
		array[i] = value;
	}
}

template<typename T, unsigned size>
inline void FArray<T, size>::print() const
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "\t" << array[i];
	}
	cout << endl;
}

template<typename T, unsigned size>
inline T& FArray<T, size>::operator[](int index)
{
	if (isValidIndex(index))
		return array[index];
	throw out_of_range("Wrong index " + to_string(index) + " in operator []");
}

template<typename T, unsigned size>
inline bool FArray<T, size>::isValidIndex(int index) const
{
	return index >= 0 && index < size;
}

template<typename U, unsigned len>
inline ostream & operator<<(ostream& out, const FArray<U, len>& obj)
{
	out << "Array (<<)\n";
	for (size_t i = 0; i < len; i++)
	{
		out << obj.array[i] << "\t";
	}
	out << endl;
	return out;
}
