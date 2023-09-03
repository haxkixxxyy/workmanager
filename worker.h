#pragma once //ְ���������
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
        cout<<"����:"<<name<<"\t"
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