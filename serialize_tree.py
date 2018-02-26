class TreeNode:
    def __init__(self, val):
        self.value = val
        self.rightChild = None
        self.leftChild = None

    def __str__(self):
        return "[Root: {" + str(self.value) + "}, LeftChild: {" + str(self.leftChild) + "}, RightChild: {" + str(self.rightChild) +"}]"

def serialize(treeRoot):
    pass


def deserialize(string, indexFirst=0):
    indexLast = len(string)-1
    treeRoot = None
    if (string[indexFirst] == 'None'):
        treeRoot = TreeNode(None)
    else:
        treeRoot = TreeNode(int(string[indexFirst]))
    leftIndex = 2*indexFirst + 1
    rightIndex = 2*(indexFirst + 1)
    if (leftIndex < indexLast):
        treeRoot.leftChild = deserialize(string, leftIndex)
    if (rightIndex < indexLast+1):
        treeRoot.rightChild = deserialize(string, rightIndex)
    return treeRoot


def main():
    #a = input("Enter string separated by commas: ")
    a = "1,2,3,None,4,None,None,None,None,5,6"
    treeRoot = deserialize(a.split(','))
    print(treeRoot)
main()
