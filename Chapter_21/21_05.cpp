#include <iostream> // ’σκηση 21.5 
#include <string>
using std::cout;
using std::string;

class Shape
{
private:
	float cntr_x;
	float cntr_y;
public:
	Shape(float x, float y) : cntr_x(x), cntr_y(y) {}
	virtual ~Shape() {}
	virtual void show() const {cout << "Cx:" << cntr_x << ' ' << "Cy:" << cntr_y << '\n';}
	virtual void area() const = 0;
};

class Shape2D : public Shape
{
private:
	string name;
public:
	Shape2D(float x, float y, const string& n) : Shape(x, y), name(n) {}
};

class Rect : public Shape2D
{
private:
	float len;
	float hght;
public:
	Rect(float x, float y, const string& n, float l, float h) : Shape2D(x, y, n), len(l), hght(h) {}
	virtual void area() const {cout << "\nArea(R):" << len*hght << '\n';}
	virtual void show() const;
};

void Rect::show() const
{
	area();
	Shape::show();
} 

class Shape3D : public Shape
{
private:
	string col;
public:
	Shape3D(float x, float y, const string& n) : Shape(x, y), col(n) {}
	virtual void vol() const = 0;
};

class Sphere : public Shape3D
{
private:
	float rad;
public:
	Sphere(float x, float y, const string& n, float r) : Shape3D(x, y, n), rad(r) {}
	virtual void area() const {cout << "Area(S):" << 4*3.14*rad*rad << '\n';}
	virtual void vol() const {cout << "Vol(S):" << (4/3.0)*3.14*rad*rad*rad << '\n';}
	virtual void show() const;
};

void Sphere::show() const
{
	area();
	vol();
	Shape::show();
}

