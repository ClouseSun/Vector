//
//  DisplayManager.hpp
//  Vector
//
//  Created by ClouseSun on 16/3/7.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#ifndef DisplayManager_hpp
#define DisplayManager_hpp

#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include "CVector3.hpp"
#include <vector>

/* DisplayManager -- display vector user input from cmdline in various perspective */

class DisplayManager
{
    static std::vector <CVector3> vec; /* store input and result vectors, maybe 2 or 3. */
    static float mspeed; /* move step each key press */
    static float rspeed; /* rotate angle each key press */
    static float mx,my,mz; /* x/y/z component of the vector offset from origion */
    static float rx,ry,rz; /* rotation angle from X/Y/Z axis , */
    static float sx,sy,sz; /* x/y/z scale component */
    
public:
    
    DisplayManager();
    
    /*
     *  Reset viewport when window size changed
     */
    
    static void ChangeSize(int w, int h);
    
    /*
     *  Initialize the rendering context
     */
    
    void SetupRC();
    
    /*
     *  Receive keyboard input to change view
     */
    
    static void KeyboardFunc(unsigned char key,int x, int y);
    
    /*
     *  Called to draw axis and vectors
     */
    
    static void RenderScene(void);
    
    /*
     *  Called to draw axis and vectors
     */
    
    static void TimeFunc(int val);
    
    /*
     *  Main depicting func
     */
    
    void Show(int argc, char* argv[]);
    
    /*
     *  Push vector
     */
    
    void PushCVector3(CVector3 cv3);
    
    /*
     *  Get no.i vector
     */
    
    CVector3 GetVector(int i);
    
};

#endif /* DisplayManager_hpp */
