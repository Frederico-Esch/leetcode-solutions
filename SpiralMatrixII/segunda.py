def generateMatrix(n:int)->list[list[int]]:
    matrix = [[j+1 for j in range(n)] for _ in range(n)]

    x = n-1
    y = 0
    n+=1
    indo = True

    for step in range(n-1, 0, -1):
        if indo:
            for _ in range(step):
                y += 1
                matrix[y][x] = n
                n+=1
            for _ in range(step):
                x-=1
                matrix[y][x] = n
                n+=1
            indo = False
        else:
            for _ in range(step):
                y -= 1
                matrix[y][x] = n
                n+=1
            for _ in range(step):
                x+=1
                matrix[y][x] = n
                n+=1
            indo = True
    return matrix
print(*generateMatrix(3), sep="\n")