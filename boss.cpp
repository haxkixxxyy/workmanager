#include"boss.h"

void Boss::ShowInfo(){
    Worker::ShowInfo();
    cout<<"��λְ��:����������"<<"\t"
        <<"��λ:"<<GetDeptName()<<endl;
}

string Boss::GetDeptName(){
    return string("�ϰ�");
}