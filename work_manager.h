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
    int EmpNum;      //职工人数
    vector<Worker*> EmpArray;  //职工信息表
    bool FileIsEmpty;       //判断文件是否为空
    //由文件初始化员工
    void InitEmp(ifstream &is);
    //由id判断职工存不存在
    int IsExist(int _id);
    //由姓名判断职工存不存在
    vector<int> FindByName(string _name);
public:
    //初始化
    WorkManager();
    //析构
    ~WorkManager();
    //展示菜单
    void ShowMenu();
    //退出系统
    void ExitSysterm();
    //添加职工
    void AddEmp();
    //保存信息
    void SaveEmp();
    //展示所有职工
    void ShowAllEmp();
    //删除职工
    void DelEmp();
    //修改职工信息
    void ModEmp();
    //查找员工
    void FindEmp();
    //进行排序
    void SortEmp();
    //清空职工
    void CleanEmp();
};