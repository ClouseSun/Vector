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

int main(int argc, char * argv[])
{
    CmdlineParser clp;
    string cmd;
    std::getline(std::cin,cmd);
    clp.ParserVector(cmd);
    clp.Run(argc, argv);
}
