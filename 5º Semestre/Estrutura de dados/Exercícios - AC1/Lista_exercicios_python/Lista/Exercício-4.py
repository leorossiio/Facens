#Leonardo Rossi de Oliveira RA: 222410

from ListaDuplamenteLigada import ListaDuplamenteLigada

def fundir_listas_ordenadas(head1, head2):
    if not head1:
        return head2
    elif not head2:
        return head1

    head_mesclado = None
    if head1.value <= head2.value:
        head_mesclado = head1
        head1 = head1.next
    else:
        head_mesclado = head2
        head2 = head2.next

    current = head_mesclado

    while head1 and head2:
        if head1.value <= head2.value:
            current.next = head1
            head1.prev = current
            head1 = head1.next
        else:
            current.next = head2
            head2.prev = current
            head2 = head2.next
        current = current.next

    if head1:
        current.next = head1
        head1.prev = current
    elif head2:
        current.next = head2
        head2.prev = current

    while head_mesclado.prev:
        head_mesclado = head_mesclado.prev

    return ordenar_ascendente(head_mesclado)

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

segundaLista = ListaDuplamenteLigada()
segundaLista.append(1)
segundaLista.append(8)
segundaLista.append(3)
segundaLista.append(9)
segundaLista.append(2)

# Fusão e ordenação
head_mesclado = fundir_listas_ordenadas(primeiraLista.head, segundaLista.head)


current = head_mesclado
while current:
    print(current.value, end=' -> ' if current.next else '')
    current = current.next
print()
