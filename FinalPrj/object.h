#pragma once

#include "shape.h"

class Object
{
private:
	_shape my_shape;

public:
	virtual void updateSelf(void) = 0;
	virtual void drawSelf(void) = 0;

	void updateShape(GLfloat vertices[])
	{
		my_shape.vertices = vertices;
		my_shape.vertex_count = sizeof vertices;
	}

	GLfloat* getShapeVertices(void) { return my_shape.vertices; }
	int getShapeVertexCount(void) { return my_shape.vertex_count; }
	double getShapeX(void) { return my_shape.pos.x; }
	double getShapeY(void) { return my_shape.pos.y; }
	double getShapeRot(void) { return my_shape.rot; }

	void setShapePos(double x, double y) { my_shape.pos.x = x; my_shape.pos.y = y; }
};