#pragma once //职工纯虚基类
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Worker{
private:
    string name;
    int Id;
    int Did;
public:
    Worker(string _name,int _id,int _did):name(_name),Id(_id),Did(_did){};
    virtual void ShowInfo(){
        cout<<"姓名:"<<name<<"\t"
            <<"id:"<<Id<<"\t"
            <<"Did:"<<Did<<"\t";            
    };
    virtual string GetDeptName()=0;
    void SaveInfo(ofstream &os){
        os<<name<<"\t"
            <<Id<<"\t"
            <<Did<<"\n";           
    }
    int GetId(){
        return Id;
    }
    string GetName(){
        return name;
    }
};