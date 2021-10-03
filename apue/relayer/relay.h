#ifndef RELAYER_H__
#define RELAYER_H__

enum
{
    STATE_RUNNING=1,
    STATE_CANCELEL,
    STATE_OVER
};

struct rel_stat_st{
    int state;
    int fd1;
    int fd2;
    int count12, count21;
};

int rel_addjob(int fd1, int fd2);
/*
*   retunr >=0          成功，返回当前任务的id
           == -EINVAL   失败，参数非法
           == -ENOSPC   失败，任务数组满
           == -ENOMEM   失败，内存分配有误
*/
int rel_canceljob(int fd);
/*
 *  return  == 0          成功，指定任务成功取消
 *          == -EINVAL    失败，参数非法
 *          == -EBUSY     失败，任务早已被取消
 * 
 */

int rel_waitjob(int id, struct rel_stat_st*);
/****
 *  return == 0          成功， 指定任务已终止并返回状态
 *         == -EINVAL    失败，参数非法
 */

int rel_statjob(int id, struct rel_stat_st*);
/**
 *    return == 0           成功
 *           == -EINVAL     失败，参数非法
 * 
 * **/

#endif