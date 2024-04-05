# Função para remover espaços, pontuações e converter tudo para lowercase
def conversor_variavel(s):
    # Salva a string original
    s_original = s
    
    # Remove espaços e pontuações, converte para lowercase
    s_sem_espacos = ''.join(c.lower() for c in s if c.isalnum())
    
    # Verifica se a string sem espaços é um palíndromo usando a função recursiva
    resultado = "verdadeira" if verifica_palindromo_recursividade(s_sem_espacos) else "falsa"
    
    # Retorna a mensagem com o resultado, a string original e a string invertida
    return f"A função é {resultado}. \nOriginal: {s_original} \nInvertida: {s_original[::-1]}"

# Função recursiva responsável por realizar a verificação se a variável é um palíndromo ou não
def verifica_palindromo_recursividade(s):
    # se a string tem 1 caractere ou menos, é um palíndromo
    if len(s) <= 1:
        return True
    
    # se o primeiro e último caractere são diferentes, não é um palíndromo
    if s[0] != s[-1]:
        return False
    
    # Chamada recursiva com a string sem o primeiro e último caractere
    return verifica_palindromo_recursividade(s[1:-1])

# Define a variável
variavel = "1234321 A n A 1234321."

# Ignora pontuações
variavel_sem_pontuacao = ''.join(c for c in variavel if c.isalnum())

# Chama a função conversor_variavel e imprime o resultado
resultado = conversor_variavel(variavel_sem_pontuacao)
print(resultado)