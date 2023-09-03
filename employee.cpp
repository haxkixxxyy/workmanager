#include"employee.h"

void Employee::ShowInfo(){
    Worker::ShowInfo();
    cout<<"岗位职责:完成经理任务"<<"\t"
        <<"岗位:"<<GetDeptName()<<endl;
}

string Employee::GetDeptName(){
    return string("员工");
}