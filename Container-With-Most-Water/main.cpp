#include<iostream>
#include<vector>

using std::vector;
int menor(int l, int r){
    if(l < r) return l;
    else return r;
}

int maxArea(vector<int>& height){
    auto pInicial = height.begin();
    auto pFinal = height.rbegin();
    int i = height.size()-1;
    int left = *pInicial;
    int right = *pFinal;
    int temp_i = i;
    
    while(pInicial < (pFinal.base()-1)){

        if(menor(left, right)*i < menor(*pInicial, *pFinal)*temp_i){
            left = *pInicial;
            right = *pFinal;
            i = temp_i;
        }

        if(*pInicial < *pFinal){
            pInicial++;
            temp_i--;
        }else{
            pFinal++;
            temp_i--;
        }
    }
    return menor(left, right) * i;
}

int main(){
    vector<int> height {2,3,4,5,18,17,6};
    std::cout << maxArea(height) << "\n";

    /*
    vector<int> vetor {1,2};
    std::cout << (vetor.begin() < (vetor.rbegin().base()-1)) << "\n";
    */
    return 0;
}
