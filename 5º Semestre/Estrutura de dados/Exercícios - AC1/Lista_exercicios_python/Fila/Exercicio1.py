# Importa a classe File do módulo Fila
from Fila import File

# Define uma função para inverter uma fila
def inverter_fila(fila):
    # Inicializa as variáveis prev e current
    prev = None
    current = fila.first
    
    # Define o último elemento da fila como o primeiro
    fila.last = fila.first
    
    # Loop para inverter a fila
    while current is not None:
        # Armazena o próximo nó antes de alterar a referência
        next_node = current.next
        
        # Inverte a referência do próximo nó para o nó anterior
        current.next = prev
        
        # Atualiza prev para o nó atual e current para o próximo nó
        prev = current
        current = next_node
    
    # Atualiza o primeiro elemento da fila para ser o último nó invertido
    fila.first = prev
