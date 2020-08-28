import numpy as np
class Solution(object):
    def __init__(self, w):
        """
        :type w: List[int]
        """
        self.K = 0
        self.probs = []
        self.smaller = []
        self.larger = []
        self.q = None
        self.J = None
        
        self.K = len(w)
        total = sum(w)
        self.probs = [p*1.0/total for p in w]
        self.q = np.zeros(self.K)
        self.J = np.zeros(self.K,dtype=np.int)
        for kk, prob in enumerate(self.probs):
            self.q[kk] = prob * self.K
            if self.q[kk] < 1.0:
                self.smaller.append(kk)
            else:
                self.larger.append(kk)
        while len(self.smaller)>0 and len(self.larger)>0:
            small = self.smaller.pop()
            large = self.larger.pop()
            self.J[small] = large
            self.q[large] = self.q[large] -(1.0-self.q[small])
            if self.q[large] < 1.0:
                self.smaller.append(large)
            else:
                self.larger.append(large)

    def pickIndex(self):
        """
        :rtype: int
        """
        sz = len(self.J)
        kk = int(np.floor(np.random.rand()*sz))
        if np.random.rand() < self.q[kk]:
            return kk
        else:
            return self.J[kk]