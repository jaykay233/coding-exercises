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
        
        