//
//  CVector3.hpp
//  Vector
//
//  Created by ClouseSun on 16/3/7.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#ifndef CVector3_h
#define CVector3_h

#include <iostream>
#include <math.h>

/* CVector3 -- 3 dimensional vector class */

extern const float eps = 1e-6; /* set desired precision */

class CVector3
{
    float x; /* X-coordinate of the vector */
    float y; /* Y-coordinate of the vector */
    float z; /* Z-coordinate of the vector */
    
public:
    
    /*
     *  default constructor
     */
    
    CVector3();
    
    /*
     *  constructor with 3 coordinates
     *  Parameters:
     *      sx : X-coordinate of the vector
     *      sy : Y-coordinate of the vector
     *      sz : Z-coordinate of the vector
     */
    
    CVector3(float sx,float sy,float sz);
    
    /*
     *  copy constructor
     */
    
    CVector3(const CVector3 &src);
    
    /*
     *  destructor
     */
    
    ~CVector3();
    
    /*
     *  return x,y,z coordinate of the vector
     */
    
    float GetX();
    float GetY();
    float GetZ();
    
    /*
     *  reset vector
     */
    
    void Set(float sx, float sy, float sz);
    
    /*
     *  return length of the vector
     */
    
    float GetLength();
    
    /*
     *  +，-，=, *, / operator overloading of the vector
     */
    
    void operator = (const CVector3 &src);
    CVector3 operator + (const CVector3 &src);
    CVector3 operator - (const CVector3 &src);
    CVector3 operator * (float scale);
    CVector3 operator / (float scale);
    
    /*
     *  return the result of dotproduct with source vector
     */
    
    float DotProduct(const CVector3 &src);
    
    /*
     *  return the result vector of crossproduct with source vector
     */
    
    CVector3 CrossProduct(const CVector3 &src);
    
    /*
     *  inverse the vector
     */
    
    void Inverse();
    
    /*
     *  normalize the vector
     */
    
    void Normalize();
    
    /*
     *  output the vector in the form of (x,y,z)
     */
    
    void Output();
    
    /*
     *  project vector on dest vector
     *      return : projection
     */
    
    CVector3 Project(CVector3 &des);
};

#endif /* CVector3_h */
