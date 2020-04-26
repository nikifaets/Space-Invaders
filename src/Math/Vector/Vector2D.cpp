#include "Vector2D.h"
#include <cmath>
#include <iostream>
using namespace std;

Vector2D::Vector2D(): x(0), y(0) {}
Vector2D::Vector2D(float x_, float y_): x(x_), y(y_){}

float Vector2D::get_length(){

	return sqrt(x*x + y*y);
}

void Vector2D::operator = (const Vector2D& arg){

	this->x = arg.x;
	this->y = arg.y;

}

Vector2D Vector2D::operator - (const Vector2D& arg){

	float x = this->x - arg.x;
	float y = this->y - arg.y;

	return Vector2D(x,y);
}

Vector2D Vector2D::operator + (const Vector2D& arg){

	float x = this->x + arg.x;
	float y = this->y + arg.y;

	return Vector2D(x,y);

}

Vector2D Vector2D::scale(const float arg){

	float x = this->x * arg;
	float y = this->y * arg;

	return Vector2D(x,y);
}

bool Vector2D::operator == (const Vector2D& arg){

	return this->x == arg.x && this->y == arg.x;
}

bool Vector2D::operator != (const Vector2D& arg){

	return this->x != arg.x || this->y != arg.y;
}

float Vector2D::dot(const Vector2D& arg){

	float dot_x = this->x * arg.x;
	float dot_y = this->y * arg.y;

	return dot_x + dot_y;
}

float Vector2D::distance_to(const Vector2D& arg){

	float dist_x = pow((this->x - arg.x), 2);
	float dist_y = pow((this->y - arg.y), 2);

	return sqrt(dist_x + dist_y);
}

void Vector2D::print_vector(){

	cout << "x " << x << " y " << y << endl;

}

void Vector2D::threshold(float min, float max){

	if(x < min) x = min;
	if(x > max) x = max;

	if(y < min) y = min;
	if(y > max) y = max;

}

Vector2D Vector2D::normalized(){

	float length = get_length();
	float xn = x/length;
	float yn = y/length;
	float zn = z/length;

	return Vector2D(xn, yn);
}
