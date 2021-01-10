##Lock控制
from threading import Lock
class TrafficLight(object):
    
    def __init__(self):
        self.lock = Lock()
        self.id = 1

    def carArrived(self, carId, roadId, direction, turnGreen, crossCar):
        """
        :type roadId: int --> // ID of the car
        :type carId: int --> // ID of the road the car travels on. Can be 1 (road A) or 2 (road B)
        :type direction: int --> // Direction of the car
        :type turnGreen: method --> // Use turnGreen() to turn light to green on current road
        :type crossCar: method --> // Use crossCar() to make car cross the intersection
        :rtype: void
        """
        self.lock.acquire()
        if self.id == roadId:
            crossCar()
        else:
            self.id=roadId
            turnGreen()
            crossCar()
        self.lock.release()