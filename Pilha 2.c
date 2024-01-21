#include <iostream>

using namespace std;

// Estrutura de dados da pilha
struct Stack {
  int top;
  int capacity;
  int *array;
};

// Função para inicializar a pilha
Stack* initStack(int capacity) {
  Stack *stack = new Stack();
  stack->top = -1;
  stack->capacity = capacity;
  stack->array = new int[capacity];
  return stack;
}

// Função para verificar se a pilha está cheia
bool isStackFull(Stack *stack) {
  return stack->top == stack->capacity - 1;
}

// Função para verificar se a pilha está vazia
bool isStackEmpty(Stack *stack) {
  return stack->top == -1;
}

// Função para inserir um elemento na pilha
void push(Stack *stack, int value) {
  if (isStackFull(stack)) {
    cout << "A pilha está cheia!" << endl;
    return;
  }

  stack->array[++stack->top] = value;
}

// Função para remover um elemento da pilha
int pop(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << "A pilha está vazia!" << endl;
    return -1;
  }

  return stack->array[stack->top--];
}

// Função para imprimir a pilha
void printStack(Stack *stack) {
  if (isStackEmpty(stack)) {
    cout << "A pilha está vazia!" << endl;
    return;
  }

  for (int i = stack->top; i >= 0; i--) {
    cout << stack->array[i] << " ";
  }
  cout << endl;
}

int main() {
  // Entrada do usuário
  int capacity;
  cout << "Informe o tamanho da pilha: ";
  cin >> capacity;
  int n = capacity - 1;

  // Inicialização da pilha
  Stack *stack = initStack(capacity);

  // Inserção dos elementos na pilha
  for (int i = 0; i < n; i++) {
    int value;
    cout << "Informe o valor do elemento " << i + 1 << ": ";
    cin >> value;
    push(stack, value);
  }

  // Impressão da pilha inicial
  printStack(stack);

  // Inclusão de um elemento na pilha
  int value;
  cout << "Informe o valor do elemento a ser inserido: ";
  cin >> value;
  push(stack, value);

  // Impressão da pilha após a inclusão
  printStack(stack);

  // Remoção de um elemento da pilha
  int removedValue = pop(stack);
  cout << "O elemento removido foi " << removedValue << endl;

  // Impressão da pilha após a remoção
  printStack(stack);

  // Limpeza da memória
  delete stack;
  return 0;
}
