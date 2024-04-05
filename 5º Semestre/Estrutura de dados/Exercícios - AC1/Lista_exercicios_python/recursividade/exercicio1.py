n=5

def somatorio(n):
    if n <= 1:
        return 1
    else:
        return n + somatorio(n-1)
soma=somatorio(n)

print("A SOMA DOS NÚMEROS DE 1 ATÉ",n, "É =", soma)