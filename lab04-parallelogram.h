#pragma once
#include "lab04-figure.h"

struct parallelogram : public all
{
private:
	CVector2D first_pointi, second_pointi, third_pointi, forth_pointi;
	double side, weight;
public:
	virtual ~parallelogram() = default; // защищенный деструктор
	parallelogram& operator=(const parallelogram&) = default; // запрет присваивания
	parallelogram();
	parallelogram(std::pair<double, double> first_point, std::pair<double, double> second_point, std::pair<double, double> third_point, std::pair<double, double> forth_point, double s, double mass);
	double square();
	double perimeter();
	double mass();
	CVector2D position();
	bool operator==(PhysObj& object) const;
	bool operator<(PhysObj& object) const;
	void draw();
	void initialization();
	const char* classname();
	unsigned size();
};
