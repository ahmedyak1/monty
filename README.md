# 0x19. C - Stacks, Queues - LIFO, FIFO


---
#### Task 0. push, pall
Implement the push and pall opcodes.
The push opcode
The opcode push pushes an element to the stack.
Usage : push
where is an integer
if is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
where is the line number in the file
You won’t have to deal with overflows. Use the atoi function

#### Task 1. pint
Implement the pint opcode.
The pint opcode
The opcode pint prints the value at the top of the stack, followed by a new line.
Usage: pint
If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

#### Task 2. pop
Implement the pop opcode.
The pop opcode
The opcode pop removes the top element of the stack.
Usage: pop
If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

#### Task 3. swap
Implement the swap opcode.
The swap opcode
The opcode swap swaps the top two elements of the stack.
Usage: swap
If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

#### Task 4. add
Implement the add opcode.
The add opcode
The opcode add adds the top two elements of the stack.
Usage: add
If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
The top element of the stack contains the result
The stack is one element shorter

#### Task 5. nop
Implement the nop opcode.
The nop opcode
The opcode nop doesn’t do anything.
Usage: nop

