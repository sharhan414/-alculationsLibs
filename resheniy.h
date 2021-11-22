#ifndef RESHENIY_H
#define RESHENIY_H

#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <iterator>

class Resheniy
{
public:
    Resheniy();
    bool isError(){
    return !error;
       }
    static std::string to_stdString(double);
    static double stdString_toDouble(std::string strValues);
    template<class Str>
    static void InsertNewSingExp(Str &text,Str Sign, Str newSign);
protected:
    std::string SearchBeginText(std::string&,std::string::iterator&,std::string::iterator&) ;
    std::string SearchEndText(std::string&,std::string,std::string::iterator&,std::string::iterator&) ;
    bool error=true;
    const std::string UserChars = "0123456789.";
};

#endif // RESHENIY_H
