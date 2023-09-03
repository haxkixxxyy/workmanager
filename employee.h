#pragma once
#include"worker.h"
class Employee: public Worker
{
public:
    Employee(string _name,int _id,int _did):Worker(_name,_id,_did){}
    virtual void ShowInfo();
    virtual string GetDeptName();        
};