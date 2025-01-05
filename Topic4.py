class OrderNode:
    def __init__(self, order_id, patient_name, next=None):
        self.order_id = order_id
        self.patient_name = patient_name
        self.next = next

class SinglyLinkedList:
    def __init__(self, max_orders):
        self.head = None
        self.max_orders = max_orders
        self.size = 0
    
    def add_order(self, order_id, patient_name):
        if self.size >= self.max_orders:
            print("Order limit reached!")
            return
        
        new_node = OrderNode(order_id, patient_name)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
        self.size += 1
    
    def display(self):
        current = self.head
        while current:
            print(f"Order ID: {current.order_id}, Patient Name: {current.patient_name}")
            current = current.next

# Example Usage
sll = SinglyLinkedList(3)
sll.add_order(101, "John Doe")
sll.add_order(102, "Jane Smith")
sll.add_order(103, "Alex Brown")
sll.add_order(103, "Alex Brown")
sll.display()
