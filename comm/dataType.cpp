#include "dataType.h"

int dataType::stringToValue(std::string &inString)
{
    Json::Value v;
    jsonApi::deSerialize(inString,v);
    nick_name=v["nick_name"].asString();
    school=v["school"].asString();
    msg=v["msg"].asString();
    cmd=v["cmd"].asString();//什么时候将用户删掉
    return 0;
}
int dataType::valueToString(std::string &outString)
{
     Json::Value v;
     v["nick_name"]=nick_name;
     v["school"]=school;
     v["msg"]=msg;
     v["cmd"]=cmd;

     return jsonApi::serialize(v,outString);
}

