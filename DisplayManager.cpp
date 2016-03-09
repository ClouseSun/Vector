//
//  DisplayManager.cpp
//  Vector
//
//  Created by ClouseSun on 16/3/7.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#include "DisplayManager.hpp"

std::vector <CVector3> DisplayManager::vec;
float DisplayManager::mspeed;
float DisplayManager::rspeed;
float DisplayManager::mx;
float DisplayManager::my;
float DisplayManager::mz;
float DisplayManager::rx;
float DisplayManager::ry;
float DisplayManager::rz;
float DisplayManager::sx;
float DisplayManager::sy;
float DisplayManager::sz;

DisplayManager::DisplayManager()
{
    std::vector <CVector3> sv;
    vec = sv;
    mspeed = 0.1f;
    rspeed = 0.1f;
    mx = my = -1.2f;
    mz = -8.6f;
    rx = ry = rz = 0;
    sx = sy = sz = 1.0f;
}

void DisplayManager::TimeFunc(int val)
{
    DisplayManager::RenderScene();
    glutTimerFunc(1, TimeFunc, 0);
}

void DisplayManager::ChangeSize(int w, int h)
{
    GLfloat nRange = 5.0f;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,GLfloat(w)/h,1,1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();}

void DisplayManager::SetupRC()
{
    //glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glShadeModel(GL_FLAT);
    glFrontFace(GL_CCW);
    glEnable(GL_DEPTH_TEST);
    glPolygonMode(GL_BACK,GL_LINE);
}

void DisplayManager::RenderScene(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    //gluLookAt(6.0f, 4.0f, 3.0f, 0, 0, 0, 0, 1, 0);
    
    glPushMatrix();
    glTranslatef(mx, my, mz);
    glRotatef(rz, 0, 0, 1);
    glRotatef(rx, 1, 0, 0);
    glRotatef(ry, 0, 1, 0);
    glScalef(sx, sy, sz);
    
    glLineWidth(3.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(5.0f, 0.0f, 0.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(5.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.0f, 5.0f, 0.0f);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 5.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 5.0f);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
    glLineWidth(1.0f);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i = 0; i < vec.size();i++)
    {
        glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f((GLfloat)vec[i].GetX(),(GLfloat)vec[i].GetY(),(GLfloat)vec[i].GetZ());
        glEnd();
    }
    glPopMatrix();
    glutSwapBuffers();
    
}
void DisplayManager::KeyboardFunc(unsigned char key,int x, int y)
{
    switch(key)
    {
        case 'w':
            my -= mspeed;
            break;
        case 's':
            my += mspeed;
            break;
        case 'a':
            mx += mspeed;
            break;
        case 'd':
            mx -= mspeed;
            break;
        case 'q':
            mz += mspeed;
            break;
        case 'e':
            mz -= mspeed;
            break;
        case 'i':
            rx += rspeed;
            break;
        case 'k':
            rx-=rspeed;
            break;
        case 'j':
            ry-=rspeed;
            break;
        case 'l':
            ry+=rspeed;
            break;
        case 'u':
            rz+=rspeed;
            break;
        case 'o':
            rz-=rspeed;
            break;
        case '1':
            sx+=0.1;
            break;
        case '2':
            sx-=0.1;
            break;
        case '3':
            sy+=0.1;
            break;
        case '4':
            sy-=0.1;
            break;
        case '5':
            sz+=0.1;
            break;
        case '6':
            sz-=0.1;
            break;
    }
}

void DisplayManager::Show(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Display");
    glutDisplayFunc(DisplayManager::RenderScene);
    glutTimerFunc(1, TimeFunc, 0);
    glutReshapeFunc(DisplayManager::ChangeSize);
    glutKeyboardFunc(DisplayManager::KeyboardFunc);
    SetupRC();
    glutMainLoop();
}

void DisplayManager::PushCVector3(CVector3 cv3)
{
    this->vec.push_back(cv3);
}

CVector3 DisplayManager::GetVector(int i)
{
    return vec[i];
}