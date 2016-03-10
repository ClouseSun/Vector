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
extern const float eps;

DisplayManager::DisplayManager()
{
    std::vector <CVector3> sv;
    vec = sv;
    mspeed = 1.0f;
    rspeed = 1.0f;
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
    
    glPushMatrix();
    glTranslatef(mx, my, mz);
    glRotatef(rz, 0, 0, 1);
    glRotatef(rx, 1, 0, 0);
    glRotatef(ry, 0, 1, 0);
    glScalef(sx, sy, sz);
    
    DrawAxis(5.0f, 3.0f, true, true, 1.0f);
    DrawVector3(2.0f, false);
    
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
            rx -= rspeed;
            break;
        case 'j':
            ry -= rspeed;
            break;
        case 'l':
            ry += rspeed;
            break;
        case 'u':
            rz += rspeed;
            break;
        case 'o':
            rz -= rspeed;
            break;
        case '1':
            sx += 0.1;
            break;
        case '2':
            sx -= 0.1;
            break;
        case '3':
            sy += 0.1;
            break;
        case '4':
            sy -= 0.1;
            break;
        case '5':
            sz += 0.1;
            break;
        case '6':
            sz -= 0.1;
            break;
        case 'z':
            mz = -10.0f;
            mx = my = 0.0f;
            ry = -90;
            rx = rz = 0;
            break;
        case 'x':
            mz = -10.0f;
            mx = my = 0.0f;
            rx = 90;
            ry = rz = 0;
            break;
        case 'c':
            mz = -10.0f;
            mx = my = 0.0f;
            rx = ry = 0;
            rz = 0;
            break;
        case 'r':
            mx = my = -1.2f;
            mz = -8.6f;
            rx = ry = rz = 0;
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

void DisplayManager::DrawAxis(GLfloat len, GLfloat width, bool coloring, bool label, GLfloat scale)
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(width);
    
    if(label)
    {
        char Xlabel[2] = "X";
        show_text(Xlabel, len, 0.2f, 0.0f, 254, 0, 0);
        char Ylabel[2] = "Y";
        show_text(Ylabel, 0.0f, len+0.2, 0.3f, 0, 254, 0);
        char Zlabel[2] = "Z";
        show_text(Zlabel, 0.0f, 0.2f, len, 0, 0, 254);
    }
    
    if(coloring)
        glColor3f(1.0f, 0.0f, 0.0f);
    
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(len, 0.0f, 0.0f);
    glEnd();
    
    
    if(scale >= 0)
    {
        int num = len / scale;
        for(int i = 1;i <= num;i++)
        {
            glBegin(GL_LINES);
            glVertex3f(i * scale, 0.0f, 0.0f);
            glVertex3f(i * scale, 0.1f, 0.0f);
            glVertex3f(i * scale, 0.0f, 0.0f);
            glVertex3f(i * scale, 0.0f, 0.1f);
            glEnd();
        }
    }
    
    glPushMatrix();
    glTranslatef(len, 0.0f, 0.0f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
    if(coloring)
        glColor3f(0.0f, 1.0f, 0.0f);
    
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, len, 0.0f);
    glEnd();
    
    if(scale >= 0)
    {
        int num = len / scale;
        for(int i = 1;i <= num;i++)
        {
            glBegin(GL_LINES);
            glVertex3f(0.0f, i * scale, 0.0f);
            glVertex3f(0.1f, i * scale, 0.0f);
            glVertex3f(0.0f, i * scale, 0.0f);
            glVertex3f(0.0f, i * scale, 0.1f);
            glEnd();
        }
    }
    
    glPushMatrix();
    glTranslatef(0.0f, len, 0.0f);
    glRotatef(90.0f, -1.0f, 0.0f, 0.0f);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
    if(coloring)
        glColor3f(0.0f, 0.0f, 1.0f);
    
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, len);
    glEnd();
    
    if(scale >= 0)
    {
        int num = len / scale;
        for(int i = 1;i <= num;i++)
        {
            glBegin(GL_LINES);
            glVertex3f(0.0f, 0.0f, i * scale);
            glVertex3f(0.1f, 0.0f, i * scale);
            glVertex3f(0.0f, 0.0f, i * scale);
            glVertex3f(0.0f, 0.1f, i * scale);
            glEnd();
        }
    }
    
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, len);
    glutWireCone(0.09, 0.3, 10, 10);
    glPopMatrix();
    
}

void DisplayManager::DrawVector3(GLfloat width, bool coloring)
{
    glLineWidth(width);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i = 0; i < vec.size();i++)
    {
        if(coloring)
        {
            if(i == 0)
                glColor3f(1.0f, 0.0f, 1.0f);
            if(i == 1)
                glColor3f(0.0f, 1.0f, 1.0f);
            if(i == 2)
                glColor3f(1.0f, 1.0f, 0.0f);
        }
        else if (i == 2)
        {
            glColor3f(1.0f, 0.0f, 1.0f);
        }
        
        glBegin(GL_LINES);
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f((GLfloat)vec[i].GetX(),(GLfloat)vec[i].GetY(),(GLfloat)vec[i].GetZ());
        glEnd();
    }
}

void DisplayManager::show_text(char *text_toshow, double x, double y, double z, float R, float G, float B)
{
    /* There are 7 bitmap fonts available in GLUT.
     GLUT_BITMAP_8_BY_13
     GLUT_BITMAP_9_BY_15
     GLUT_BITMAP_TIMES_ROMAN_10
     GLUT_BITMAP_TIMES_ROMAN_24
     GLUT_BITMAP_HELVETICA_10
     GLUT_BITMAP_HELVETICA_12
     GLUT_BITMAP_HELVETICA_18 */
    
    void* font = GLUT_BITMAP_HELVETICA_18;
    glColor3f(R, G, B);
    glRasterPos3f(x, y, z);
    
    for(int i = 0; i<=strlen(text_toshow); i++)
    {
        char c = text_toshow[i];
        glutBitmapCharacter(font, c);
    }
    
}