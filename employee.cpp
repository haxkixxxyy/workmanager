#include"employee.h"

void Employee::ShowInfo(){
    Worker::ShowInfo();
    cout<<"��λְ��:��ɾ�������"<<"\t"
        <<"��λ:"<<GetDeptName()<<endl;
}

string Employee::GetDeptName(){
    return string("Ա��");
}