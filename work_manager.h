#pragma once
#include<iostream>
#include<vector>
#include<string>
#include"worker.h"
#include"employee.h"
#include"boss.h"
#include"manager.h"
#include<fstream>
#include<algorithm>
using namespace std;
#define FILENAME "emp_files.txt"

class WorkManager
{
private:
    int EmpNum;      //ְ������
    vector<Worker*> EmpArray;  //ְ����Ϣ��
    bool FileIsEmpty;       //�ж��ļ��Ƿ�Ϊ��
    //���ļ���ʼ��Ա��
    void InitEmp(ifstream &is);
    //��id�ж�ְ���治����
    int IsExist(int _id);
    //�������ж�ְ���治����
    vector<int> FindByName(string _name);
public:
    //��ʼ��
    WorkManager();
    //����
    ~WorkManager();
    //չʾ�˵�
    void ShowMenu();
    //�˳�ϵͳ
    void ExitSysterm();
    //���ְ��
    void AddEmp();
    //������Ϣ
    void SaveEmp();
    //չʾ����ְ��
    void ShowAllEmp();
    //ɾ��ְ��
    void DelEmp();
    //�޸�ְ����Ϣ
    void ModEmp();
    //����Ա��
    void FindEmp();
    //��������
    void SortEmp();
    //���ְ��
    void CleanEmp();
};