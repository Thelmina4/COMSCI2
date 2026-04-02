# Q1

class Node:
    def __init__(self, val):
        self.val = val
        self.next = None

class SinglyLinkedList:

    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def insert_start(self, val):
        node = Node(val)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            node.next = self.head
            self.head = node
        self.size += 1
        return node

    def insert_end(self, val):
        node = Node(val)
        if not self.head:
            self.head = node
            self.tail = node
        else:
            self.tail.next = node
            self.tail = node
        self.size += 1
        return node

    def insert_sorted(self, val):
        node = Node(val)
        if not self.head or val < self.head.val:
            node.next = self.head
            self.head = node
            if not self.tail:
                self.tail = node
        else:
            cur = self.head
            while cur.next and cur.next.val < val:
                cur = cur.next
            node.next = cur.next
            cur.next = node
            if node.next is None:
                self.tail = node
        self.size += 1
        return node

    def remove_start(self):
        if not self.head:
            return None
        val = self.head.val
        self.head = self.head.next
        if not self.head:
            self.tail = None
        self.size -= 1
        return val

    def remove_end(self):
        if not self.head:
            return None
        if self.head == self.tail:
            val = self.head.val
            self.head = None
            self.tail = None
            self.size -= 1
            return val
        cur = self.head
        while cur.next != self.tail:
            cur = cur.next
        val = self.tail.val
        cur.next = None
        self.tail = cur
        self.size -= 1
        return val

    def find(self, val):
        cur = self.head
        while cur:
            if cur.val == val:
                return cur
            cur = cur.next
        return None

    def is_empty(self):
        return self.size == 0

    def __len__(self):
        return self.size

    def display(self):
        cur = self.head
        vals = []
        while cur:
            vals.append(str(cur.val))
            cur = cur.next
        return ' -> '.join(vals)


# Q2
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None
        self._children = []

class Tree:
    def __init__(self, is_binary=True):
        self.is_binary = is_binary
        self.root = None
        self.size = 0

    def set_root(self, val):
        self.root = TreeNode(val)
        self.size = 1
        return self.root

    def is_leaf(self, node):
        if self.is_binary:
            return node.left is None and node.right is None
        return len(node._children) == 0

    def children(self, node):
        if self.is_binary:
            r = []
            if node.left: r.append(node.left)
            if node.right: r.append(node.right)
            return r
        return list(node._children)

    def add_child(self, parent, val):
        if self.is_binary:
            raise ValueError("use insert_left/insert_right for binary trees")
        n = TreeNode(val)
        parent._children.append(n)
        self.size += 1
        return n

    def insert_left(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.left is not None:
            raise ValueError("left already set")
        n = TreeNode(val)
        parent.left = n
        self.size += 1
        return n

    def insert_right(self, parent, val):
        if not self.is_binary:
            raise ValueError("use add_child for general trees")
        if parent.right is not None:
            raise ValueError("right already set")
        n = TreeNode(val)
        parent.right = n
        self.size += 1
        return n

    def preorder(self):
        out = []
        def _pre(n):
            if not n: return
            out.append(n.val)
            if self.is_binary:
                _pre(n.left)
                _pre(n.right)
            else:
                for c in n._children:
                    _pre(c)
        _pre(self.root)
        return out

    def postorder(self):
        out = []
        def _post(n):
            if not n: return
            if self.is_binary:
                _post(n.left)
                _post(n.right)
            else:
                for c in n._children:
                    _post(c)
            out.append(n.val)
        _post(self.root)
        return out

    def inorder(self):
        out = []
        def _in(n):
            if not n: return
            if self.is_binary:
                _in(n.left)
                out.append(n.val)
                _in(n.right)
            else:
                if len(n._children) == 0:
                    out.append(n.val)
                else:
                    _in(n._children[0])
                    out.append(n.val)
                    for c in n._children[1:]:
                        _in(c)
        _in(self.root)
        return out
