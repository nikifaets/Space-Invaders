#ifndef VECTOR_2D_H

#define VECTOR_2D_H

#include <cmath>

#define null_vector_2d Vector2D(INFINITY, INFINITY)

class Vector2D{

public:

	float x;
	float y;
	float z;
	
	Vector2D();
	Vector2D(float x_, float y_);

	float get_length();

	void operator = (const Vector2D& arg);

	Vector2D operator - (const Vector2D& arg);

	Vector2D operator + (const Vector2D& arg);
	
	Vector2D scale (const float arg);

	bool operator == (const Vector2D& arg);

	bool operator != (const Vector2D& arg);
	
	float dot(const Vector2D& arg);

	float distance_to(const Vector2D& arg);

	void print_vector();

	void threshold(float min, float max);

	Vector2D normalized();
};	


#endif