/**
 * // This is the FontInfo's API interface.
 * // You should not implement it, or speculate about its implementation
 * class FontInfo {
 *   public:
 *     // Return the width of char ch when fontSize is used.
 *     int getWidth(int fontSize, char ch);
 *     
 *     // Return Height of any char when fontSize is used.
 *     int getHeight(int fontSize)
 * };
 */
class Solution {
public:

    bool check(string text,long long  w,long long h, FontInfo fontInfo,int fontSize){
        for(char c:text){
            w -= fontInfo.getWidth(fontSize, c);
        }
        int height = fontInfo.getHeight(fontSize);
        return w>=0 && height <= h;
    }

    int maxFont(string text, int w, int h, vector<int>& fonts, FontInfo fontInfo) {
        int i =0, j = fonts.size()-1;
        while(i<j){
            int mid = (i + j + 1)>> 1;
            int fontsize = fonts[mid];
            if(check(text,w,h,fontInfo,fontsize)) {
                i = mid;
            }
            else j = mid - 1;
        }
        if(check(text,w,h,fontInfo,fonts[i])) return fonts[i];
        return -1;
    }
};