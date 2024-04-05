#Leonardo Rossi de Oliveira RA: 222410

from ListaDuplamenteLigada import ListaDuplamenteLigada

def fundir_listas_ordenadas(head_one, head_two):
    if head_one is None:
        return head_two
    elif head_two is None:
        return head_one

    head_mixed = None
    if head_one.value <= head_two.value:
        head_mixed = head_one
        head_one = head_one.next
    else:
        head_mixed = head_two
        head_two = head_two.next

    current = head_mixed

    while head_one and head_two:
        if head_one.value <= head_two.value:
            current.next = head_one
            head_one.prev = current
            head_one = head_one.next
        else:
            current.next = head_two
            head_two.prev = current
            head_two = head_two.next
        current = current.next

    if head_one:
        current.next = head_one
        head_one.prev = current
    elif head_two:
        current.next = head_two
        head_two.prev = current

    while head_mixed.prev:
        head_mixed = head_mixed.prev

    return ordenar_ascendente(head_mixed)

def ordenar_ascendente(head):
    current = head
    while current:
        next_node = current.next
        while next_node:
            if current.value > next_node.value:
                current.value, next_node.value = next_node.value, current.value
            next_node = next_node.next
        current = current.next
    return head

primeiraLista = ListaDuplamenteLigada()
primeiraLista.append(7)
primeiraLista.append(6)
primeiraLista.append(4)
primeiraLista.append(5)

#########################################

segundaLista = ListaDuplamenteLigada()
segundaLista.append(1)
segundaLista.append(8)
segundaLista.append(10)
segundaLista.append(3)
segundaLista.append(9)
segundaLista.append(2)

# Fusão e ordenação
head_mixed = fundir_listas_ordenadas(primeiraLista.head, segundaLista.head)


current = head_mixed
while current:
    print(current.value, end=' => ' if current.next else '')
    current = current.next
print()
