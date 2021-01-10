## 暴力上锁
from threading import Lock
class DiningPhilosophers:
    def __init__(self):
        self.Fork0 = Lock()
        self.Fork1 = Lock()
        self.Fork2 = Lock()
        self.Fork3 = Lock()
        self.Fork4 = Lock()
        self.ForkList=[self.Fork0,self.Fork1,self.Fork2,self.Fork3,self.Fork4]
    # call the functions directly to execute, for example, eat()
    def wantsToEat(self,
                   philosopher: int,
                   pickLeftFork: 'Callable[[], None]',
                   pickRightFork: 'Callable[[], None]',
                   eat: 'Callable[[], None]',
                   putLeftFork: 'Callable[[], None]',
                   putRightFork: 'Callable[[], None]') -> None:
        self.ForkList[philosopher%5].acquire()
        pickRightFork()
        self.ForkList[(philosopher+1)%5].acquire()
        pickLeftFork()
        eat()
        putLeftFork()
        self.ForkList[(philosopher+1)%5].release()
        putRightFork()
        self.ForkList[philosopher%5].release()