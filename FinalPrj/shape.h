#pragma once

#include <gl\gl.h>             	//header file for openGL
#include <gl\glu.h>             //header file for the openGL utility library
#include <gl\glut.h>           	//header file for GLUT

struct _shape {
	struct {
		GLfloat x, y;
	} pos;
	GLfloat rot;
	GLfloat *vertices;
	int vertex_count;

	_shape() { // Constructor
		pos.x = 0;
		pos.y = 0;
		rot = 0;
		vertex_count = 0;
	}
};