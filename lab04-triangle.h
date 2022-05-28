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

bool triangle::operator==(PhysObj& object) const {
	if (weight == object.mass​()) {
		return true;
	}
	return false;
}

bool triangle::operator<(PhysObj& object) const {
	if (weight < object.mass​()) {
		return true;
	}
	return false;
}

triangle::triangle() {
	first_pointi.x = 0;
	first_pointi.y = 0;
	second_pointi.x = 0;
	second_pointi.y = 0;
	third_pointi.x = 0;
	third_pointi.y = 0;
	side = 0;
	weight = 0;
}

inline triangle::triangle(std::pair<double, double> first_point, std::pair<double, double> second_point, std::pair<double, double> third_point, double s, double mass)
{
	first_pointi.x = 0;
	first_pointi.y = 0;
	second_pointi.x = 0;
	second_pointi.y = 0;
	third_pointi.x = 0;
	third_pointi.y = 0;
	side = 0;
	weight = 0;
}

inline triangle::triangle(double first_point_x, double first_point_y, double second_point_x, double second_point_y, double third_point_x, double third_point_y, double s, double mass)
{
	first_point.x = first_point_x;
	first_point.y = first_point_y;
	second_point.x = second_point_x;
	second_point.y = second_point_y;
	third_point.x = third_point_x;
	third_point.y = third_point_y;
	side = s;
	weight = mass;
}

double triangle::square() {
	return ((sqrt(3) / 4) * pow(side, 2));
}

double triangle::perimeter() {
	return 3 * side;
}

double triangle::mass​() {
	return weight;
}

CVector2D triangle::position() {
	CVector2D answer;
	answer.x = (first_point.x + second_point.x + third_point.x) / 3;
	answer.y = (first_point.y + second_point.y + third_point.y) / 3;
	return answer;
}

void triangle::draw() {
	std::cout << classname() << "\n";
	std::cout << square() << "\n";
	std::cout << perimeter() << "\n";
	std::cout << size() << "\n";
	//std::std::cout << mass() << "\n"; 
	std::cout << "x = " << position().x << ", y = " << position().y << endl;
}

void triangle::initialization() {
	cin >> first_point.x >> first_point.y;
	cin >> second_point.x >> second_point.y;
	cin >> third_point.x >> third_point.y;
	cin >> side;
	cin >> weight;
}

const char* triangle::classname() {
	return "triangle";
}

unsigned triangle::size() {
	return sizeof(triangle);
}