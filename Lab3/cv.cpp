#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

void CALLBACK display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0); // Set up the camera position

    // Draw the sphere
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glTranslatef(0.0f, 0.0f, 0.0f); // Move sphere to origin
    GLUquadricObj* sphere = gluNewQuadric();
    gluQuadricDrawStyle(sphere, GLU_FILL); // Filled sphere
    gluSphere(sphere, 1.0f, 20, 20); // Radius of 1.0
    gluDeleteQuadric(sphere);

   
}

void myInit() {
    glClearColor(1.0, 0, 0, 0);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 600);
    auxInitWindow("Lab. 3");
    myInit();

    //auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}