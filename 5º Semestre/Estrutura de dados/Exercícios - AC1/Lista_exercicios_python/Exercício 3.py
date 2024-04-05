# Leonardo Rossi de Oliveira - RA: 222410

# Function de notação polonesa reversa ( a b + c / ) == ( (a + b)/c )
from Pilha import Pilha

# Avalia se é um number: 'c' é inválido pois é um char
def e_numero(s):
    try:
        float(s)
        return True
    except ValueError:
        return False

# Avalia se é um operador válido: '?' inválido
def e_operador_valido(s):
    return s in ['+', '-', '*', '/']

def avaliar_expressao_notacao_posfixa():
    while True:
        try:
            elements = input("Digite os elementos separando-os por espaços (ex. 2 1 + 3 *): ")
            elements = elements.split()
            pilha = Pilha()
            
            #Tratamentos:  caso a pilha = '' || empty, mostrar erro -> busca do Pilha.py
                        #  caso a pilha = '1 a +' ou 'a 1 +', mostrar o elemento inválido
                        #  caso a pilha = 'first_num +', alertar sobre o numero de operadores insuficientes
            for elemento in elements:
                if e_numero(elemento):
                    pilha.push(float(elemento))
                elif e_operador_valido(elemento):
                    
                    if pilha.is_empty():
                        raise ValueError("Número insuficiente de operandos para o operador '{}'".format(elemento))
                    second_num = pilha.pop()
                    if pilha.is_empty():
                        raise ValueError("Número insuficiente de operandos para o operador '{}'".format(elemento))
                    first_num = pilha.pop()
                    if not e_numero(second_num):
                        raise ValueError("'{}' não é um número válido".format(second_num))
                    if elemento == '+':
                        resultado = first_num + second_num
                    elif elemento == '-':
                        resultado = first_num - second_num
                    elif elemento == '*':
                        resultado = first_num * second_num
                    elif elemento == '/':
                        resultado = first_num / second_num
                    pilha.push(resultado)
                else:
                    raise ValueError("Elemento inválido encontrado: {}".format(elemento))
            if pilha.is_empty():
                raise ValueError("Expressão inválida: não há resultado na pilha")
            resultado_pilha = pilha.pop()
            
            if not pilha.is_empty():
                raise ValueError("Expressão inválida: mais de um resultado na pilha")
            return resultado_pilha
        #exepcion
        except ValueError as e:
            print(e)
# Resultado final caso todos as tratativas forem válidas
print("Resultado final:", avaliar_expressao_notacao_posfixa())

# (["2", "1", "+", "3", "*"])) o resultado será 9
# (["4", "13", "5", "/", "+"])) o resultado será 6.6

# Para o resultado ser int apenas, deve-se substituir "resultado = first_num / second_num" por "resultado = first_num // second_num" pois 13/5 = 2.6 <- float !!!! Não foi específicado ):