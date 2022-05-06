from typing import List


def generateMatrix(n:int):
    resposta = [[i+1 for i in range(0,n)] for _ in range(0, n)]
    direcao = True
    x = n-1
    y = 0
    contador = n+1

    for passos in range(n-1, -1, -1):
        if direcao:
            for i in range(1, passos+1):
                y += 1
                resposta[y][x] = contador
                contador += 1
            for i in range(1, passos+1):
                x -= 1
                resposta[y][x] = contador
                contador += 1
        else:
            for i in range(1, passos+1):
                y -= 1
                resposta[y][x] = contador
                contador += 1
            for i in range(1, passos+1):
                x += 1
                resposta[y][x] = contador
                contador += 1
        direcao = not direcao
            
    return resposta

print(*generateMatrix(5), sep="\n")