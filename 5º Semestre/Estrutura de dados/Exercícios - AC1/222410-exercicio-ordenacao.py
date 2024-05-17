#Leonardo Rossi de OLiveira 222410

def construtor_list():
    numbers = []
    while True:
        try:
            number = input("Digite um número para adicionar à list: ")
            if not number.isdigit():  # Verifica se a entrada é int
                raise ValueError("Opção inválida, digite apenas números inteiros.")
            numbers.append(int(number))
            proceed = input("Deseja adicionar mais números? (sim/não): ")
            if proceed.lower() != 'sim' and proceed.lower() != 'não':
                raise ValueError("Por favor, responda 'sim' ou 'não'.")
            elif proceed.lower() == 'não' and len(numbers) == 1:
                print("Não é possível ordenar apenas um número.")
                proceed = 'sim'
            if proceed.lower() != 'sim':
                break
        except ValueError as e:
            print(e)
    return numbers


def insertion_sort(numbers, reverse=False):
    # Insertion Sort
    for i in range(1, len(numbers)):
        key = numbers[i]
        j = i - 1
        while j >= 0 and numbers[j] > key:
            numbers[j + 1] = numbers[j]
            j -= 1
        numbers[j + 1] = key
    if reverse:
        numbers.reverse()
    return numbers


def quick_sort(numbers, reverse=False):
    # Quick Sort
    def quicksort_helper(low, high):
        if low < high:
            pi = partition(low, high)
            quicksort_helper(low, pi - 1)
            quicksort_helper(pi + 1, high)

    def partition(low, high):
        pivot = numbers[high]
        i = low - 1
        for j in range(low, high):
            if numbers[j] <= pivot:
                i += 1
                numbers[i], numbers[j] = numbers[j], numbers[i]
        numbers[i + 1], numbers[high] = numbers[high], numbers[i + 1]
        return i + 1

    quicksort_helper(0, len(numbers) - 1)
    if reverse:
        numbers.reverse()
    return numbers 


def bubble_sort(numbers, reverse=False):
    # Bubble Sort
    n = len(numbers)
    for i in range(n):
        changed = False
        for j in range(0, n - i - 1):
            if numbers[j] > numbers[j + 1]:
                numbers[j], numbers[j + 1] = numbers[j + 1], numbers[j]
                changed = True
        if not changed:
            break 
    if reverse:
        numbers.reverse()
    return numbers 


def main():
    numbers = construtor_list()

    print("\nEscolha o método de ordenação:")
    print("1. Bubble Sort\n2. Insertion Sort\n3. Quick Sort")

    while True:
        try:
            choice = int(input("Digite sua escolha: "))
            if choice in [1, 2, 3]:
                break
            else:
                print("Escolha inválida. Digite 1, 2 ou 3.")
        except ValueError:
            print("Escolha inválida. Digite 1, 2 ou 3.")

    while True:
        order = input("Deseja ordenar em ordem crescente ou decrescente? (crescente/decrescente): ")
        if order.lower() in ['crescente', 'decrescente']:
            break
        else:
            print("Opção inválida.")

    if choice == 1:
        numbers_ordered = bubble_sort(numbers, order.lower() == 'decrescente')
    elif choice == 2:
        numbers_ordered = insertion_sort(numbers, order.lower() == 'decrescente')
    elif choice == 3:
        numbers_ordered = quick_sort(numbers, order.lower() == 'decrescente')

    print(f"\nLista ordenada: [{', '.join(map(str, numbers_ordered))}]")


if __name__ == "__main__":
    main()