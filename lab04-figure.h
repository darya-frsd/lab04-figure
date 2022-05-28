// lab04-figure.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
#pragma once

#include <iostream>

using namespace std;

struct Geofig {
public:
	virtual double square() = 0;
	virtual double perimeter() = 0;
};

struct CVector2D {
public:
	double x, y;
	CVector2D(double x, double y) : x(x), y(y) {}
	CVector2D() : x(0), y(0) {}
	CVector2D(const CVector2D& second) {
		this->x = second.x;
		this->y = second.y;
	}
};

struct PhysObj {
public:
	virtual double mass​() = 0;
	virtual CVector2D position() = 0;
	virtual bool operator==(PhysObj& ob) const = 0;
	virtual bool operator<(PhysObj& ob) const = 0;
};

struct Diagonalinit {
	virtual void initialization() = 0;
};

struct BaseObj {
public:
	virtual const char* classname() = 0;
	virtual unsigned int size() = 0;
};

struct all : public  BaseObj, public Diagonalinit, public PhysObj, public CVector2D, public Geofig {};