#Leonardo Rossi de Oliveira RA: 222410

from ListaCircular import ListaCircular

def rotacao(lista, k):
    if lista.head is None:
        return

    tamanho = 1
    current = lista.head
    while current.next != lista.head:
        current = current.next
        tamanho += 1

    k = k % tamanho

    if k == 0:
        return

    for _ in range(k):
        lista.head = lista.head.next





#########################################################

lista = ListaCircular()
lista.insert(1)
lista.insert(2)
lista.insert(3)
lista.insert(4)
lista.insert(5)
#Resposta: 4 -> 5 -> 1 -> 2 -> 3 -> (volta para o início)

k = 3
rotacao(lista, k)
lista.display()