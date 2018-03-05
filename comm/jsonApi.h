#ifndef _JSONAPI_H_
#define _JSONAPI_H_

#include<iostream>
#include<string>
#include "json/json.h"
class jsonApi{
    public:
        jsonApi();
        ~jsonApi();
        static int serialize(const Json::Value &val,std::string &outstring);
        //序列化
        static int deSerialize(std::string &inString,Json::Value &val);//反序列化
};

#endif
