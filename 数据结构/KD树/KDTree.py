import numpy as np

class Node:
    def __init__(self, data, lchild=None, rchild=None):
        self.data = data
        self.lchild = lchild
        self.rchild = rchild 

class KDTree:
    def __init__(self):
        self.kdTree = None 

    def create(self, dataSet, depth):
        if len(dataSet) > 0:
            m, n = np.shape(dataSet)
            midIndex = int(m/2)
            axis = depth % n
            sortedDataSet = self.sort(dataSet, axis)
            node = Node(sortedDataSet[midIndex])

            leftDataSet = sortedDataSet[:midIndex]
            rightDataSet = sortedDataSet[midIndex + 1:]
            print(leftDataSet)
            print(rightDataSet)
            node.lchild = self.create(leftDataSet, depth + 1)
            node.rchild = self.create(rightDataSet, depth + 1)
            return node 
        else:
            return None 

    def sort(self, dataSet, axis):
        sortDataset = dataSet[:]
        m, n = np.shape(sortDataset)
        for i in range(m):
            for j in range(0, m - i -1):
                if sortDataset[j][axis] > sortDataset[j+1][axis]:
                    sortDataset[j], sortDataset[j+1] = sortDataset[j+1], sortDataset[j]
        print(sortDataset)
        return sortDataset

    
    def preOrder(self, node):
        if node != None:
            print("tttt->%s" % node.data)
            self.preOrder(node.lchild)
            self.preOrder(node.rchild)
    
    def search(self, tree, x):
        self.nearestPoint = None 
        self.nearestValue = 0
        def travel(node, depth = 0):
            if node != None:
                n = len(x)
                axis = depth % n
                if x[axis] < node.data[axis]:
                    travel(node.lchild, depth + 1)
                else:
                    travel(node.rchild, depth + 1)
                
                distNodeAndX = self.dist(x, node.data)
                if self.nearestPoint == None:
                    self.nearestPoint = node.data 
                    self.nearestValue = distNodeAndX 
                elif self.nearestValue > distNodeAndX:
                    self.nearestPoint = node.data 
                    self.nearestValue = distNodeAndX

                print(node.data, depth, self.nearestValue, node.data[axis], x[axis])
                if abs(x[axis] - node.data[axis]) <= self.nearestValue:
                    if x[axis] < node.data[axis]:
                        travel(node.rchild, depth+1)
                    else:
                        travel(node.lchild, depth+1)
        travel(tree)
        return self.nearestPoint

    def dist(self, x1, x2):
        return ((np.array(x1) - np.array(x2)) ** 2).sum() ** 0.5

dataSet = [[2, 3, 4, 5],
           [5, 4, 4, 5],
           [9, 6, 3, 2],
           [4, 7, 3, 4],
           [8, 1, 0, 5],
           [7, 2, 3, 7]]
x = [5, 3, 4, 5]
kdtree = KDTree()
tree = kdtree.create(dataSet, 0)
kdtree.preOrder(tree)
print(kdtree.search(tree, x))