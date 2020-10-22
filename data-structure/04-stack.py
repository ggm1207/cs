class Stack:
    def __init__(self):
        self.top = -1
        self.stack_capacity = 1
        self.stack = self._create_stack(self.stack_capacity)

    def _create_stack(self, capacity):
        return [0] * capacity

    def is_full(self):
        return self.top == (self.stack_capacity - 1)

    def is_empty(self):
        return self.top == -1

    def push(self, value):
        if self.is_full():
            new_capacity = self.stack_capacity * 2
            new_stack = self._create_stack(new_capacity)
            new_stack[: self.stack_capacity] = self.stack
            self.stack = new_stack
            self.stack_capacity = new_capacity

        self.top += 1
        self.stack[self.top] = value

    def pop(self):
        if self.is_empty():
            raise IndexError("Stack is Empty!")

        self.top -= 1
        return self.stack[self.top + 1]

    def peek(self):
        if self.is_empty():
            return IndexError("Stack is Empty!")

        return self.stack[self.top]


s = Stack()
s.push(1)
print(s.stack)
s.push(2)
s.push(3)
print(s.stack, s.top)
print(s.pop())
print(s.peek())
print(s.pop())
print(s.stack, s.top)


def check_matching(parenthesis: str) -> bool:
    stack = Stack()
    stack.push(parenthesis[0])
    for p in parenthesis[1:]:
        if stack.peek() == "(" and p == ")":
            try:
                stack.pop()
            except IndexError:
                return False
        else:
            stack.push(p)
    return stack.top == -1


print(check_matching("(())"))
print(check_matching("(()))"))
print(check_matching("(((()))"))


def change_infix_to_postfix(infix: str) -> str:
    s = Stack()
    prec = {"+": 1, "-": 1, "*": 2, "/": 2}
    result = ""
    for ix in infix:
        if ix == "(":
            pass
        elif ix == ")":
            pass
        elif ix in prec.keys():
            while not s.is_empty():
                if prec[s.peek()] >= prec[ix]:
                    result += s.pop()
                else:
                    break

            s.push(ix)
        else:
            result += ix
    
    while not s.is_empty():
        result += s.pop()

    return result

def eval_postfix(postfix: str) -> int:
    s = Stack()
    for ch in postfix:
        if ch in ["+", "-", "/", "*"]:
            l = s.pop()
            r = s.pop()
            s.push(str(eval(l + ch + r)))
        else:
            s.push(ch)

    return s.pop() 

infix = "2+3*4"
print(change_infix_to_postfix(infix))
print(eval_postfix("234*+"))  # not perfect
