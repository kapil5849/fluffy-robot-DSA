Sure, here is the code to remove duplicates from an unsorted linked list:

```python
class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

def remove_duplicates(head):
  current = head
  seen = set()
  while current:
    if current.data in seen:
      current.next = current.next.next
    else:
      seen.add(current.data)
      current = current.next

  return head

def main():
  head = Node(1)
  head.next = Node(2)
  head.next.next = Node(3)
  head.next.next.next = Node(2)
  head.next.next.next.next = Node(1)

  new_head = remove_duplicates(head)

  while new_head:
    print(new_head.data)
    new_head = new_head.next

if __name__ == "__main__":
  main()
```

This code works by maintaining a set of seen elements. As the algorithm iterates through the linked list, it checks if the current element is in the set. If it is, then the algorithm removes the current element from the linked list. Otherwise, the algorithm adds the current element to the set and continues iterating.

The time complexity of this algorithm is O(n), where n is the number of elements in the linked list. This is because the algorithm has to iterate through the linked list once.

The space complexity of this algorithm is O(n), where n is the number of elements in the linked list. This is because the algorithm needs to store the set of seen elements, which can take up to n elements.

**Follow up:**

If a temporary buffer is not allowed, then the algorithm can be modified to use a **dummy node**. The dummy node is a node that is inserted before the head of the linked list. The algorithm then iterates through the linked list, and if the current element is already in the linked list, then the algorithm removes the current element and the dummy node. Otherwise, the algorithm moves the dummy node to the next element in the linked list.

The time complexity of this algorithm is O(n), where n is the number of elements in the linked list. This is because the algorithm has to iterate through the linked list once.

The space complexity of this algorithm is O(1), because the algorithm does not need to store any additional data.