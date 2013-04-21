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
float i =1.0;
void display()
{ 
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0,0,-3,0,0,0,0,1,0);
    glEnable(GL_DEPTH_TEST);
    
    glColor3f(0.5f,0.3f,0.5f);
    glRotatef(i++,0,1,0);
    glutSolidTeapot(1); 
    glEnable(GL_LIGHTING);  
    glEnable(GL_LIGHT0);
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
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE );   
    //create a window
    glutCreateWindow("Teapot?");    
    //displays the objects for the first time
    glutDisplayFunc(&display);
    //displays the objects(updates)
    glutIdleFunc(&display);
    //Handle Keyboard input;
    glutKeyboardFunc(&Keyinput);
    
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 90.0f,1, 0.1f, 100.0f);
    
    
  //main loop
  glutMainLoop();
    
}

