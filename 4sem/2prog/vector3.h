#pragma once
#include <iostream>

class Vector3
{
private:
        // fixit: а как снаружи узнать компоненты вектора, раз они приватные
        double x;
        double y;
        double z;
public:
	// fixit: вынесите реализацию в cpp файл
	Vector3(float x, float y, float z): x(x), y(y), z(z) {};
	Vector3(): x(0), y(0), z(0) {};

	Vector3 operator+(const Vector3& other) const;
	Vector3& operator+=(const Vector3& other);
	Vector3 operator-(const Vector3& other) const;
	Vector3& operator-=(const Vector3& other);
	Vector3& invert();
	Vector3 operator-() const;
	Vector3 operator*(double k) const;

	double operator*(const Vector3& other) const;	//scalar
	Vector3 operator^(const Vector3& other) const;	//vector

	double squareLen() const;
	double len() const;
	Vector3& norm();
	Vector3& rotate(double angle, const Vector3& axis);	//in radian rotates itself
	Vector3 getRotated(double angle, const Vector3& axis) const;	// radian returns rotated 
	
	friend Vector3 operator*(double k, const Vector3& v);
	friend Vector3 operator*=(double scalar, Vector3 vec);
	friend std::ostream& operator<<(std::ostream& stream, const Vector3& vec);
	friend std::istream& operator>>(std::istream& stream, Vector3& vec);
};

	bool almostEqual(double lhs, double rhs);
