#include <semaphore.h>
class Foo {
public:
    sem_t firstJobDone;
    sem_t secondJobDone;

    Foo() {
        sem_init(&firstJobDone,0,0);
        sem_init(&secondJobDone,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstJobDone);
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&firstJobDone);
        printSecond();
        sem_post(&secondJobDone);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        sem_wait(&secondJobDone);
        printThird();
    }
};