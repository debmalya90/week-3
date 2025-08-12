class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def add_lists(l1, l2):
    dummy = Node(0)
    temp = dummy
    carry = 0

    while l1 or l2 or carry:
        val1 = l1.data if l1 else 0
        val2 = l2.data if l2 else 0
        total = val1 + val2 + carry
        carry = total // 10
        temp.next = Node(total % 10)
        temp = temp.next
        if l1: l1 = l1.next
        if l2: l2 = l2.next

    return dummy.next

def display(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("NULL")


l1 = Node(3)
l1.next = Node(4)
l1.next.next = Node(2)
l2 = Node(4)
l2.next = Node(6)
l2.next.next = Node(5)

print("First number:")
display(l1)
print("Second number:")
display(l2)

result = add_lists(l1, l2)
print("Sum:")
display(result)  # Expected: 7 -> 0 -> 8 (807)
