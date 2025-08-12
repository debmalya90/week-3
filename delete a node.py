class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Function to display linked list
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

pos = int(input("Enter position to delete (1-based index): "))

if pos == 1:
    head = head.next
else:
    temp = head
    for i in range(1, pos - 1):
        if temp is None:
            print("Position out of range!")
            break
        temp = temp.next
    else:
        if temp.next is None:
            print("Position out of range!")
        else:
            temp.next = temp.next.next

# Display updated list
print("Updated Linked List:")
display(head)
