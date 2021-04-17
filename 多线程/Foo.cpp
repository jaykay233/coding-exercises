#include <pthread.h>
#include <vector>
#include <mutex>
#include <iostream>
#include <boost/smart_pctr.hpp>
#include <boost/make_shared.hpp>

class Foo{
public:
    void print(){
        std::cout<<"error"<<std::endl;
    }
};

std::vector<Foo> foos;
std::mutex mx;

typedef std::vector<Foo> FooList;
typedef boost::shared_ptr<FooList> FooListPtr;
FooListPtr g_foos;

void post(const Foo& f){
    std::lock_guard<std::mutex> lock(mx);
    foos.push_back(f);
}

void postv2(const Foo& f){
    printf("post\n");
    std::unique_lock<std::mutex> lck(mx);
    if(!g_foos.unique()){
        g_foos.reset(new FooList(*g_foos));
        printf("copy the whole list\n");
    }
    assert(g_foos.unique());
    g_foos->push_back(f);
}

int main(){


    return 0;
}