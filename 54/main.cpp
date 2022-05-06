#include<iostream>
#include<vector>

std::vector<std::vector<int>> generateMatrix(int n){
    int[][] resposta = new int[n][n];
    bool direcao = true;
    int x = n-1, y=0;
    int contador = n+1;

    for(int i = 0; i < n; i++) resposta[0][i] = i+1;

    for(int passos = n-1, passos>= 0; passos--){
        if(direcao){
            for(int i = 1; i < passos+1) resposta[++y][x] = contador++;
            for(int i = 1; i < passos+1) resposta[y][--x] = contador++;
            
        }else{
            for(int i = 1; i < passos+1) resposta[--y][x] = contador++;
            for(int i = 1; i < passos+1) resposta[y][++x] = contador++;
        }
        direcao = !direcao;
    }

    std::vector<std::vector<int>> _resposta;
    for(int[] arr : resposta){
        std::vector<int> sub;
        for(int i : arr){
            sub.push_back(i);
        }
        _resposta.push_back(sub);
    }
    return _resposta;
}

int main(){
    generateMatrix(3);
    return 0;
}