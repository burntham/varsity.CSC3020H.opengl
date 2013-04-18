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
{   // Change to the Modelview
    glMatrixMode(GL_MODELVIEW);
    
    //clears colour and depth buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    //render the teapot set the render colour of the teapot
    glColor3f(1.0f, 0.5f, 0.0f);
    //draw a teapot
    glutSolidTeapot(0.4);
    
    //enables opengl's depth test
    glEnable(GL_DEPTH_TEST);
    // Reset Matrix
    glLoadIdentity();
    //enables lighting
    glEnable(GL_LIGHTING);
    //adds a light to the scene
    glEnable(GL_LIGHT0);
    //swaps the double buffer
    
    glFlush();
    glutSwapBuffers();
}

void Keyinput(unsigned char key, int mousePos_x, int mousePos_y){
  switch ( key ) 
  {
      case 27://exit button pressed
      exit ( 0 );   
      break;      

    default:      
      break;
  }
};

int main(int argc, char** argv) {
    //initialize
    glutInit(&argc,argv);
    //set window position
    glutInitWindowPosition(100,100);
    //set window size
    glutInitWindowSize(600,600);
    //set display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);   
    //create a window
    glutCreateWindow("Teapot?");    
    //displays the objects for the first time
    glutDisplayFunc(&display);
    //displays the objects(updates)
    glutIdleFunc(&display);
    //Handle Keyboard input;
    glutKeyboardFunc(&Keyinput);
    
  
  //main loop
  glutMainLoop();
    
}

