class Node:
    def __init__(self, patient_id, name, next=None, prev=None):
        self.patient_id = patient_id
        self.name = name
        self.next = next
        self.prev = prev

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def append(self, patient_id, name):
        new_node = Node(patient_id, name)
        if not self.head:
            self.head = self.tail = new_node
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
    
    def display(self):
        current = self.head
        while current:
            print(f"Patient ID: {current.patient_id}, Name: {current.name}")
            current = current.next

# Example Usage
dll = DoublyLinkedList()
dll.append(1, "John Doe")
dll.append(2, "Jane Smith")
dll.display()
