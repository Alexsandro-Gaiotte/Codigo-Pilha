#include <iostream>

using namespace std;

// Estrutura de dados da pilha
struct Stack {
  int top;
  int capacity;
  int *array;
};

// Fun��o para inicializar a pilha
Stack* initStack(int capacity) {
  Stack *stack = new Stack();
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = new int[capacity];
  return stack;
}

// Fun��o para verificar se a pilha est� cheia
bool isStackFull(Stack *stack) {
  return stack->top == stack->capacity - 1;
}

// Fun��o para verificar se a pilha est� vazia
bool isStackEmpty(Stack *stack) {
  return stack->top == -1;
}

// Fun��o para inserir um elemento na pilha
void push(Stack *stack, int value) {
  if (isStackFull(stack)) {
    cout << "A pilha est� cheia!" << endl;
    return;
  }

  stack->array[++stack->top] = value;
}

// Fun��o para remover um elemento da pilha
int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << "A pilha est� vazia!" << endl;
    return -1;
  }

  return stack->array[stack->top--];
}

// Fun��o para imprimir a pilha
void printStack(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << "A pilha est� vazia!" << endl;
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    cout << stack->array[i] << " ";
  }
  cout << endl;
}

int main() {
  // Entrada do usu�rio
  int capacity;
  cout << "Informe o tamanho da pilha: ";
  cin >> capacity;
  int n = capacity - 1;

  // Inicializa��o da pilha
  Stack *stack = initStack(capacity);

  // Inser��o dos elementos na pilha
  for (int i = 0; i < n; i++) {
    int value;
    cout << "Informe o valor do elemento " << i + 1 << ": ";
    cin >> value;
    push(stack, value);
  }

  // Impress�o da pilha inicial
  printStack(stack);

  // Inclus�o de um elemento na pilha
  int value;
  cout << "Informe o valor do elemento a ser inserido: ";
  cin >> value;
  push(stack, value);

  // Impress�o da pilha ap�s a inclus�o
  printStack(stack);

  // Remo��o de um elemento da pilha
  int removedValue = pop(stack);
  cout << "O elemento removido foi " << removedValue << endl;

  // Impress�o da pilha ap�s a remo��o
  printStack(stack);

  // Limpeza da mem�ria
  delete stack;
  return 0;
}
