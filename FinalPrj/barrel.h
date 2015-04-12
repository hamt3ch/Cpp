#pragma once

#include <vector>

#include "shape.h"
#include "object.h"

class Character : public Object
{
private:
	float x;
	float y;
	float speed_x;
	float speed_y;
	float max_speed_x;
	float max_speed_y;
	float gravity;
	float friction;

	int collision_box_left;
	int collision_box_top;
	int collision_box_right;
	int collision_box_bottom;

	int boundary_left;
	int boundary_right;
	int boundary_ground;

	_shape my_shape;

public:
	Character();
	Character(std::vector<Object*> &objects);
	Character(std::vector<Object*> &objects, float x, float y);
	~Character();

	float getX(void);
	float getY(void);
	float getSpeedX(void);
	float getSpeedY(void);

	void setX(float x);
	void setY(float y);
	void setSpeedX(float speed_x);
	void setSpeedY(float speed_y);

	void addSpeedX(float accel);
	void addSpeedY(float accel);

	void updateSelf(void);
	void drawSelf(void);

	bool onGround(void);

	_shape getShape(void);
};