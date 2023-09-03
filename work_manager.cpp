#include"work_manager.h"

WorkManager::WorkManager()
{
    ifstream is;
    is.open(FILENAME);
    if(!is.is_open()){
        cout<<"文件不存在"<<endl;
        EmpNum=0;
        EmpArray.clear();
        FileIsEmpty=true;
        is.close();
        return;      
    }
    is.get();
    if(is.eof()){
        cout<<"文件为空"<<endl;
        EmpNum=0;
        EmpArray.clear();
        FileIsEmpty=true;
        is.close();
        return;     
    }
    is.close();
    is.open(FILENAME);
    InitEmp(is);
    FileIsEmpty=false;
    //测试
    // for(int i=0;i<EmpNum;i++){
    //     EmpArray[i]->ShowInfo();
    // } 
}

WorkManager::~WorkManager()
{
    for(int i=0;i<EmpNum;i++){
        delete EmpArray[i];
    }
    EmpArray.clear();
}

void WorkManager::ShowMenu(){
    cout << "**********************************" << endl;
    cout << "********* 0.退出管理程序 *********" << endl;    
    cout << "********* 1.添加职工信息 *********" << endl;
    cout << "********* 2.显示职工信息 *********" << endl;
    cout << "********* 3.删除离职职工 *********" << endl;
    cout << "********* 4.修改职工信息 *********" << endl;    
    cout << "********* 5.查找职工信息 *********" << endl;
    cout << "********* 6.按照编号排序 *********" << endl;     
    cout << "********* 7.清空所有文档 *********" << endl;
    cout << "**********************************" << endl;
}

void WorkManager::ExitSysterm(){
    cout<<"欢迎下次使用";
    exit(EXIT_FAILURE);
}

void WorkManager::AddEmp(){
    int num;
    string _name;
    int _id,_did;
    Worker* temp;
    int i=0;
    cout<<"请输入要添加的人数:\n";
    cin>>num;
    if(num<=0){
        cout<<"输入错误!\n";
    }
    else{
        while (i<num)
        {   
            cout<<"请输入第"<<i+1<<"位职员的信息"<<endl;
            cout<<"请输入姓名:\n";
            cin>>_name;
            cout<<"请输入id:\n";
            cin>>_id;
            cout<<"请输入岗位:(1为员工,2为经理,3为老板)\n";
            cin>>_did;
            switch (_did)
            {
            case 1:
                temp=new Employee(_name,_id,_did);
                EmpArray.push_back(temp);
                break;
            case 2:
                temp=new Manager(_name,_id,_did);
                EmpArray.push_back(temp);
                break; 
            case 3:
                temp=new Boss(_name,_id,_did);
                EmpArray.push_back(temp);
                break;                 
            default:
                cout<<"输入错误!\n";
                cout<<"请重新输入\n";
                i--;
                break;
            }
            i++;
        }
        EmpNum+=num;
        cout<<"成功添加"<<num<<"位员工"<<endl;
        FileIsEmpty=false;
        SaveEmp();
    }
}

//保存职工信息表
void WorkManager::SaveEmp(){
    ofstream os;
    os.open(FILENAME);
    for(int i=0;i<EmpNum;i++){
        EmpArray[i]->SaveInfo(os);
    }
}

//初始化职工信息表
void WorkManager::InitEmp(ifstream &is){
    int num=0;
    string _name;
    int _id,_did;
    Worker *temp;
    while(is>>_name&&is>>_id&&is>>_did){
        num++;
        switch (_did)
        {
        case 1:
            temp=new Employee(_name,_id,_did);
            EmpArray.push_back(temp);
            break;
        case 2:
            temp=new Manager(_name,_id,_did);
            EmpArray.push_back(temp);
            break;  
        case 3:
            temp=new Boss(_name,_id,_did);
            EmpArray.push_back(temp);
            break;      
        default:
            break;
        }
    }
    EmpNum=num;
}

void WorkManager::ShowAllEmp(){
    if(FileIsEmpty){
        cout<<"无任何职工信息\n";
    }
    else{
        for(int i=0;i<EmpNum;i++){
            EmpArray[i]->ShowInfo();
        }
    }
}

int WorkManager::IsExist(int _id){
    for(int i=0;i<EmpNum;i++){
        if(EmpArray[i]->GetId()==_id) return i;
    }
    return -1;
}

void WorkManager::DelEmp(){
    if(FileIsEmpty){
        cout<<"文件为空或者记录不存在\n";
        return;
    }
    int _id;
    cout<<"输入需要删除职工的id:"<<endl;
    cin>>_id;
    int temp=IsExist(_id);
    if(temp==-1){
        cout<<"对应职工不存在!\n";
    }
    else{
        delete EmpArray[temp];
        EmpArray.erase(EmpArray.begin()+temp);
        cout<<"删除成功!\n";
        EmpNum--;
        if(EmpNum==0) FileIsEmpty=true;
        SaveEmp();
    }
}

void WorkManager::ModEmp(){
    if(FileIsEmpty){
        cout<<"文件为空或者记录不存在\n";
        return;
    }
    int _id;
    cout<<"请输入id:\n";
    cin>>_id;
    int temp=IsExist(_id);
    if(temp==-1){
        cout<<"对应员工不存在\n";
        return;
    }
    cout<<"该员工信息如下:\n";
    EmpArray[temp]->ShowInfo();
    string _name;
    int _did;
    cout<<"请输入姓名:\n";
    cin>>_name;
    cout<<"请输入岗位:(1为员工,2为经理,3为老板)\n";
    cin>>_did;
    while(_did!=1&&_did!=2&&_did!=3){
        cout<<"输入有误,请重新输入:(1为员工,2为经理,3为老板)\n";
        cin>>_did;
    }
    delete EmpArray[temp];
    EmpArray.erase(EmpArray.begin()+temp);
    Worker* _temp;
    switch (_did)
    {
    case 1:
        _temp=new Employee(_name,_id,_did);
        EmpArray.push_back(_temp);
        break;
    case 2:
        _temp=new Manager(_name,_id,_did);
        EmpArray.push_back(_temp);
        break; 
    case 3:
        _temp=new Boss(_name,_id,_did);
        EmpArray.push_back(_temp);
        break;                 
    default:
        break;
    }
    SaveEmp();
    cout<<"修改成功!\n";
    return;
}

vector<int> WorkManager::FindByName(string _name){
    vector<int> temp;
    for(int i=0;i<EmpNum;i++){
        if(EmpArray[i]->GetName()==_name){
            temp.push_back(i);
        }
    }
    return temp;
}

void WorkManager::FindEmp(){
    if(FileIsEmpty){
        cout<<"文件为空或者记录不存在\n";
        return;
    }
    int flag=false;
    int way;
    cout<<"请输入查找的方式:\n"
        <<"1为按姓名查找\n"
        <<"2为按Id查找\n";
    cin>>way;
    while(way!=1&&way!=2){
        cout<<"方式输入错误,请重新输入:\n";
        cin>>way;
    }
    if(way==1){
        string _name;
        cout<<"请输入姓名:\n";
        cin>>_name;
        vector<int> person=FindByName(_name);
        if(person.size()!=0) flag=true;
        for(auto x:person){
            EmpArray[x]->ShowInfo();
        }
    }
    if(way==2){
        int _id;
        cout<<"请输入Id:\n";
        cin>>_id;
        int person=IsExist(_id);
        if(person!=-1){
            flag=true;
            EmpArray[person]->ShowInfo();
        }
    }
    if(flag==false){
        cout<<"查询失败!\n";
    }
}

bool cmp1(Worker* a,Worker* b){
    return a->GetId()<b->GetId();
}

bool cmp2(Worker* a,Worker* b){
    return a->GetId()>b->GetId();
}

void WorkManager::SortEmp(){
    if(FileIsEmpty){
        cout<<"文件为空或者记录不存在\n";
        return;
    }
    int select;
    cout<<"选择排序的方式:(1为升序,2为降序):\n";
    cin>>select;
    while(select!=1&&select!=2){
        cout<<"方式输入错误,请重新输入:\n";
        cin>>select;
    }
    if(select==1){
        sort(EmpArray.begin(),EmpArray.end(),cmp1);
    }
    else{
        sort(EmpArray.begin(),EmpArray.end(),cmp2);;
    }
    cout<<"排序完成!,排序的结果为:\n";
    SaveEmp();
    ShowAllEmp();
}

void WorkManager::CleanEmp(){
    if(FileIsEmpty){
        cout<<"文件为空或者记录不存在\n";
        return;
    }
    cout<<"是否确认清空\n"
        <<"1清空\n"
        <<"2不清空\n";
    int select;
    cin>>select;
    if(select==1){
        ofstream os(FILENAME,ios::trunc);
        os.close();
        for(int i=0;i<EmpNum;i++){
            delete EmpArray[i];
        }
        EmpArray.clear();
        EmpNum=0;
        FileIsEmpty=true;
        cout<<"清空成功!\n";
    }
}