#include"manager.h"

void Manager::ShowInfo(){
    Worker::ShowInfo();
    cout<<"岗位职责:完成老板的任务,给员工任务"<<"\t"
        <<"岗位:"<<GetDeptName()<<endl;
}

string Manager::GetDeptName(){
    return string("经理");
}