/* 
 * File:   Attributes.h
 * Author: brunt
 *
 * Created on 21 April 2013, 2:45 PM
 */

#ifndef ATTRIBUTES_H
#define	ATTRIBUTES_H

#include "Handler.h"
#include <iostream>

#ifdef	__cplusplus
extern "C" {
#endif
    
    
    float axisLength = 5;
    float camRotX =0.0f;
    float camRotY = 0.0f;
    float camRotZ = 0.0f;
    float camDist = 5.0f;
    
    //draws global Axis
    void drawGlobAxis() {
        //disable Lighting
       
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        //X axis
        glColor3f(1.0, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(axisLength, 0, 0);
        //y axis
        glColor3f(0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, axisLength, 0);
        //z axis
        glColor3f(0, 0, 1.0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, axisLength);

        glEnd();

        //re enable lighting
        //glEnable(GL_LIGHTING);

    }

    //Manages key input
    void Keyinput(unsigned char key, int mousePos_x, int mousePos_y) {
       
        switch (key) {
            case 27://exit button pressed
                exit(0);
                break;
            case '6'://numpad 6 pressed (Camera rotate right)
                --camRotY;
                break;
            case '4'://numpad 4 pressed (Camera rotate left)
                ++camRotY;
                break;
            case '8'://numpad 8 pressed (Camera rotate up)
                ++camRotX;
                break;
                
            case '2'://numpad 2 pressed (Camera rotate down)
                --camRotX;
                break;
            
            case '5'://numpad 2 pressed (Camera rotate down)
                camRotX=0; camRotY=0; camRotZ=0;camDist =5.0f;
                break;
            case '+'://numpad + Zoom in
                camDist-=0.25;
                break;
            case '-'://numpad + Zoom out
                camDist+=0.25;
                break;
            case 'd':
                //std::cout<<"test"<<std::endl;
                move(1);                
                break;
            case 'w':
                //std::cout<<"test"<<std::endl;
                move(2);                
                break;
            case 'a':
                //std::cout<<"test"<<std::endl;
                move(3);                
                break;
            case 's':
                //std::cout<<"test"<<std::endl;
                move(4);                
                break;
            case ' ':
                //std::cout<<"test"<<std::endl;
                toggle();               
                break;
            case 'r':
                reset();
                break;
                
            default:
                break;
        }
    };
    
    //rotates the camera
    void rotateCamera(){
        
        glRotatef(camRotX,1,0,0);
        glRotatef(camRotY,0,1,0);
        glRotatef(camRotZ,0,0,1);
   
    }


#ifdef	__cplusplus
}
#endif

#endif	/* ATTRIBUTES_H */

