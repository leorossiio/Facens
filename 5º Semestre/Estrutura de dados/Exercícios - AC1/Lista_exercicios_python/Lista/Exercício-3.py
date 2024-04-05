#Leonardo Rossi de Oliveira RA: 222410

from ListaCircular import ListaCircular

def rotate(lista, k):
    if lista.head is None:
        return

    size = 1
    current = lista.head
    while current.next != lista.head:
        current = current.next
        size += 1

    k = k % size

    if k == 0:
        return

    for _ in range(k):
        lista.head = lista.head.next

# Exemplo de uso
lista = ListaCircular()
lista.insert(1)
lista.insert(2)
lista.insert(3)
lista.insert(4)
lista.insert(5)

k = 3
rotate(lista, k)
lista.display()