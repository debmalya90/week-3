class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def print_list(head):
    while head:
        print(head.data, end=" -> ")
        head = head.next
    print("NULL")

# Example
head = Node(10)
head.next = Node(20)
head.next.next = Node(30)

print("Linked List:")
print_list(head)
