import unittest

class Node:

    def __init__(self, val, next=None):
        self.val = val
        self.next = next

class Position:

    def __init(self, node):
        self.node = node

    def element(self):
        return self.node.val if self.node else None

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

        return Position(node)

    def remove_last(self):

        if self.size == 0:
            return None

        # only a single element
        if self.head == self.tail:
            node = self.head
            self.head = None
            self.tail = None
            self.size -= 1
            return node

        current = self.head
        while current.next.next:
            current = current.next

        node = current.next
        current.next = None
        self.tail = current
        self.size -= 1

        return node

ll = SinglyLinkedList()
p1 = ll.insert_start("A")
ll.insert_after(p1, "B")
p1.element()

class LinkedListTest(unittest.TestCase):

    def setUp(self):
        pass

    def test_insert_start_empty(self):

        ll = SinglyLinkedList()
        ll.insert_start('A')
        self.assertEqual(ll.size, 1)
        self.assertIsNotNone(ll.head)
        self.assertEqual(ll.head, ll.tail)

    def test_insert_start__not_empty(self):

        ll = SinglyLinkedList()
        ll.insert_start('A')
        ll.insert_start('B')
        self.assertEqual(ll.size, 2)
        self.assertIsNotNone(ll.head)
        self.assertTrue(ll.head != ll.tail)