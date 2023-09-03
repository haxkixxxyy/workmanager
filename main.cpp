#include<iostream>
#include"work_manager.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
using namespace std;

int main(){
    WorkManager wm;
    // //测试
    // Employee em("张三",1,2);
    // em.ShowInfo();
    // Manager mg("李四",3,4);
    // mg.ShowInfo();
    // Boss bs("王五",6,3);
    // bs.ShowInfo();
    long long choice=0;
    while (true)
    {
        wm.ShowMenu();
        cin>>choice;
        switch (choice)
        {
        case 0:
            wm.ExitSysterm();
            break;
        case 1:
            wm.AddEmp();
            system("pause");
            system("cls");
            break;
        case 2:
            wm.ShowAllEmp();
            system("pause");
            system("cls");
            break;
        case 3:
            wm.DelEmp();
            system("pause");
            system("cls");           
            break;
        case 4:
            wm.ModEmp();
            system("pause");
            system("cls"); 
            break;
        case 5:
            wm.FindEmp();
            system("pause");
            system("cls");             
            break;
        case 6:
            wm.SortEmp();
            system("pause");
            system("cls"); 
            break;
        case 7:
            wm.CleanEmp();
            system("pause");
            system("cls");           
            break;
        default:
            system("cls");
            break;
        }
    }
    return 0;
}