class Solution:
    def deleteDuplicatesUnsorted(self, head: ListNode) -> ListNode:
        d={};p=head
        while p:
            d[p.val]=d.get(p.val,0) +1
            p=p.next
        w=pr=ListNode(0,head)
        while head:
            if d[head.val] >1:pr.next=head.next
            else:pr=pr.next
            head=head.next
        return w.next
