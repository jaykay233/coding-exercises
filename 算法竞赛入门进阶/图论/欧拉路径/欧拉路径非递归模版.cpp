void euler(){//模拟dfs
    stk[++top] = 1;//起点
    while(top > 0){
        int x = stk[top],i = head[x];
        while(i && vis[i])i = nex[i];//找到一条尚未访问过的路
        // 与x相连的所有边均已访问，模拟回溯过程，并记录
        if(i){
            stk[++top] = ver[i];
            vis[i] =  true;//题目要求要回来的嘛，需要标记一次
            //vis[i] = ver[i ^ 1] = true;//正常的欧拉回路模板
            head[x] = nex[i];
        }
        else {// 与x相连的所有边均已访问，模拟回溯过程，并记录
            top--;
            ans[++cnt] = x;
        }

    }
}

