#pragma once
// у .h-файлі пишемо визначення класу, реалізацію inline-методів
// у .cpp-файлі пишемо  реалізацію інших не реалізованих методів
//
class Point3D
{
public:
	Point3D():x(x), y(y), z(z)
	{
		/*x = 0;
		y = 0;
		z = 0;*/
	}
	Point3D(int x, int y, int z);
	void print() const;
private:
	int x;
	int y;
	int z;
};

