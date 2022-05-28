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

bool parallelogram::operator==(PhysObj& object) const {
	if (weight == object.mass​()) {
		return true;
	}
	return false;
}

bool parallelogram::operator<(PhysObj& object) const {
	if (weight > object.mass()) {
		return false;
	}
	return true;
}

parallelogram::parallelogram() {
	first_pointi.x = 0;
	first_pointi.y = 0;
	second_pointi.x = 0;
	second_pointi.y = 0;
	third_pointi.x = 0;
	third_pointi.y = 0;
	forth_pointi.x = 0;
	forth_pointi.y = 0;
	side = 0;
	weight = 0;
}

inline parallelogram::parallelogram(std::pair<double, double> first_point, std::pair<double, double> second_point, std::pair<double, double> third_point, std::pair<double, double> forth_point, double s, double mass)
{
	first_pointi.x = first_point.first;
	first_pointi.y = first_point.second;
	second_pointi.x = second_point.first;
	second_pointi.y = second_point.second;
	third_pointi.x = third_point.first;
	third_pointi.y = third_point.second;
	forth_pointi.x = forth_point.first;
	forth_pointi.y = forth_point.second;
	side = s;
	weight = mass;
}

double parallelogram::square() {
	return (side * side);
}

double parallelogram::perimeter() {
	return 4 * side;
}

double parallelogram::mass​() {
	return weight;
}

CVector2D parallelogram::position() {
	CVector2D answer;
	answer.x = (first_pointi.x + second_pointi.x + third_pointi.x + forth_pointi.x) / 4;
	answer.y = (first_pointi.y + second_pointi.y + third_pointi.y + forth_pointi.y) / 4;
	return answer;
}

void parallelogram::draw() {
	std::cout << classname() << "\n";
	std::cout << square() << "\n";
	std::cout << perimeter() << "\n";
	std::cout << size() << "\n";
	std::cout << position().x << position().y << endl;
}

void parallelogram::initialization() {
	std::cin >> first_pointi.x >> first_pointi.y;
	std::cin >> second_pointi.x >> second_pointi.y;
	std::cin >> third_pointi.x >> third_pointi.y;
	std::cin >> forth_pointi.x >> forth_pointi.y;
	std::cin >> side;
	std::cin >> weight;
}

const char* parallelogram::classname() {
	return "parallelogram";
}

unsigned parallelogram::size() {
	return sizeof(parallelogram);
}
