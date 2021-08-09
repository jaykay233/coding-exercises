#include <atomic>
#include <stdio.h>

int main(){
    std::atomic<int> value;
    value = 99;
    printf("%d\n", (int)value);

    value ++;
    printf("%d\n",(int)value);
    return 0;
}