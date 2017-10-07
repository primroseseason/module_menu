//
//  module.h
//  module_menu
//
//  Created by 高旭 on 2017/10/7.
//  Copyright © 2017年 高旭. All rights reserved.
//

#ifndef module_h
#define module_h
typedef struct DataNode
{
    char *cmd;
    char *desc;
    int (*handler)(void);
    struct  DataNode *next;
}tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode * FindCmd(tDataNode *head, char *cmd);
/* show all cmd in linklist */
int ShowAllCmd(tDataNode* head);
#endif /* module_h */
