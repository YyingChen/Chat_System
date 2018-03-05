#ifndef _LOG_H_
#define _LOG_H_

#define NORMAL 0
#define NOTICE 1
#define WARNING 2
#define FATAL 3

#include<iostream>
#include<string>

void print_log(std::string msg,int _level);

#endif
