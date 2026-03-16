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

    # -------- is_balanced (O(n)) --------
    def is_balanced(self):
        """
        A tree is balanced if, for every node, the height difference
        between left and right subtrees is at most 1.
        """

        def check(node):
            if node is None:
                return 0  # height
            left_h = check(node.left)
            if left_h == -1:
                return -1
            right_h = check(node.right)
            if right_h == -1:
                return -1

            if abs(left_h - right_h) > 1:
                return -1
            return max(left_h, right_h) + 1

        return check(self) != -1

    # -------- is_bst (O(n)) --------
    def is_bst(self):
        """
        Verify that this tree satisfies the strict BST property:
        For every node:
          - all keys in left subtree are < node.key
          - all keys in right subtree are > node.key
        """
        def check(node, min_key, max_key):
            if node is None:
                return True

            if (min_key is not None and node.key <= min_key) or \
               (max_key is not None and node.key >= max_key):
                return False

            return (check(node.left, min_key, node.key) and
                    check(node.right, node.key, max_key))

        return check(self, None, None)

    # -------- iterative inorder traversal --------
    def inorder_iterative(self):
        """
        Returns a list of (key, value) in inorder without recursion.
        """
        result = []
        stack = []
        current = self

        while stack or current:
            # reach leftmost
            while current:
                stack.append(current)
                current = current.left

            current = stack.pop()
            result.append((current.key, current.value))
            current = current.right

        return result

    # -------- print all root-to-leaf paths --------
    def print_paths(self):
        """
        Print all root-to-leaf paths from this node.
        Uses DFS with an explicit path list.
        """
        path = []

        def dfs(node):
            if not node:
                return

            path.append(node.key)

            # leaf: no children
            if not node.left and not node.right:
                print(" -> ".join(map(str, path)))
            else:
                dfs(node.left)
                dfs(node.right)

            path.pop()

        dfs(self)


def rotate_left(node):
    rotation_root = node
    new_root = rotation_root.right
    if not new_root:
        return  # nothing to rotate

    # move new_root.left to rotation_root.right
    if new_root.left:
        rotation_root.right = new_root.left
        new_root.left.parent = rotation_root
    else:
        rotation_root.right = None

    # rotation_root becomes left child of new_root
    new_root.left = rotation_root

    # hook new_root to rotation_root's old parent
    new_root.parent = rotation_root.parent
    if rotation_root.parent:
        if rotation_root.parent.left == rotation_root:
            rotation_root.parent.left = new_root
        else:
            rotation_root.parent.right = new_root

    # update rotation_root parent
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


# ---------- Tests ----------

# Build:
#     10
#       \
#        20
#          \
#           30
root = TreeNode(10, '10_val')
node20 = TreeNode(20, '20_val', root)
root.right = node20
node30 = TreeNode(30, '30_val', node20)
node20.right = node30

# Test is_balanced
print("\nIs the tree balanced (Initially)?")
print(root.is_balanced(), end="\n\n")

# Test is_bst (Initially)
print("Is the tree a valid BST (Initially)?")
print(root.is_bst(), end="\n\n")

print("before rotation:")
print_tree(root)

# Left rotate at 10 -> 20 becomes new root of that subtree
rotate_left(root)

# Find actual root after rotation (walk up from any node)
new_root = node20
while new_root.parent:
    new_root = new_root.parent

print("\nafter rotation:")
print_tree(new_root)

# Test is_balanced
print("\nIs the tree balanced (after rotation)?")
print(new_root.is_balanced())

# Test is_bst (after rotation)
print("\nIs the tree a valid BST (after rotation)?")
print(new_root.is_bst())

# Test iterative inorder
print("\nIterative inorder traversal from new_root:")
print(new_root.inorder_iterative())

# Test printing all root-to-leaf paths
print("\nAll root-to-leaf paths:")
new_root.print_paths()

# sample output

# Is the tree balanced (Initially)?
# False
#
# Is the tree a valid BST (Initially)?
# True
#
# before rotation:
# key: 10, value: 10_val, left: None, right: 20, parent: None
#     key: 20, value: 20_val, left: None, right: 30, parent: 10
#         key: 30, value: 30_val, left: None, right: None, parent: 20
#
# after rotation:
# key: 20, value: 20_val, left: 10, right: 30, parent: None
#     key: 10, value: 10_val, left: None, right: None, parent: 20
#     key: 30, value: 30_val, left: None, right: None, parent: 20
#
# Is the tree balanced (after rotation)?
# True
#
# Is the tree a valid BST (after rotation)?
# True
#
# Iterative inorder traversal from new_root:
# [(10, '10_val'), (20, '20_val'), (30, '30_val')]
#
# All root-to-leaf paths:
# 20 -> 10
# 20 -> 30


# ---------------------- Questions 2 and 3 --------------------------------------
def basic_hash(str):

    hash_code = 0

    for i in str:
        hash_code += ord(i)

    return hash_code

def position_hash(str):

    hash_code = 0

    prime = 13
    for i in range(len(str)):
        hash_code += (ord(str[i]) * (prime**i))

    return hash_code

def insert(str, buckets):

    index = basic_hash(str) % len(buckets)

    buckets[index].append(str)

def insert_position_hash(str, buckets):

    index = position_hash(str) % len(buckets)

    buckets[index].append(str)

if __name__ == '__main__':

    # mimic a bucket array using the following:
    buckets = [[] for _ in range(10)]

    insert('stop', buckets)
    insert('tops', buckets)
    insert('pots', buckets)
    insert('spot', buckets)

    print(buckets)

    buckets = [[] for _ in range(11)]

    insert_position_hash('stop', buckets)
    insert_position_hash('tops', buckets)
    insert_position_hash('pots', buckets)
    insert_position_hash('spot', buckets)

    print(buckets)