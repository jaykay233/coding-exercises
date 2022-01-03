#include <iostream>
using namespace std;
int main(){
    std::allocator<int> aalloc;
    int *p = aalloc.allocate(3);
    int *q = p;
    q = p;
    *q = 1; q++;
    *q = 2; q++;
    *q = 3;
    aalloc.deallocate(p,3);

    return 0;
}