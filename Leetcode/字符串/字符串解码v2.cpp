class Solution {
public:
    string src; 
    size_t ptr;

    int getDigits() {
        int ret = 0;
        while (ptr < src.size() && isdigit(src[ptr])) {
            ret = ret * 10 + src[ptr++] - '0';
        }
        return ret;
    }

    string getString() {
        if(ptr == src.size() || src[ptr] == ']'){
            return "";
        }
        string ret = ""; int repTime = 1;
        if(isdigit(src[ptr])){
            repTime = getDigits();
            ptr ++;
            string cur = getString();
            ptr ++;
            while(repTime--) ret += cur;
        }
        else if(isalpha(src[ptr])){
            ret = string(1, src[ptr]);
            ptr ++;
        }
        return ret + getString();
    }

    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getString();
    }
};