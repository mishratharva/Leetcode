class Node:

  def __init__(self, data):
    self.data=data
    self.leftchild=None
    self.rightchild=None


class BinarySearchTree:

  def __init__(self):
    self.root=None

  def insert(self, data):
    if not self.root:
      self.root=Node(data)
    else:
      self.insertNode(data, self.root)

  def insertNode(self, data, node):
    if data < node.data:
      if node.leftchild:
        self.insertNode(data, node.leftchild)
      else:
        node.leftchild=Node(data)
    else:
      if node.rightchild:
        self.insertNode(data, node.rightchild)
      else:
        node.rightchild=Node(data)

  def traverse(self):
    if self.root:
      self.postorderTraversal(self.root)

  def postorderTraversal(self, node):
    if node.leftchild:
      self.postorderTraversal(node.leftchild)
    if node.rightchild:
      self.postorderTraversal(node.rightchild)
    print(node.data)




#testing above code........................................

#creating object..........................................

bst=BinarySearchTree()
bst.insert(1)
bst.insert(2)
bst.insert(3)
bst.insert(4)
bst.insert(5)
bst.insert(6)
bst.insert(7)
bst.insert(8)
bst.insert(9)
bst.insert(0)

#Postorder Traversal-----------------------------
bst.traverse()
