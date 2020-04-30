# Property
# 완전이진트리이다.
# 각 노드의 왼쪽 서브트리에는 해당 노드의 값보다 작은 값을 지닌 노드들로 이루어져 있다.
# 각 노드의 오른쪽 서브트리에는 해당 노드의 값보다 큰 값을 지닌 노드들로 이루어져 있다.
# 중복된 노드가 없어야 한다.
# 왼쪽 서브트리, 오른쪽 서브트리 또한 이진탐색트리이다.

class Node:
	def __init__(self, val):
		self.val = val;
		self.leftChild = None
		self.rightChild = None
class BinarySearchTree:
	def __init__(self):
		self.root = None

	def setRoot(self, val):
		self.root = Node(val)

	def find(self, val):
		if (self.findNode(self.root, val) is False) :
			return False
		else :
			return True

	def findNode(self, currentNode, val):
		if (currentNode is None) :
			return False
		elif (val == currentNode.val):
			return currentNode
		elif (val < currentNode.val):
			return self.findNode(currentNode.leftChild, val)
		else:
			return self.findNode(currentNode.rightChild, val)

	def insert(self, val):
		if (self.root is None):
			self.setRoot(val)
		else:
			self.insertNode(self.root, val)

	def insertNode(self, currentNode, val):
		if (val <= currentNode.val):
			if (currentNode.leftChild):
				self.insertNode(currentNode.leftChild, val)
			else:
				currentNode.leftChild = Node(val)
		elif (val > currentNode.val):
			if (currentNode.rightChild):
				self.insertNode(currentNode.rightChild, val)
			else:
				currentNode.rightChild = Node(val)
 	def traverse(self):
 		return self.traverseNode(self.root)

 	def traverseNode(self, currentNode):
 		result = []
 		if (currentNode.leftChild is not None):
 			result.extend(self.traverseNode(currentNode.leftChild))
 		if (currentNode is not None):
 			result.extend([currentNode.val])
 		if (currentNode.rightChild is not None):
 			result.extend(self.traverseNode(currentNode.rightChild))

 		return result
