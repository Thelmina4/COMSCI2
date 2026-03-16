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

    def upsert(self, key, val):

        if not self.root:
            self.root = Position(key, val)
            return self.root

        def _upsert(key, val, node, parent=None):

            if not node:
                return Position(key, val, parent)

            if key < node.key:
                node.left = _upsert(key, val, node.left, node)
            elif key > node.key:
                node.right = _upsert(key, val, node.right, node)
            else:
                node.value = val

            return node

        return _upsert(key, val, self.root)

    def find(self, key, node=None):

        if not node:
            node =  self.root

        if key < node.key:
            return self.find(key, node.left)
        elif key > node.key:
            return self.find(key, node.right)
        else:
            return node

    def first(self):
        if not self.root:
            return None

        def _first(node):
            if not node.left:
                return node
            return _first(node.left)

        return _first(self.root)

    def last(self, node=None):

        if not node:
            node = self.root

        if not node:
            return None

        def _last(node):
            if not node.right:
                return node
            return _last(node.right)

        return _last(node)

    def before(self, node):

        if not node:
            return None

        if node.left:
            return self.last(node.left)

        def _before(node):

            if not node or not node.parent:
                return None

            if node.parent.right == node:
                return node.parent

            return _before(node.parent)

        return _before(node)

    def print_tree(self):
        def display(node):
            """Return list of strings, width, height, and horizontal coordinate of root."""
            if node is None:
                return [], 0, 0, 0

            line = f"{node.key}({node.value})"
            width = len(line)

            left_lines, left_width, left_height, left_middle = display(node.left)
            right_lines, right_width, right_height, right_middle = display(node.right)

            first_line = second_line = ""
            if left_width > 0:
                first_line += " " * (left_middle + 1)
                first_line += "_" * (left_width - left_middle - 1)
                second_line += " " * left_middle + "/" + " " * (left_width - left_middle - 1)
            first_line += line
            second_line += " " * width
            if right_width > 0:
                first_line += "_" * right_middle + " " * (right_width - right_middle)
                second_line += " " * right_middle + "\\" + " " * (right_width - right_middle - 1)

            # Combine subtrees
            if left_height < right_height:
                left_lines += [" " * left_width] * (right_height - left_height)
            elif right_height < left_height:
                right_lines += [" " * right_width] * (left_height - right_height)

            zipped = zip(left_lines, right_lines)
            lines = [first_line, second_line] + [l + " " * width + r for l, r in zipped]
            return lines, left_width + width + right_width, max(left_height, right_height) + 2, left_width + width // 2

        lines, *_ = display(self.root)
        print("\n".join(lines))
