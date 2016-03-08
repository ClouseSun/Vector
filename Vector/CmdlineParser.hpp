//
//  CmdlineParser.hpp
//  Vector
//
//  Created by ClouseSun on 16/3/8.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#ifndef CmdlineParser_hpp
#define CmdlineParser_hpp

#include <string>
#include <stdlib.h>
#include "DisplayManager.hpp"
#include "CVector3.hpp"

/* The command line parser class parses options and parameters user gives to calculate and display.*/

class CmdlineParser
{
    DisplayManager *_displaymanager;/* ptr to displaymanager instance which it will update based on the vector user give */
    
public:
    
    CmdlineParser();
    
    /*
     * Parse given cmdlines
     * return true if cmdline was valid, false if there was an error
     */
    
    bool ParserVector(const std::string &cmd);
    
    void Run(int argc, char* argv[]);
    
protected:
    
    static std::vector<std::string> Split(std::string str, std::string pattern);
    
    /*
     * Print help text to console
     */
    
    static void PrintHelp();
    
    /*
     * Print help text to : (console at present)
     */
    
    static void PrintMsg(const std::string &msg);
    

};

#endif /* CmdlineParser_hpp */
