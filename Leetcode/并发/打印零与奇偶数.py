##三把锁
import threading
class ZeroEvenOdd(object):
    def __init__(self, n):
        self.n = n
        self.zeroLock=threading.Lock()
        self.evenLock=threading.Lock()
        self.oddLock=threading.Lock()
        
        self.evenLock.acquire()
        self.oddLock.acquire()
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(1,self.n+1,1):
            self.zeroLock.acquire()
            printNumber(0)
            if i%2==0:
                self.evenLock.release()
            else:
                self.oddLock.release()

        
        
        
    def even(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(1,self.n+1,1):
            if i%2==0:
                self.evenLock.acquire()
                printNumber(i)
                self.zeroLock.release()
            
        
        
        
    def odd(self, printNumber):
        """
        :type printNumber: method
        :rtype: void
        """
        for i in range(1,self.n+1,1):
            if i%2==1:
                self.oddLock.acquire()
                printNumber(i)
                self.zeroLock.release()


##条件变量+一把锁+notify_all()
from threading import Lock, Condition
class ZeroEvenOdd:
    def __init__(self, n):
        self.n = n
        self.num = 0
        self.cv = Condition()
        
        
	# printNumber(x) outputs "x", where x is an integer.
    def zero(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n):
            with self.cv:
                while self.num % 2 != 0:
                    self.cv.wait()
                printNumber(0)
                self.num += 1
                self.cv.notify_all()
        
        
    def even(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(self.n - (self.n+1)//2):
            with self.cv:
                while self.num % 4 !=3:
                    self.cv.wait()
                printNumber((self.num+1)//2)
                self.num += 1
                self.cv.notify_all()    
        
        
    def odd(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range((self.n+1)//2):
            with self.cv:
                while self.num % 4 != 1:
                    self.cv.wait()
                printNumber((self.num+1)//2)
                self.num += 1
                self.cv.notify_all()

        
        