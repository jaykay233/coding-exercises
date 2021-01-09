#1.Semaphore信号量
from threading import Semaphore
class FooBar(object):
    def __init__(self, n):
        self.n = n
        self.a = Semaphore(1)
        self.b = Semaphore(0)


    def foo(self, printFoo):
        """
        :type printFoo: method
        :rtype: void
        """
        for i in xrange(self.n):
            self.a.acquire()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.b.release()


    def bar(self, printBar):
        """
        :type printBar: method
        :rtype: void
        """
        for i in xrange(self.n):
            self.b.acquire()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.a.release()


#2.queue同步
#两个函数对应两个queue,queue为空时函数阻塞
import queue

class FooBar:
    def __init__(self, n):
        self.n = n
        self.q1 = queue.Queue()
        self.q2 = queue.Queue()
        self.q1.put(0)


    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.q1.get()
            # printFoo() outputs "foo". Do not change or remove this line.
            printFoo()
            self.q2.put(0)


    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            self.q2.get()
            # printBar() outputs "bar". Do not change or remove this line.
            printBar()
            self.q1.put(0)


#3.条件变量
#python条件变量 + 一把锁
from threading import Lock, Condition
class FooBar:
    def __init__(self, n):
        self.n = n
        self.num = 0 
        self.cv = Condition()

    def foo(self, printFoo: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.num % 2 == 1:
                    self.cv.wait()
                printFoo()
                self.num += 1
                self.cv.notify()
            

    def bar(self, printBar: 'Callable[[], None]') -> None:
        
        for i in range(self.n):
            with self.cv:
                while self.num %2 == 0:
                    self.cv.wait()
                # printBar() outputs "bar". Do not change or remove this line.
                printBar()
                self.num += 1
                self.cv.notify()
