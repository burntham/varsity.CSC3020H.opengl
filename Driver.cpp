/* 
 * File:   Driver.cpp
 * Author: brunt
 *
 * Created on 17 April 2013, 10:31 PM
 */

#include <cstdlib>
#include <GL/glut.h>
#include <string>
#include "Attributes.h"
#include "Handler.h"

using namespace std;
float i =1.0;
void display()
{ 
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load the identity matrix
    gluLookAt(0,0,camDist,0,0,0,0,1,0);  
    rotateCamera();//call the camera rotating
    glEnable(GL_DEPTH_TEST);//enable depth testing
    drawGlobAxis();//self explanatory

    glColorMaterial (GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
    glEnable(GL_COLOR_MATERIAL);
    
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
    
    //glTranslatef(-5,0,0);
    //glRotatef(45,0,0,1);
    drawTeapot();
    //glPopMatrix();
    glutSwapBuffers();
}



int main(int argc, char** argv) {
    //initialize
    glutInit(&argc,argv);
    //set window position
    glutInitWindowPosition(100,100);
    //set window size
    glutInitWindowSize(600,600);
    //set display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );   
    //create a window
    glutCreateWindow("Teapot?");    
    //displays the objects for the first time
    glutDisplayFunc(&display);
    //displays the objects(updates)
    glutIdleFunc(&display);
    //Handle Keyboard input;
    glutKeyboardFunc(&Keyinput);
    //set first trans axis to X
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 90.0f,1, 0.1f, 100.0f);
    
  //main loop
  glutMainLoop();
    
}

