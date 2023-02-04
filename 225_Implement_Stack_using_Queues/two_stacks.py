class MyQueue:

    def __init__(self):
        self.lst = []
    
    def enqueue(self, x: int) -> None:
        self.lst.append(x)

    def dequeue(self) -> int:
        return self.lst.pop(0)

    def top(self) -> int:
        return self.lst[0]
    
    def empty(self) -> bool:
        return len(self.lst) == 0

    def size(self) -> int:
        return len(self.lst)

class MyStack:

    def __init__(self):
        self.q1, self.q2 = MyQueue(), MyQueue()

    def push(self, x: int) -> None:
        if not self.q1.empty():
            self.q1.enqueue(x)
        else:
            self.q2.enqueue(x)

    def pop(self) -> int:
        if not self.q1.empty():
            while self.q1.size() > 1:
                self.q2.enqueue(self.q1.dequeue())
            return self.q1.dequeue()
        else:
            while self.q2.size() > 1:
                self.q1.enqueue(self.q2.dequeue())
            return self.q2.dequeue()

    def top(self) -> int:
        temp = self.pop()
        self.push(temp)
        return temp

    def empty(self) -> bool:
        return self.q1.empty() and self.q2.empty()
        


# Your MyStack object will be instantiated and called as such:
obj = MyStack()
obj.push(1)
obj.push(2)
print(obj.pop())
print(obj.empty())
obj.push(3)
print(obj.pop())
print(obj.pop())
print(obj.empty())

# obj = MyQueue()
# obj.enqueue(1)
# print(obj.dequeue())
# print(obj.empty())
# obj.enqueue(2)
# obj.enqueue(3)
# print(obj.top())
# print(obj.dequeue())
# print(obj.dequeue())
