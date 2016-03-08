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
public:
    
    static std::vector <CVector3> vec; /* store input and result vectors, maybe 2 or 3. */

    DisplayManager();
    
    /*
     *  reset viewport when window size changed
     */
    
    static void ChangeSize(int w, int h);
    
    /*
     *  initialize the rendering context
     */
    
    void SetupRC();
    
    /*
     *  called to draw axis and vectors
     */
    
    static void RenderScene(void);
    
    /*
     *  main depicting func
     */
    
    void Show(int argc, char* argv[]);
    
};

#endif /* DisplayManager_hpp */
