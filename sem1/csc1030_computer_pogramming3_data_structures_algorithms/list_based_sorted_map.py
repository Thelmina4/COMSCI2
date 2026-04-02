from datetime import datetime, timedelta


class SortedMap:
    """
    Sorted map backed by a Python list of (key, value) pairs.
    - Keys must be comparable (support <, ==).
    - Stored in strictly ascending key order.
    """

    def __init__(self):
        self._data = []  # list[(key, value)]

    def __len__(self):
        return len(self._data)

    def __repr__(self):
        return f"SortedMap({self._data!r})"

    # ---------- internal: binary search for index ----------

    def _find_index(self, key):
        """
        Returns the index where `key` is or should be inserted.
        If key exists, index may be that exact position.
        If not, index is the insertion point to keep order.
        """
        low = 0
        high = len(self._data) - 1

        while low <= high:
            mid = (low + high) // 2
            mid_key, _ = self._data[mid]

            if mid_key == key:
                return mid
            elif key < mid_key:
                high = mid - 1
            else:
                low = mid + 1

        return low  # insertion point

    def get(self, key, default=None):
        """
        Return value for key, or default if not found.
        """
        i = self._find_index(key)
        if i < len(self._data) and self._data[i][0] == key:
            return self._data[i][1]
        return default

    def put(self, key, value):
        """
        Insert or update (key, value) while preserving sort order.
        Overwrites if key already exists.
        """
        i = self._find_index(key)
        if i < len(self._data) and self._data[i][0] == key:
            self._data[i] = (key, value)
        else:
            self._data.insert(i, (key, value))

    def delete(self, key):
        """
        Delete key if present. Return True if deleted, False otherwise.
        """
        i = self._find_index(key)
        if i < len(self._data) and self._data[i][0] == key:
            self._data.pop(i)
            return True
        return False

    def range(self, start, end):
        """
        Return list of (key, value) with start <= key <= end in sorted order.
        """
        result = []
        i = self._find_index(start)

        while i < len(self._data):
            k, v = self._data[i]
            if k > end:
                break
            if k >= start:
                result.append((k, v))
            i += 1

        return result


def _print_header(title):
    print("\n" + "=" * 40)
    print(title)
    print("=" * 40)


def run_tests():
    sm = SortedMap()

    # helper timestamps
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

    assert len(sm) == 3
    assert sm._data[0][0] == t0
    assert sm._data[1][0] == t1
    assert sm._data[2][0] == t2

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
    res = sm.range(r_start, r_end)
    for k, v in res:
        print(k, "->", v)
    # Expect keys >= 09:15 and <= 10:00, so t1 and t2
    assert [k for k, _ in res] == [t1, t2]

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
