from threading import Semaphore

class BoundedBlockingQueue(object):
    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.__semaphore_data = Semaphore(0)
        self.__semaphore_capacity = Semaphore(capacity)
        self.__data = []
        

    def enqueue(self, element):
        """
        :type element: int
        :rtype: void
        """
        self.__semaphore_capacity.acquire()
        self.__data.append(element)
        self.__semaphore_data.release()
        

    def dequeue(self):
        """
        :rtype: int
        """
        self.__semaphore_data.acquire()
        data =  self.__data.pop(0)
        self.__semaphore_capacity.release()
        return data
        

    def size(self):
        """
        :rtype: int
        """
        return len(self.__data)