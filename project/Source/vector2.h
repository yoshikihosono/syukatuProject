#pragma once

class Vector2 {
public:
	double x, y;

	Vector2() : x(0), y(0) {}
	Vector2(double _x, double _y) : x(_x), y(_y) {}
	Vector2(int _x, int _y) : x(static_cast<double>(_x)), y(static_cast<double>(_y)) {}
};