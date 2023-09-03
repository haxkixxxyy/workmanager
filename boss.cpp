#include"boss.h"

void Boss::ShowInfo(){
    Worker::ShowInfo();
    cout<<"岗位职责:给经理任务"<<"\t"
        <<"岗位:"<<GetDeptName()<<endl;
}

string Boss::GetDeptName(){
    return string("老板");
}