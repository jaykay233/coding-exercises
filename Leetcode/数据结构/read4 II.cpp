/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

//抽象出一个get_next_char会更加好理解

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    
    
    int readoffset =0;
    int bufsize =0 ;
    char* tmpbuf = new char[5];

    int read(char *buf, int n) {
        for(int i =0;i<n;i++){
            char c =get_next_char();
            buf[i] = c;
        }
        return n;
    }

    char get_next_char(){
        if(readoffset==bufsize){
            bufsize = read4(tmpbuf);
            readoffset = 0;
            if(bufsize==0) return 0;
        }
        return tmpbuf[readoffset++];
    }


};