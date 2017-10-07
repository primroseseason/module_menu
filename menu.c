//
//  menu.c
//  module_menu
//
//  Created by 高旭 on 2017/10/7.
//  Copyright © 2017年 高旭. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "module.h"

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10
static time_t t;
int Help(void);
int Info(void);
int Exit(void);
int Time(void);
static tDataNode menu[]=
{
    {"help","List all command in this program",Help,&menu[1]},
    {"info","Show information",Info,&menu[2]},
    {"version", "menu program v1.0", NULL,&menu[3]},
    {"exit","Exit this program",Exit,&menu[4]},
    {"time","Output system time",Time,NULL},
};

int main ()
{
    /* cmd line begins */
    while (1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(menu, cmd);
        if (p == NULL)
        {
            printf("\tThis is a wrong cmd!\n");
            continue;
        }
        printf("\t%s - %s\n", p->cmd, p->desc);
        if (p->handler != NULL)
        {
            p->handler();
        }
        
    }
}
int Help()
{
    ShowAllCmd(menu);
    return 0;
}
int Info()
{
    printf("Author:Gao xu\nProgram Version:1.0\n");
    return 0;
}
int Exit()
{
    printf("Program exited\n");
    exit(0);
}
int Time()
{
    time_t t;
    time(&t);
    printf("The system time now is: %s\n",ctime(&t));
    return 0;
}

