//
//  DisplayManager.cpp
//  Vector
//
//  Created by 孙云霄 on 16/3/7.
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
    glViewport(0, 0, w, h);
}

void DisplayManager::SetupRC()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

void DisplayManager::RenderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

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
    std::vector<CVector3>::iterator it;
    for(it = vec.begin() ; it!=vec.end() ; it++)
    {
        glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f((GLfloat)it->GetX(),(GLfloat)it->GetY(),(GLfloat)it->GetZ());
        glEnd();
    }
    
    glFlush();
}

void DisplayManager::Show(int argc, char* argv[])
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Display");
    glutReshapeFunc(DisplayManager::ChangeSize);
    glutDisplayFunc(DisplayManager::RenderScene);
    SetupRC();
    glutMainLoop();
}