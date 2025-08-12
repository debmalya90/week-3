class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def detect_loop(head):
    slow = head
    fast = head
    while slow and fast and fast.next:
        slow = slow.next
        fast = fast.next.next
        if slow == fast:
            return True
    return False

head = Node(1)
second = Node(2)
third = Node(3)
fourth = Node(4)

head.next = second
second.next = third
third.next = fourth
fourth.next = second  # Creates loop

if detect_loop(head):
    print("Loop detected in linked list")
else:
    print("No loop found")
