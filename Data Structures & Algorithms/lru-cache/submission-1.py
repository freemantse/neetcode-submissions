class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}
        self.left, self.right = Node(0,0), Node(0,0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node) -> None:
        prev, next = node.prev, node.next
        prev.next, next.prev = next, prev
        node.prev, node.next = None, None

    def insert(self, node) -> None:
        prev, next = self.right.prev, self.right
        prev.next = next.prev = node
        node.prev, node.next = prev, next

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        
        self.remove(self.cache[key])
        self.insert(self.cache[key])
        return self.cache[key].val

    def put(self, key: int, value: int) -> None:
        if (key in self.cache):
            self.remove(self.cache[key])
        
        node = Node(key, value)
        self.cache[key] = node
        self.insert(node)

        if (len(self.cache) > self.capacity):
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]
