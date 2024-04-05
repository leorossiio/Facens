from Fila import Fila

def gerar_binarios(n):
    fila = Fila()
    fila.push("1")
    resultado = []
    
    for _ in range(n):
        numero_atual = fila.pop()
        resultado.append(numero_atual)
        fila.push(numero_atual + "0")
        fila.push(numero_atual + "1")
    return resultado