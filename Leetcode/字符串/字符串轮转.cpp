class Solution{
public: 
    bool isFlippedString(string s1, string s2){
        return minString(s1) == minString(s2);
    }

    string minString(string s1){
        int l = s1.size();
        int i =0,j = 1,k=0;
        while(i<l && j<l && k<l){
            int t = s1[(i+k)%l] - s1[(j+k)%l];
            if(t==0)
                k ++;
            else {
                if(t>0)
                    i = i + k + 1;
                else
                    j = j + k + 1;
                if(i==j)
                    j++;
                k = 0;
            }
        }
        int min = i<j?i:j;
        return s1.substr(min,l-min) + s1.substr(0,min);
    }
};