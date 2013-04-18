/* 
 * File:   Driver.cpp
 * Author: brunt
 *
 * Created on 17 April 2013, 10:31 PM
 */

#include <cstdlib>
#include <GL/glut.h>
#include <string>

using namespace std;

void display()
{
  // Change to the Modelview
  glMatrixMode(GL_MODELVIEW);
  //clears colour and depth buffers
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  //enables opengl's depth test
  glEnable(GL_DEPTH_TEST);
  // Reset Matrix
  glLoadIdentity();
  //enables lighting
  glEnable(GL_LIGHTING);
  //adds a light to the scene
  glEnable(GL_LIGHT0);
  //swaps the double buffer
  glutSwapBuffers();
  
}

int main(int argc, char** argv) {
    glutInit(&argc,argv);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(300,300);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   
    glutCreateWindow("what?");
    
      //displays the objects for the first time
  glutDisplayFunc(&display);
  //displays the objects(updates)
  //glutIdleFunc(&display);
  
  //main loop
  glutMainLoop();
    
}

