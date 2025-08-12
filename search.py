class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to search an element
def search(head, key):
    pos = 1
    temp = head
    while temp:
        if temp.data == key:
            return pos
        temp = temp.next
        pos += 1
    return -1

def display(head):
    temp = head
    while temp:
        print(temp.data, end=" -> ")
        temp = temp.next
    print("NULL")

n = int(input("Enter number of nodes: "))
head = None
for i in range(n):
    data = int(input(f"Enter data for node {i+1}: "))
    new_node = Node(data)
    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node

key = int(input("Enter element to search: "))
pos = search(head, key)

if pos != -1:
    print(f"Element {key} found at position {pos}")
else:
    print(f"Element {key} not found in the list")


print("Linked List:")
display(head)
