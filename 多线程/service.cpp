
void workerThread(){
    while(running){ //running变量是全局标志
        Function task = taskQueue.take(); // this blocks
        task(); //在产品代码中需要考虑异常处    理
    }
}

int N = num_of_computing_threads;
for(int i =0;i<N;++i){
    create_thread(&workerThread);
}

Foo foo;
boost::function<void()> task = boost::bind(&Foo::calc, &foo);
taskQueue.post(task);