#define GLUT_DISABLE_ATEXIT_HACK
#define GLUT_RGB
#define GLUT_DOUBLE
#define GLUE_DEPTH
#define ORTHO_SCALE 10.
#include <windows.h>           	//header file for windows
#include <ctime>				//header file for clock definitions
#include <vector>
#include <gl\gl.h>             	//header file for openGL
#include <gl\glu.h>             //header file for the openGL utility library
#include <gl\glut.h>           	//header file for GLUT

#include "shape.h"
#include "object.h"
#include "character.h"

#include <cstdio> // Temporarily included for debugging using std::printf()

void display(void);
void keyboard(unsigned char key, int x, int y);
void special(int key, int x, int y);
void update(void);

GLfloat square_vertices[] = {
	-0.5, -9.0,
	0.5, -9.0,
	0.5, -8.0,
	-0.5, -8.0
};

std::vector<Object*> objects;
Character* player;

void timer(int value){
	update();
	glutTimerFunc(16, timer, 0);
}

int main(int argc, char *argv[])
{
	// Temporary game initialization
	objects = {};
	player = new Character();
	player->updateShape(square_vertices);

	// GLUT initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

    glutCreateWindow("Working Title");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(special);
	glutTimerFunc(0, timer, 0);

	glutMainLoop(); // game loop allows game to keep running

    return 0;
}

void display(void)
{
    GLuint win_width, win_height;		// setting up game window
    GLfloat win_aspect;

    win_width  = glutGet(GLUT_WINDOW_WIDTH);
    win_height = glutGet(GLUT_WINDOW_HEIGHT);
    win_aspect = (float)win_width/(float)win_height;

    glViewport(0, 0, win_width, win_height);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-win_aspect * ORTHO_SCALE, 
             win_aspect * ORTHO_SCALE, 
        -ORTHO_SCALE, 
         ORTHO_SCALE,
         -1., 1.);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

	/*glTranslatef((shape.pos.x, shape.pos.y, 0.);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 0, player->getShapeVertices());//shape.vertices);
	glDrawArrays(GL_POLYGON, 0, player->getShapeVertexCount());*/

    glEnableClientState(GL_VERTEX_ARRAY);

	//for (unsigned i = 0; i < objects.size(); i++)
	//	objects[i]->drawSelf();
	player->drawSelf();

    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	default:
		break;
	}
}

void special(int key, int x, int y)
{
    switch(key) {
	case GLUT_KEY_LEFT:
		if (player->onGround())
			player->addSpeedX(-1);
        break;
	case GLUT_KEY_RIGHT:
		if (player->onGround())
			player->addSpeedX(1);
        break;
	case GLUT_KEY_UP:
		if (player->onGround())
			player->addSpeedY(1);
        break;
    case GLUT_KEY_DOWN:
        break;
    }
    glutPostRedisplay();
}

void update(void)
{
	player->updateSelf();

	glutPostRedisplay();
}