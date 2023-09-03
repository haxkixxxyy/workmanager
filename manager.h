#pragma once
#include"worker.h"
class Manager: public Worker
{
public:
    Manager(string _name,int _id,int _did):Worker(_name,_id,_did){}
    virtual void ShowInfo();
    virtual string GetDeptName();        
};