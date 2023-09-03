#include"work_manager.h"

WorkManager::WorkManager()
{
    ifstream is;
    is.open(FILENAME);
    if(!is.is_open()){
        cout<<"�ļ�������"<<endl;
        EmpNum=0;
        EmpArray.clear();
        FileIsEmpty=true;
        is.close();
        return;      
    }
    is.get();
    if(is.eof()){
        cout<<"�ļ�Ϊ��"<<endl;
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
    //����
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
    cout << "********* 0.�˳�������� *********" << endl;    
    cout << "********* 1.���ְ����Ϣ *********" << endl;
    cout << "********* 2.��ʾְ����Ϣ *********" << endl;
    cout << "********* 3.ɾ����ְְ�� *********" << endl;
    cout << "********* 4.�޸�ְ����Ϣ *********" << endl;    
    cout << "********* 5.����ְ����Ϣ *********" << endl;
    cout << "********* 6.���ձ������ *********" << endl;     
    cout << "********* 7.��������ĵ� *********" << endl;
    cout << "**********************************" << endl;
}

void WorkManager::ExitSysterm(){
    cout<<"��ӭ�´�ʹ��";
    exit(EXIT_FAILURE);
}

void WorkManager::AddEmp(){
    int num;
    string _name;
    int _id,_did;
    Worker* temp;
    int i=0;
    cout<<"������Ҫ��ӵ�����:\n";
    cin>>num;
    if(num<=0){
        cout<<"�������!\n";
    }
    else{
        while (i<num)
        {   
            cout<<"�������"<<i+1<<"λְԱ����Ϣ"<<endl;
            cout<<"����������:\n";
            cin>>_name;
            cout<<"������id:\n";
            cin>>_id;
            cout<<"�������λ:(1ΪԱ��,2Ϊ����,3Ϊ�ϰ�)\n";
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
                cout<<"�������!\n";
                cout<<"����������\n";
                i--;
                break;
            }
            i++;
        }
        EmpNum+=num;
        cout<<"�ɹ����"<<num<<"λԱ��"<<endl;
        FileIsEmpty=false;
        SaveEmp();
    }
}

//����ְ����Ϣ��
void WorkManager::SaveEmp(){
    ofstream os;
    os.open(FILENAME);
    for(int i=0;i<EmpNum;i++){
        EmpArray[i]->SaveInfo(os);
    }
}

//��ʼ��ְ����Ϣ��
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
        cout<<"���κ�ְ����Ϣ\n";
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
        cout<<"�ļ�Ϊ�ջ��߼�¼������\n";
        return;
    }
    int _id;
    cout<<"������Ҫɾ��ְ����id:"<<endl;
    cin>>_id;
    int temp=IsExist(_id);
    if(temp==-1){
        cout<<"��Ӧְ��������!\n";
    }
    else{
        delete EmpArray[temp];
        EmpArray.erase(EmpArray.begin()+temp);
        cout<<"ɾ���ɹ�!\n";
        EmpNum--;
        if(EmpNum==0) FileIsEmpty=true;
        SaveEmp();
    }
}

void WorkManager::ModEmp(){
    if(FileIsEmpty){
        cout<<"�ļ�Ϊ�ջ��߼�¼������\n";
        return;
    }
    int _id;
    cout<<"������id:\n";
    cin>>_id;
    int temp=IsExist(_id);
    if(temp==-1){
        cout<<"��ӦԱ��������\n";
        return;
    }
    cout<<"��Ա����Ϣ����:\n";
    EmpArray[temp]->ShowInfo();
    string _name;
    int _did;
    cout<<"����������:\n";
    cin>>_name;
    cout<<"�������λ:(1ΪԱ��,2Ϊ����,3Ϊ�ϰ�)\n";
    cin>>_did;
    while(_did!=1&&_did!=2&&_did!=3){
        cout<<"��������,����������:(1ΪԱ��,2Ϊ����,3Ϊ�ϰ�)\n";
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
    cout<<"�޸ĳɹ�!\n";
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
        cout<<"�ļ�Ϊ�ջ��߼�¼������\n";
        return;
    }
    int flag=false;
    int way;
    cout<<"��������ҵķ�ʽ:\n"
        <<"1Ϊ����������\n"
        <<"2Ϊ��Id����\n";
    cin>>way;
    while(way!=1&&way!=2){
        cout<<"��ʽ�������,����������:\n";
        cin>>way;
    }
    if(way==1){
        string _name;
        cout<<"����������:\n";
        cin>>_name;
        vector<int> person=FindByName(_name);
        if(person.size()!=0) flag=true;
        for(auto x:person){
            EmpArray[x]->ShowInfo();
        }
    }
    if(way==2){
        int _id;
        cout<<"������Id:\n";
        cin>>_id;
        int person=IsExist(_id);
        if(person!=-1){
            flag=true;
            EmpArray[person]->ShowInfo();
        }
    }
    if(flag==false){
        cout<<"��ѯʧ��!\n";
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
        cout<<"�ļ�Ϊ�ջ��߼�¼������\n";
        return;
    }
    int select;
    cout<<"ѡ������ķ�ʽ:(1Ϊ����,2Ϊ����):\n";
    cin>>select;
    while(select!=1&&select!=2){
        cout<<"��ʽ�������,����������:\n";
        cin>>select;
    }
    if(select==1){
        sort(EmpArray.begin(),EmpArray.end(),cmp1);
    }
    else{
        sort(EmpArray.begin(),EmpArray.end(),cmp2);;
    }
    cout<<"�������!,����Ľ��Ϊ:\n";
    SaveEmp();
    ShowAllEmp();
}

void WorkManager::CleanEmp(){
    if(FileIsEmpty){
        cout<<"�ļ�Ϊ�ջ��߼�¼������\n";
        return;
    }
    cout<<"�Ƿ�ȷ�����\n"
        <<"1���\n"
        <<"2�����\n";
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
        cout<<"��ճɹ�!\n";
    }
}