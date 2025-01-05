class TreeNode:
    def __init__(self, name):
        self.name = name
        self.children = []

    def add_child(self, node):
        self.children.append(node)

    def display(self, level=0):
        print(" " * level + self.name)
        for child in self.children:
            child.display(level + 2)

# Example Usage
root = TreeNode("Clinic")
department1 = TreeNode("Emergency")
department2 = TreeNode("General")
department1.add_child(TreeNode("Trauma"))
department2.add_child(TreeNode("Pediatrics"))
root.add_child(department1)
root.add_child(department2)
root.display()
