##四把锁，疯狂切换
import threading
class FizzBuzz:
    def __init__(self, n: int):
        self.n = n
        # 创建4把锁
        self.FizzLock = threading.Lock()
        self.BuzzLock = threading.Lock()
        self.FizzBuzzLock = threading.Lock()
        self.NumberLock = threading.Lock()

        # 将3把锁阻塞
        self.FizzLock.acquire()
        self.BuzzLock.acquire()
        self.FizzBuzzLock.acquire()


    # printFizz() outputs "fizz"
    def fizz(self, printFizz: 'Callable[[], None]') -> None:
        for i in range(1,self.n + 1,1):
            if not i%3 and i%5:
                self.FizzLock.acquire()
                printFizz()
                self.NumberLock.release()
    	

    # printBuzz() outputs "buzz"
    def buzz(self, printBuzz: 'Callable[[], None]') -> None:
        for i in range(1,self.n + 1,1):
            if not i%5 and i%3:
                self.BuzzLock.acquire()
                printBuzz()
                self.NumberLock.release()
    	

    # printFizzBuzz() outputs "fizzbuzz"
    def fizzbuzz(self, printFizzBuzz: 'Callable[[], None]') -> None:
        for i in range(1,self.n + 1,1):
            if not i%(3*5):
                self.FizzBuzzLock.acquire()
                printFizzBuzz()
                self.NumberLock.release()
        

    # printNumber(x) outputs "x", where x is an integer.
    def number(self, printNumber: 'Callable[[int], None]') -> None:
        for i in range(1,self.n +1,1):
            self.NumberLock.acquire()
            if not i%(3*5):
                self.FizzBuzzLock.release()
            elif not i%3:
                self.FizzLock.release()
            elif not i%5:
                self.BuzzLock.release()
            else:
                printNumber(i)
                self.NumberLock.release()
