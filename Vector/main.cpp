//
//  main.cpp
//  Vector
//
//  Created by ClouseSun on 16/3/7.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#include <iostream>
#include "CmdlineParser.hpp"
using namespace std;

int main(int argc, const char * argv[])
{
    CmdlineParser clp;
    string cmd;
    cin >> cmd;
    clp.ParserVector(cmd);
    
}
