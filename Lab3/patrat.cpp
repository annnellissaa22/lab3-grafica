/*
Programul afiseaza un patrat pe care il translateaza pe axa x la apasarea sagetilor stanga, dreapta
*/
#include "glos.h"

#include "gl.h"
#include "glu.h"
#include "glaux.h"

static GLfloat x = 0;
GLUquadricObj* myQuadric;


void myInit() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    myQuadric = gluNewQuadric();

}


void Sfera(){
    gluQuadricDrawStyle(myQuadric, GLU_LINE);
    glPushMatrix();
    glTranslatef(-150, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(45, 1, 1, 1);
    glColor3f(1.0, 1.0, 0);
    gluSphere(myQuadric, 30, 50, 50);
    glPopMatrix();
}

void Cilindru() {
    glPushMatrix();
    glTranslatef(-100, 0, 0);
    glRotatef(90, 1, 0, 0);
    glRotatef(60, 1, 1, 1);
    glColor3f(0.0, 1.0, 0);
    gluCylinder(myQuadric, 20, 20, 40, 30, 20);
    glPopMatrix();
}

void Cub() {
    gluQuadricDrawStyle(myQuadric, GLU_SILHOUETTE);
    glPushMatrix();
    glTranslatef(30, 0, 0);
    glRotatef(105, 1, 0, 0);
    glRotatef(90, 1, 1, 1);
    glColor3f(0, 1.0, 1.0);
    gluCylinder(myQuadric, 20, 20, 20, 4, 10);
    glPopMatrix();
}

void CALLBACK display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    Cilindru();
    Sfera();
    Cub();
    
    glPopMatrix();

    glFlush();
}

#define ISOTROPIC
#ifdef ISOTROPIC
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) {
        return;
    }
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        glOrtho(-160.0, 160.0, 160.0 * (GLfloat)h / (GLfloat)w, -160.0 * (GLfloat)h / (GLfloat)w, -200.0, 200.0);
    }
    else {
        glOrtho(-160.0 * (GLfloat)w / (GLfloat)h, 160.0 * (GLfloat)w / (GLfloat)h, -160.0, 160.0, -200.0, 200.0);
    }
    glMatrixMode(GL_MODELVIEW);
}
#else
void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;			//transformare anizotropica, forma se modifica functie de forma(dimens) viewportului
    glViewport(0, 0, w, h);	//daca w>h stabilim ca baza inaltime, si stab unit logica de dimens in fct de h(h/320, 320 lungime lat patrat)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-160.0, 160.0, -160.0, 160.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}
#endif

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 800, 600);
    auxInitWindow("Lab. 3");
    myInit();
    
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return(0);
}
