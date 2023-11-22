class stack:
    def __init__(self , max_size):
        self.max_size = max_size
        self.stack = []
        
    def is_empty(self):
        return len(self.stack) == 0
    
    def is_full(self):
        return len(self.stack) == self.max_size
    
    def push(self , item):
        if not self.is_full():
            self.stack.append(item)
            
        else:
            print("Stack Overflow")
            
    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        
        else:
            print("Stack Underflow")
            return None
        
    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        
        else:
            print("Stack is empty")
            
    def size_stack(self):
        return len(self.stack)
    

my_stack = stack(3)

my_stack.push(1)
my_stack.push(2)
my_stack.push(3)

print("Top element",my_stack.peek()) # 3
print("Size of stack",my_stack.size_stack()) # 3

print(my_stack.pop()) # 3 
print(my_stack.pop()) # 2

print("Top element",my_stack.peek()) # 1
print("Size of stack",my_stack.size_stack()) # 1
