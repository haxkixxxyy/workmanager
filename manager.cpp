#include"manager.h"

void Manager::ShowInfo(){
    Worker::ShowInfo();
    cout<<"��λְ��:����ϰ������,��Ա������"<<"\t"
        <<"��λ:"<<GetDeptName()<<endl;
}

string Manager::GetDeptName(){
    return string("����");
}