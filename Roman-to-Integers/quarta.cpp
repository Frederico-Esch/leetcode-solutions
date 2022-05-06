#include<stdio.h>
#include<iostream>
#include<unordered_map>

using std::string;

std::unordered_map<char, int> romanos = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000},
};

int romanToInt(string s){
    int last_one = 1000;
    int result = 0;
    int valor;
    
    for(char c : s){
        valor = romanos.at(c);
        if(valor <= last_one){
            last_one = valor;
            result += valor;
        }else{
            result -= 2*last_one;
            result += valor;
        }
    }
    return result;
}

int main(){
    printf("%d\n", romanToInt("III"));
    printf("%d\n", romanToInt("LXXX"));
    printf("%d\n", romanToInt("XL"));
    printf("%d\n", romanToInt("MCMLXXXIV"));
    return 0;
}
