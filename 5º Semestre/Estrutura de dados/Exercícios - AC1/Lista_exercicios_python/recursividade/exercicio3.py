def fibonacci(n):
      if n <= 1:
          return n
      else:
          return fibonacci(n - 1) + fibonacci(n - 2)
n = 5
resultado = fibonacci(n)
print(resultado)