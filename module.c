//
//  module.c
//  module_menu
//
//  Created by 高旭 on 2017/10/7.
//  Copyright © 2017年 高旭. All rights reserved.
//

#include "module.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
tDataNode* FindCmd(tDataNode* head, char* cmd)
{
    if (head == NULL || cmd == NULL)
    {
        return NULL;
    }
    tDataNode *p = head;
    while (p != NULL)
    {
        if (strcmp(p->cmd, cmd) == 0)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}
int ShowAllCmd(tDataNode* head)
{
    printf("Menu List:\n");
    tDataNode *q = head;
    while (q != NULL)
    {
        printf("\t%s - %s\n", q->cmd, q->desc);
        q = q->next;
    }
    
    return 0;
    
}
