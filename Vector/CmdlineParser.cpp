//
//  CmdlineParser.cpp
//  Vector
//
//  Created by ClouseSun on 16/3/8.
//  Copyright © 2016年 ClouseSun. All rights reserved.
//

#include "CmdlineParser.hpp"

CmdlineParser::CmdlineParser()
{
    _displaymanager = new DisplayManager();
}

std::vector<std::string> CmdlineParser::Split(std::string str, std::string pattern)
{
    std::string::size_type pos;
    std::vector<std::string> result;
    str += pattern;
    int size = (int)str.size();
    
    for(int i = 0; i < size; i++)
    {
        pos = str.find(pattern,i);
        if(pos < size)
        {
            std::string s = str.substr(i, pos - i);
            result.push_back(s);
            i = (int)(pos + pattern.size() - 1);
        }
    }
    return result;
}

bool CmdlineParser::ParserVector(const std::string &cmd)
{
    std::vector<std::string> cmdline = CmdlineParser::Split(cmd , " ");
    int mark = -1;
    
    for (int i = 0; i < cmdline.size(); i++)
    {
        if(std::strcmp(cmdline[i].c_str(), "-help") == 0)
        {
            CmdlineParser::PrintHelp();
            return true;
        }
        
        std::string str = cmdline[i].substr(cmdline[i].find("(") + 1 , cmdline[i].find(")") - cmdline[i].find("(") - 1);
        std::vector<std::string> vector = CmdlineParser::Split(str , ",");
        if(vector.size() == 3)
        {
            float x,y,z;
            x = atoi(vector[0].c_str());
            y = atoi(vector[1].c_str());
            z = atoi(vector[2].c_str());
        
            _displaymanager->PushCVector3(CVector3(x,y,z));
        }
        
        if(std::strcmp(cmdline[i].c_str(), "+") == 0)
        {
            mark = 1;
        }
        if(std::strcmp(cmdline[i].c_str(), "-") == 0)
        {
            mark = 2;
        }
        if(std::strcmp(cmdline[i].c_str(), ".") == 0)
        {
            mark = 3;
        }
        if(std::strcmp(cmdline[i].c_str(), "*") == 0)
        {
            mark = 4;
        }
    }
    if(1 == mark)
    {
        CVector3 cv3(_displaymanager->GetVector(0) + _displaymanager->GetVector(1));
        _displaymanager->PushCVector3(cv3);
        std::string msg = "The result is ";
        cv3.Output();
    }
    if(2 == mark)
    {
        CVector3 cv3(_displaymanager->GetVector(0) + _displaymanager->GetVector(1));
        _displaymanager->PushCVector3(cv3);
        std::string msg = "The result is ";
        cv3.Output();
    }
    if(3 == mark)
    {
        std::string msg = "The result of DotProduct is ";
        std::string res;
        gcvt(_displaymanager->GetVector(0).DotProduct(_displaymanager->GetVector(1)), 7, (char *)res.c_str());
        CmdlineParser::PrintMsg(msg + res);
    }
    if(4 == mark)
    {
        CVector3 cv3(_displaymanager->GetVector(0).CrossProduct(_displaymanager->GetVector(1)));
        _displaymanager->PushCVector3(cv3);
        std::string msg = "The result is ";
        cv3.Output();
    }
    
    
    
    return true;
}

void CmdlineParser::PrintHelp()
{
    
    return;
}

void CmdlineParser::PrintMsg(const std::string &msg)
{
    std::cout << msg << std::endl;
    return;
}

void CmdlineParser::Run(int argc, char ** argv)
{
    _displaymanager->Show(argc, argv);
}