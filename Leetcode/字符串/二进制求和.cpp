class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res = "";
        int i = a.size()-1, j = b.size()-1;
        while(i>=0 && j>=0){
            int v1 = a[i] - '0';
            int v2 = b[j] - '0';
            int v = v1 + v2 + carry;
            res += to_string(v%2);
            carry = v/2;
            i --; j --;    
        }



        if(i>=0){
            while(i>=0){
                int v1 = a[i] - '0';
                int v = v1 + carry;
                res += to_string(v%2);
                carry = v/2;
                i--;
            }
            if(carry) {
                res.push_back(carry + '0');
                carry = 0;
            }
        }
        else if(j>=0){
            while(j>=0){
                int v2 = b[j] - '0';
                int v = v2 + carry;
                res += to_string(v%2);
                carry = v/2;
                j--;
            }
            if(carry) {
                res.push_back(carry + '0');
                carry = 0;
            }
        }else{
            if(carry){
                res.push_back(carry + '0');
                carry = 0;
            }
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};