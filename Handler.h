/* 
 * File:   Handler.h
 * Author: brunt
 *
 * Created on 21 April 2013, 9:54 PM
 */

#ifndef HANDLER_H
#define	HANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
    //initial values
    enum {X,Y,Z} axis;
    float moveUnit=0.1;
    float tempX,tempY,tempZ;
    float currentX=0.0;
    float currentY=0.0;
    float currentZ=0.0;
    float rotX=0.0;
    float rotY=0.0;
    float rotZ=0.0;
    
    void reset(){
   
    currentX=0.0;
     currentY=0.0;
     currentZ=0.0;
     rotX=0.0;
     rotY=0.0;
     rotZ=0.0;
    }
    
    //move the teapot (on keyboard command)
    void move(int direction){
        //1 is right, 2 up, 3 left, 4 down;
        switch (axis){
            case X:
                switch (direction){
                    case 1:
                        currentX+=moveUnit;
                        tempX=currentX;
                        break;
                    case 2:
                        rotX--;                        
                        break;
                    case 3:
                        currentX-=moveUnit;
                        tempX=currentX;
                        break;
                    case 4:
                        rotX++;
                        break;  
                }
                break;
            case Y:
                switch (direction){
                    case 1:
                        currentY+=moveUnit;
                        tempY=currentY;
                        break;
                    case 2:
                        rotY--;                        
                        break;
                    case 3:
                        currentY-=moveUnit;
                        tempY=currentY;
                        break;
                    case 4:
                        rotY++;
                        break;  
                }
                break;
                
             case Z:
                switch (direction){
                    case 1:
                        currentZ+=moveUnit;
                        tempZ=currentZ;
                        break;
                    case 2:
                        rotZ--;                        
                        break;
                    case 3:
                        currentZ-=moveUnit;
                        tempZ=currentZ;
                        break;
                    case 4:
                        rotZ++;
                        break;  
                }
                break;
        }
    }
    
    void toggle(){
        axis = (axis==X)?Y:(axis==Y)?Z:X;
    }
    
    void drawLocAxis(){
        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        //X axis
        glColor3f(0.5, 0.5, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0.5, 0, 0);
        //y axis
        glColor3f(0, 0.5, 0.5);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0.5, 0);
        //z axis
        glColor3f(0.5, 0, 0.5);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 0.5);

        glEnd();
        glEnable(GL_LIGHTING);
    }
    
    void drawMinAxis(){

        glDisable(GL_LIGHTING);
        glBegin(GL_LINES);
        if (axis==X){
        //X axis
        glColor3f(1.0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(3, 0, 0);
        }else if(axis==Y){
            //y axis
        glColor3f(1.0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 3, 0);
        }else{
        //z axis
        glColor3f(1.0, 1.0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, 3);
        }
        glEnd();
        glEnable(GL_LIGHTING);
    }
   
    
    void drawTeapot(){
    glTranslatef(currentX,currentY,currentZ);//move teapot relative to global axis
    drawMinAxis();//draw local axis*
    
    glRotatef(rotX,1,0,0);//rotate relative to local axis
    glRotatef(rotY,0,1,0);//rotate relative to local axis
    glRotatef(rotZ,0,0,1);//rotate relative to local axis
    drawMinAxis();
    
    drawLocAxis();
    
    glColor3f(1.0f,0.5f,0.0f);
    glutSolidTeapot(2);

    //currentX=0;currentY=0;currentZ=0;
    //rotX=0;rotY=0;rotZ=0;
    }



#ifdef	__cplusplus
}
#endif

#endif	/* HANDLER_H */

