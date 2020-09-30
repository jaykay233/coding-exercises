int quickMulti(int A,int B){
    int ans = 0;
    for(;B;B>>=1){
        if(B&1)
            ans+=A;
        A<<=1;
    }
    return ans;
};