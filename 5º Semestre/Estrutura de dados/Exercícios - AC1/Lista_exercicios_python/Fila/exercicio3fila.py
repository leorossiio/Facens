#Leonardo Rossi de Oliveira RA: 222410

from Node import node  # Import a classe Node do modulo Node

# Definição da classe Fila
class Fila:
    def __init__(self):
        # inicializa os atributos first e last como None
        self.first = None  
        self.last = None
        
    def fila_vazia(self):
        # Verifica se a fila esta vazia
        return self.first is None
    
    def olhar(self):
        # Retorna o valor do primeiro elemento da fila
        if not self.fila_vazia():
            return self.first.value
        return None
    
    def enfileirar(self, value):
        # Adiciona um novo elemento à fila através dos nós
        new_node = node(value)
        if self.last is None:
            self.first = self.last = new_node
            return
        self.last.next = new_node
        self.last = new_node

    def desenfileirar(self):
        # Remove e retorna o primeiro elemento da fila
        if self.fila_vazia():
            return None
        no_removido = self.first
        self.first = self.first.next
        if self.first is None:
            self.last = None
        return no_removido.value

# Função para reorganizar a fila
def reorganizar(fila):
    # Verifica se a fila está vazia ou possui apenas um elemento
    if fila.fila_vazia() or fila.first.next is None:
        return
    
    # Calcula o número de elementos na fila
    numero_elementos = 0
    temp = fila.first
    while temp:
        numero_elementos += 1
        temp = temp.next
   
    # Se o número de elementos for par ele faz o processo de reorganizar a fila
    if numero_elementos % 2 == 0:
        meio = numero_elementos // 2
        pilha = []
        # Empilha a metade inicial dos elementos da fila
        for _ in range(meio):
            pilha.append(fila.desenfileirar())
        # Reorganiza a fila intercalando os elementos da pilha e da fila
        while pilha:
            fila.enfileirar(pilha.pop(0))
            fila.enfileirar(fila.desenfileirar())
 
    # Se o número de elementos for ímpar ele faz o tratamento adicionando mais um elemento e faz o mesmo processo acima
    else:
        meio = numero_elementos // 2 + 1
        pilha = []
        # Empilha a primeira metade dos elementos da fila
        for _ in range(meio):
            pilha.append(fila.desenfileirar())
        # Reorganiza a fila intercalando os elementos da pilha e da fila
        while pilha:
            fila.enfileirar(pilha.pop(0))
            if pilha:
                fila.enfileirar(fila.desenfileirar())


# Cria uma fila
fila = Fila()

# Solicita o número de elementos a serem inseridos na fila
while True:
    try:
        numero_elementos = int(input("Quantos elementos serão inseridos na fila? (Digite apenas números inteiros): "))
        break
    except ValueError:
        print("Valor inválido. Por favor, insira um número inteiro.")

# Insere os elementos na fila
for i in range(numero_elementos):
    while True:
        try:
            elemento = int(input(f"Informe o elemento na posição {i+1}: "))
            fila.enfileirar(elemento)
            break 
        except ValueError:
            print("Entrada inválida. Por favor, insira um número inteiro.")

# Exibe a sequência original
print("Sequência digitada:", end=" ")
temp_fila = Fila()
temp = fila.first
while temp:
    print(temp.value, end="")
    temp_fila.enfileirar(temp.value)
    if temp.next is not None:
        print(" - ", end="")
    temp = temp.next

# Chama a função de reorganizar fila
reorganizar(fila)

# Exibe a sequência reorganizada
print("\nSequência reorganizada:", end=" ")
while not fila.fila_vazia():
    print(fila.desenfileirar(), end="")
    if not fila.fila_vazia():
        print(" - ", end="")