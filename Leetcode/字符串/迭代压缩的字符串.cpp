class StringIterator {
public:
    string res;
    int ptr=0, num =0;
    char ch = ' ';
    StringIterator(string compressedString) {
        res = compressedString;
    }
    
    char next() {
        if(!hasNext()) return ' ';
        if(num == 0){
            ch = res[ptr++];
            while(ptr < res.size() && isdigit(res[ptr])){
                num = num * 10 + res[ptr++] - '0';
            }
        }
        num --;
        return ch;
    }
    
    bool hasNext() {
        return ptr !=res.size() || num!=0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */