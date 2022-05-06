#include<vector> 
#include<array> 
#include<iostream> 
using std::vector;

#ifndef __GNUC__
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> resposta(n, std::vector<int>(n));
    bool direcao = true;
    int x = n-1, y=0;
    int contador = n+1;

    for(int i = 0; i < n; i++) resposta[0][i] = i+1;

    for(int passos = n-1; passos>= 0; passos--){
        if(direcao){
            for(int i = 1; i < passos+1; i++) resposta[++y][x] = contador++;
            for(int i = 1; i < passos+1; i++) resposta[y][--x] = contador++;

        }else{
            for(int i = 1; i < passos+1; i++) resposta[--y][x] = contador++;
            for(int i = 1; i < passos+1; i++) resposta[y][++x] = contador++;
        }
        direcao = !direcao;
    }
    std::cout <<"WIN" << std::endl;
    return resposta;
}

#else
//faster but only works on gnu compilers
vector<vector<int>> generateMatrix(int n){
    int resposta[n][n];
    bool direcao = true;
    int x = n-1, y=0;
    int contador = n+1;

    for(int i = 0; i < n; i++) resposta[0][i] = i+1;

    for(int passos = n-1; passos>= 0; passos--){
        if(direcao){
            for(int i = 1; i < passos+1; i++) resposta[++y][x] = contador++;
            for(int i = 1; i < passos+1; i++) resposta[y][--x] = contador++;

        }else{
            for(int i = 1; i < passos+1; i++) resposta[--y][x] = contador++;
            for(int i = 1; i < passos+1; i++) resposta[y][++x] = contador++;
        }
        direcao = !direcao;
    }

    std::vector<std::vector<int>> _resposta;
    for(auto& arr : resposta){
        std::vector<int> sub;
        for(auto& i : arr){
            sub.push_back(i);
        }
        _resposta.push_back(sub);
    }
    std::cout <<"GNU" << std::endl;
    return _resposta;
}
#endif


int main(){
    for(auto v : generateMatrix(4)) { 
        for(auto value : v){
            std::cout<< value << " ";
        }
        std::cout << "\n";
    }
    return 0;
}