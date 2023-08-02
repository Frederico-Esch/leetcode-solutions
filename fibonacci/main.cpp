#include<iostream>


int fib(int n){
  if(n == 0) return 0;
  if(n == 1) return 1;
  int vals[2] = {0,1};
  int aux;
  for(int i =0 ; i < n-1; i++){
    aux = vals[1];
    vals[1] = vals[1] + vals[0];
    vals[0] = aux;
  }
  return vals[1];
}

int main(){
  for(int i = 0; i < 10; i++) std::cout << fib(i) << "\n";
}
