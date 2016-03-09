//
//  DisplayManager.cpp
//  Vector
//
//  Created by ClouseSun on 16/3/7.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#include "DisplayManager.hpp"

std::vector <CVector3> DisplayManager::vec;

DisplayManager::DisplayManager()
{
    std::vector <CVector3> sv;
    vec = sv;
}


void DisplayManager::ChangeSize(int w, int h)
{
    GLfloat nRange = 1.0f;
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glOrtho(-nRange,nRange,-nRange*h/w,nRange*h/w,-100,100);
    else
        glOrtho(-nRange*w/h,nRange*w/h,-nRange,nRange,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void DisplayManager::SetupRC()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void DisplayManager::RenderScene(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    gluLookAt(60.0f, 40.0f, 30.0f, 0, 0, 0, 0, 1, 0);
    
    glLineWidth(3.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutWireCone(0.027, 0.09, 10, 10);
    glPopMatrix();
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0.0f);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glutWireCone(0.027, 0.09, 10, 10);
    glPopMatrix();
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 1.0f);
    glEnd();
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 1.0f);
    glutWireCone(0.027, 0.09, 10, 10);
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
    
    glFlush();
}

void DisplayManager::Show(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Display");
    glutDisplayFunc(DisplayManager::RenderScene);
    glutReshapeFunc(DisplayManager::ChangeSize);
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