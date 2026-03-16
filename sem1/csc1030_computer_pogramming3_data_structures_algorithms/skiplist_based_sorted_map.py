import random
from datetime import datetime, timedelta


class SkipListNode:

    def __init__(self, key, value, level_count):
        self.key = key
        self.value = value
        # next_node_per_level[i] points to the next node at level i
        self.next_node_per_level = [None] * (level_count + 1)


class SkipListMap:
    """
    A sorted map implemented using a skip list.
    - Keys must be comparable.
    - Expected time complexities:
        * get(key):    O(log n)
        * put(key,v):  O(log n)
        * delete(key): O(log n)
    - Maintains sorted order at the lowest level for range queries.
    """

    def __init__(self, max_level=16, promotion_probability=0.5):
        self._max_level = max_level
        self._promotion_probability = promotion_probability
        self._header = SkipListNode(None, None, max_level)
        self._current_level = 0
        self._size = 0

    def __len__(self):
        return self._size

    def __repr__(self):
        items = []
        node = self._header.next_node_per_level[0]
        while node:
            items.append((node.key, node.value))
            node = node.next_node_per_level[0]
        return f"SkipListMap({items!r})"

    # ---------- internal helpers ----------

    def _generate_random_level(self):
        """
        Randomly determine how many levels the new node should occupy.
        """
        level = 0
        while random.random() < self._promotion_probability and level < self._max_level:
            level += 1
        return level

    def _find_predecessor_nodes(self, search_key):
        """
        Walks from top to bottom and collects the last node
        before `search_key` at each level.
        """
        predecessors = [None] * (self._max_level + 1)
        current_node = self._header

        for level in range(self._current_level, -1, -1):
            while True:
                next_node = current_node.next_node_per_level[level]
                if next_node is not None and next_node.key < search_key:
                    current_node = next_node
                else:
                    break
            predecessors[level] = current_node

        return predecessors

    def get(self, search_key, default=None):
        """
        Return the value for `search_key`, or default if not found.
        """
        current_node = self._header

        # Move top-down until the key is found or end reached
        for level in range(self._current_level, -1, -1):
            while True:
                next_node = current_node.next_node_per_level[level]
                if next_node is not None and next_node.key < search_key:
                    current_node = next_node
                else:
                    break

        current_node = current_node.next_node_per_level[0]
        if current_node is not None and current_node.key == search_key:
            return current_node.value
        return default

    def put(self, key, value):
        """
        Insert or update a (key, value) pair while keeping the skip list balanced.
        """
        predecessors = self._find_predecessor_nodes(key)
        next_node = predecessors[0].next_node_per_level[0]

        # Key exists → update value
        if next_node is not None and next_node.key == key:
            next_node.value = value
            return

        # Otherwise insert a new node
        new_node_level = self._generate_random_level()

        if new_node_level > self._current_level:
            # Initialize unused predecessor levels to the header node
            for level in range(self._current_level + 1, new_node_level + 1):
                predecessors[level] = self._header
            self._current_level = new_node_level

        new_node = SkipListNode(key, value, new_node_level)

        # Update forward pointers for each level
        for level in range(new_node_level + 1):
            new_node.next_node_per_level[level] = predecessors[level].next_node_per_level[level]
            predecessors[level].next_node_per_level[level] = new_node

        self._size += 1

    def delete(self, key):
        """
        Delete a key if it exists. Returns True if deleted, False if not found.
        """
        predecessors = self._find_predecessor_nodes(key)
        target_node = predecessors[0].next_node_per_level[0]

        if target_node is None or target_node.key != key:
            return False

        for level in range(self._current_level + 1):
            if predecessors[level].next_node_per_level[level] is target_node:
                predecessors[level].next_node_per_level[level] = target_node.next_node_per_level[level]

        # Reduce current level if top levels are now empty
        while self._current_level > 0 and self._header.next_node_per_level[self._current_level] is None:
            self._current_level -= 1

        self._size -= 1
        return True

    def range(self, start_key, end_key):
        """
        Return all (key, value) pairs with start_key <= key <= end_key.
        """
        results = []
        predecessors = self._find_predecessor_nodes(start_key)
        current_node = predecessors[0].next_node_per_level[0]

        if current_node is not None and current_node.key < start_key:
            current_node = current_node.next_node_per_level[0]

        while current_node is not None and current_node.key <= end_key:
            if current_node.key >= start_key:
                results.append((current_node.key, current_node.value))
            current_node = current_node.next_node_per_level[0]

        return results


# ---------- identical test suite ----------

def _print_header(title):
    print("\n" + "=" * 40)
    print(title)
    print("=" * 40)


def run_tests():
    sm = SkipListMap()

    base = datetime(2024, 1, 1, 9, 0)
    t0 = base
    t1 = base + timedelta(minutes=30)
    t2 = base + timedelta(minutes=60)
    t3 = base + timedelta(minutes=90)

    _print_header("Insert in non-sorted order (should be stored sorted)")
    sm.put(t2, "event-10:00")
    sm.put(t0, "event-09:00")
    sm.put(t1, "event-09:30")
    print(sm)

    # Collect keys in order
    node = sm._header.next_node_per_level[0]
    keys = []
    while node:
        keys.append(node.key)
        node = node.next_node_per_level[0]

    assert len(sm) == 3
    assert keys == [t0, t1, t2]

    _print_header("Lookup existing keys")
    print("t0:", sm.get(t0))
    print("t1:", sm.get(t1))
    print("t2:", sm.get(t2))
    assert sm.get(t0) == "event-09:00"
    assert sm.get(t1) == "event-09:30"
    assert sm.get(t2) == "event-10:00"

    _print_header("Lookup missing key")
    print("t3:", sm.get(t3))
    assert sm.get(t3) is None

    _print_header("Overwrite existing key")
    sm.put(t1, "updated-09:30")
    print(sm)
    assert sm.get(t1) == "updated-09:30"

    _print_header("Range query [09:15, 10:00]")
    r_start = base + timedelta(minutes=15)
    r_end = base + timedelta(minutes=60)
    results = sm.range(r_start, r_end)
    for k, v in results:
        print(k, "->", v)
    assert [k for k, _ in results] == [t1, t2]

    _print_header("Delete existing key")
    ok = sm.delete(t1)
    print("deleted t1:", ok)
    print(sm)
    assert ok is True
    assert sm.get(t1) is None

    _print_header("Delete missing key")
    ok = sm.delete(t3)
    print("deleted t3:", ok)
    assert ok is False

    _print_header("Final state")
    print(sm)

    print("\nAll checks passed (if you saw no assertion errors).")


if __name__ == "__main__":
    run_tests()
