#include "character.h"

#include <vector>

#include <gl\gl.h>             	//header file for openGL
#include <gl\glu.h>             //header file for the openGL utility library
#include <gl\glut.h>           	//header file for GLUT

#include "shape.h"
#include "object.h"

Character::Character()
{
	// Defaults
	x = 0.0;
	y = 0.0;
	speed_x = 0.0;
	speed_y = 0.0;
	max_speed_x = 1.0;
	max_speed_y = 2.0;
	gravity = 0.05;
	friction = 0.2;

	collision_box_left = -0.5;
	collision_box_right = 0.5;
	collision_box_top = 0.5;
	collision_box_bottom = -0.5;

	boundary_left = -9;
	boundary_right = 9;
	boundary_ground = 0;

	my_shape = _shape();
}

Character::Character(std::vector<Object*> &vec)
{
	Character();

	vec.push_back(this);
}

Character::Character(std::vector<Object*> &vec, float x, float y)
{
	vec.push_back(this);

	// Inputs
	x = x;
	y = y;
}

Character::~Character()
{
}

float Character::getX(void) { return x; }
float Character::getY(void) { return y; }
float Character::getSpeedX(void) { return speed_x; }
float Character::getSpeedY(void) { return speed_y; }

void Character::setX(float x) { x = x; }
void Character::setY(float y) { y = y; }
void Character::setSpeedX(float speed_x) { speed_x = speed_x; }
void Character::setSpeedY(float speed_y) { speed_y = speed_y; }

void Character::addSpeedX(float accel)
{
	speed_x += accel;

	if (speed_x > max_speed_x)
		speed_x = max_speed_x;
	else if (speed_x < -max_speed_x)
		speed_x = -max_speed_x;
}

void Character::addSpeedY(float accel)
{
	speed_y += accel;

	if (speed_y > max_speed_y)
		speed_y = max_speed_y;
	else if (speed_y < -max_speed_y)
		speed_y = -max_speed_y;
}

void Character::updateSelf(void)
{
	// Apply gravity!
	addSpeedY(-gravity);

	// Apply friction!

	if (onGround()) // Only apply friction while on the ground
	{
		if (speed_x < 0)
		{
			speed_x += friction;

			if (speed_x > 0)
				speed_x = 0;
		}
		else
		{
			speed_x += -friction;

			if (speed_x < 0)
				speed_x = 0;
		}
	}

	// Move the character!

	/*
	[ INSERT COLLISION DETECTION ]
	*/

	x += speed_x;
	y += speed_y;

	// Enforce boundaries!
	if (x < boundary_left)
	{
		x = boundary_left;
		speed_x = 0;
	}

	if (x > boundary_right)
	{
		x = boundary_right;
		speed_x = 0;
	}

	if (y < boundary_ground)
	{
		y = boundary_ground;
		speed_y = 0;
	}
}

void Character::drawSelf(void)
{
	// Set the position on the screen that the Character should be drawn at
	glColor3f(1.0, 1.0, 0.0);
	setShapePos(x, y);
	glTranslatef(getShapeX(), getShapeY(), 0.0);
	glRotatef(getShapeRot(), 0, 0, 1.);

	// Draw to the screen
	glVertexPointer(2, GL_FLOAT, 0, getShapeVertices());
	glDrawArrays(GL_POLYGON, 0, getShapeVertexCount());
}

bool Character::onGround(void)
{
	return (y == boundary_ground);
}