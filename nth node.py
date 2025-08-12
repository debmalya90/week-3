class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def nth_from_end(head, n):
    first = head
    second = head
    
    # Move first pointer n steps ahead
    for _ in range(n):
        if first is None:
            return None
        first = first.next
    while first:
        first = first.next
        second = second.next

    return second.data

n_nodes = int(input("Enter number of nodes: "))
head = None
for i in range(n_nodes):
    data = int(input(f"Enter data for node {i+1}: "))
    new_node = Node(data)
    if head is None:
        head = new_node
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = new_node
n = int(input("Enter n (from end): "))
result = nth_from_end(head, n)
if result is not None:
    print(f"{n}th node from end is: {result}")
else:
    print("List is shorter than given n")
