def potencia(x, y):
    if y < 0:
        return print("O NÚMERO NÃO PODE SER NEGATIVO")
    elif y==0:
        return 1
    else:
        return x * potencia(x, y - 1)
    
x=2.5
y=2
resultado=potencia(x, y)

print(x,"^",y,"=",resultado)