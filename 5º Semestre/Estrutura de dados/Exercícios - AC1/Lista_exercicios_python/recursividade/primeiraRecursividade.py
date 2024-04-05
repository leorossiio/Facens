n=5
def fatorial(n: int) -> int:
    if n == 1 or n == 0:
        return 1
    else:
        return n * fatorial(n - 1)

print(n)
