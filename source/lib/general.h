#ifndef __GENERAL_HPP__
#define __GENERAL_HPP__

#include <iostream>
#include <map>
#include <cassert>
#include <cstring>
using namespace std;


typedef unsigned int uint;
typedef unsigned int identifier;// Variable and function name ID

inline string char2string(char ch)
{
          char tmp[2] = { ch, '\0' };
                  return string(tmp);
}


#endif // __GENERAL_HPP__
