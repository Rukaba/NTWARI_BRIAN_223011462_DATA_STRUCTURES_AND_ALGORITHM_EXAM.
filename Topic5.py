class BSTNode:
    def __init__(self, patient_id, name):
        self.patient_id = patient_id
        self.name = name
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
    
    def insert(self, patient_id, name):
        if not self.root:
            self.root = BSTNode(patient_id, name)
        else:
            self._insert(self.root, patient_id, name)
    
    def _insert(self, node, patient_id, name):
        if patient_id < node.patient_id:
            if node.left is None:
                node.left = BSTNode(patient_id, name)
            else:
                self._insert(node.left, patient_id, name)
        else:
            if node.right is None:
                node.right = BSTNode(patient_id, name)
            else:
                self._insert(node.right, patient_id, name)
    
    def display_in_order(self):
        self._in_order(self.root)
    
    def _in_order(self, node):
        if node:
            self._in_order(node.left)
            print(f"Patient ID: {node.patient_id}, Name: {node.name}")
            self._in_order(node.right)

# Example Usage
bst = BST()
bst.insert(1, "John Doe")
bst.insert(2, "Jane Smith")
bst.display_in_order()
