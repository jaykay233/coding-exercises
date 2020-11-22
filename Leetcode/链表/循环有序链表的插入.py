class Solution:
    def insert(self,head,insertVal):
        if not head:
            newNode = Node(insertVal,None)
            newNode.next = newNode
            return newNode 
        
        prev,curr = curr,curr.next 
        toinsert = False 

        while True:
            if prev.val <= insertVal <= curr.val:
                toinsert=True 
            elif prev.val > curr.val:
                if insertVal >= prev.val or insertVal <= curr.val:
                    toinsert=True 

            if toinsert:
                prev.next = Node(insertVal,curr)
                return head
            prev, curr = curr, curr.next 
            if prev == head:
                break

        prev.next = Node(insertVal,curr)
        return head 