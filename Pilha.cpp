#include <iostream>

using namespace std;

struct Stack {
  int top;
  int capacity;
  int *array;
};

Stack* initStack(int capacity) {
  Stack *stack = new Stack();
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = new int[capacity];
  return stack;
}

bool isStackFull(Stack *stack) {
  return stack->top == stack->capacity - 1;
}

bool isStackEmpty(Stack *stack) {
  return stack->top == -1;
}

void push(Stack *stack, int value) {
  if (isStackFull(stack)) {
    cout << "A pilha está cheia!" << endl;
    return;
  }

  stack->array[++stack->top] = value;
}

int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << " Pilha Vazia!" << endl;
    return -1;
  }

  return stack->array[stack->top--];
}

void printStack(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << " Pilha Vazia!" << endl;
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    cout << stack->array[i] << " ";
  }
  cout << endl;
}

int main() {
  int capacity;
  cout << "Diga o tamanho da pilha: ";
  cin >> capacity;
  int n = capacity - 1;

  Stack *stack = initStack(capacity);

  for (int i = 0; i < n; i++) {
    int value;
    cout << "Diga o valor do elemento " << i + 1 << ": ";
    cin >> value;
    push(stack, value);
  }

  printStack(stack);

  int value;
  cout << " Valor do elemento que sera colocado: ";
  cin >> value;
  push(stack, value);

  printStack(stack);

  int removedValue = pop(stack);
  cout << " Elemento removido: " << removedValue << endl;

  printStack(stack);

  delete stack;
  return 0;
}
