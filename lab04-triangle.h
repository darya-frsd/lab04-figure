#pragma once
#include "lab04-figure.h"

struct triangle : public all
{
private:
	CVector2D first_pointi, second_pointi, third_pointi;
	double side, weight;
public:
	virtual ~triangle() = default; // защищенный деструктор
	triangle& operator=(const triangle&) = default; // запрет присваивания
	triangle();
	triangle(std::pair<double, double> first_point, std::pair<double, double> second_point, std::pair<double, double> third_point, double s, double mass);
	double square();
	double perimeter();
	double mass​();
	CVector2D position() override;
	bool operator==(PhysObj& object) const;
	bool operator<(PhysObj& object) const;
	void draw();
	void initialization();
	const char* classname();
	unsigned size();
};
