# ------------------------------ Question 1 ------------------------------

# Question 1
class Position:

    def __init__(self, key, value, parent=None):
        self.key = key
        self.value = value
        self.parent = parent
        self.left = None
        self.right = None

    def __repr__(self):
        return f"({self.key}, {self.value})"

class BinarySearchTree:

    def __init__(self):
        self.root = None

    def _internal_upsert(self, key, value, node, parent=None):

        if not node:
            return Position(key, value, parent)

        if key < node.key:
            node.left = self._internal_upsert(key, value, node.left, node)
        elif key > node.key:
            node.right = self._internal_upsert(key, value, node.right, node)
        elif key == node.key:
            node.value = value

        return node

    def upsert(self, key, value):

        if self.root is None:
            self.root = Position(key, value)
            return self.root

        return self._internal_upsert(key, value, self.root)

    def _internal_in_order(self, node, inorder_list):

        if not node:
            return

        self._internal_in_order(node.left, inorder_list)
        inorder_list.append(node.key)
        self._internal_in_order(node.right, inorder_list)

    def in_order(self):

        in_order_list = []
        self._internal_in_order(self.root, in_order_list)
        return in_order_list

    def _internal_first(self, node):

        if not node.left:
            return node

        return self._internal_first(node.left)

    def first(self, node=None):
        if not node:
            node = self.root
        return self._internal_first(node)

    def _internal_last(self, node):
        if not node.right:
            return node

        return self._internal_last(node.right)

    def last(self, node=None):
        if not node:
            node = self.root
        return self._internal_last(node)

    def _before_no_left(self, node):
        if not node:
            return None

        if not node.parent:
            return None

        if node.parent.right == node:
            return node.parent

        return self._before_no_left(node.parent)

    def before(self, node):
        if node is None:
            return None

        if node.left:
            # go right from left
            return self.last(node.left)

        # go up until node is the right child of parent
        return self._before_no_left(node)

    def _after_no_right(self, node):
        if not node:
            return None

        if node.parent is None:
            return None

        if node.parent.left == node:
            return node.parent

        return self._after_no_right(node.parent)

    def after(self, node):
        if node is None:
            return None

        if node.right:
            # go right from left
            return self.first(node.right)

        # go up until node is the left child of parent
        return self._after_no_right(node)

    def in_order_using_after(self, node=None):
        if not node:
            node = self.root

        in_order_list = []
        current = self.first(node)
        while current:
            in_order_list.append(current.key)
            current = self.after(current)
        return in_order_list

    def in_order_using_before(self, node=None):
        if not node:
            node = self.root

        in_order_list = []
        current = self.last(node)
        while current:
            in_order_list.append(current.key)
            current = self.before(current)
        in_order_list.reverse()
        return in_order_list

    def _find_internal(self, key, node):
        if not node:
            return None

        if key < node.key:
            return self._find_internal(key, node.left)
        elif key > node.key:
            return self._find_internal(key, node.right)
        elif key == node.key:
            return node

    def find(self, key, node=None):

        if not node:
            node = self.root
        if not node:
            return None

        return self._find_internal(key, node)

    def _internal_preorder(self, node, result_list):

        if node is None:
            return

        result_list.append(node.key)
        self._internal_preorder(node.left, result_list)
        self._internal_preorder(node.right, result_list)

    def preorder(self, node=None):
        if not node:
            node =  self.root

        preorder = []
        self._internal_preorder(node, preorder)
        return preorder

    def _internal_postorder(self, node, result_list):

        if node is None:
            return

        self._internal_postorder(node.left, result_list)
        self._internal_postorder(node.right, result_list)
        result_list.append(node.key)

    def postorder(self, node=None):
        if not node:
            node =  self.root

        postorder = []
        self._internal_postorder(node, postorder)
        return postorder

    def delete(self, node):

        if not node:
            return

        if node.left and node.right:

            before = self.before(node)
            node.key = before.key
            node.value = before.value
            self.delete(before)

        else:

            # if the node is the root node, and has no children, simply delete the root node
            # if the root has a single child, replace the root with the single child
            if node == self.root:
                self.root = node.left if node.left else node.right if node.right else None
            else:
                # every other node in the tree has a parent!
                # we know that the node only has a left or a right child
                if node.parent.left == node:
                    node.parent.left = node.left if node.left else node.right
                elif node.parent.right == node:
                    node.parent.right = node.left if node.left else node.right

# ------------------------------ Question 2 ------------------------------

class TreeNode:

    def __init__(self, key, value, parent=None):

        self.key = key
        self.value = value
        self.left = None
        self.right = None
        self.parent = parent

    def __repr__(self):
        left_key = self.left.key if self.left else None
        right_key = self.right.key if self.right else None
        parent_key = self.parent.key if self.parent else None
        return f"key: {self.key}, value: {self.value}, left: {left_key}, right: {right_key}, parent: {parent_key}"

def rotate_left(node):
    rotation_root = node
    new_root = rotation_root.right

    # Update rotation_root.right to new_root.left
    if new_root.left:
        rotation_root.right = new_root.left
        new_root.left.parent = rotation_root
    else:
        rotation_root.right = None

    # Assign rotation_root as the left child of new_root
    new_root.left = rotation_root

    # Update parent pointers
    new_root.parent = rotation_root.parent
    if rotation_root.parent:
        if rotation_root.parent.left == rotation_root:
            rotation_root.parent.left = new_root
        else:
            rotation_root.parent.right = new_root

    # Update the parent pointer of rotation_root
    rotation_root.parent = new_root

def print_tree(node, level=0):
    if not node:
        return
    indent = " " * (4 * level)
    print(f"{indent}{node}")
    if node.left:
        print_tree(node.left, level + 1)
    if node.right:
        print_tree(node.right, level + 1)

root = TreeNode(10, '10_val')
new_root = TreeNode(20, '20_val', root)
root.right = new_root
new_root.right = TreeNode(30, '30_val', new_root)

print("before rotation: ")
print_tree(root)

rotate_left(root)

print("\nafter rotation: ")
print_tree(new_root)

