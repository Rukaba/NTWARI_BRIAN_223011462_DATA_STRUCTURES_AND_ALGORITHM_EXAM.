class Queue:
    def __init__(self):
        self.queue = []
    
    def enqueue(self, patient_id, name):
        self.queue.append((patient_id, name))
    
    def dequeue(self):
        if self.is_empty():
            return None
        return self.queue.pop(0)
    
    def is_empty(self):
        return len(self.queue) == 0
    
    def display(self):
        for patient in self.queue:
            print(f"Patient ID: {patient[0]}, Name: {patient[1]}")

# Example Usage
queue = Queue()
queue.enqueue(1, "John Doe")
queue.enqueue(2, "Jane Smith")
queue.display()
queue.dequeue()
queue.display()
