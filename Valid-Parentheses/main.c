#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

char valores[10000];
bool isValid(const char* s){
  memset(valores, 0, 10000*sizeof(char));
  int counter = 0;
  
  for(int i = 0; i < strlen(s); i++){
    if(counter < 0) return false;

    if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
      valores[counter] = s[i];
      counter++;
    }
    else {
      counter--;
      if(s[i] == ')' && valores[counter] != '(') return false;
      else if(s[i] == ']' && valores[counter] != '[') return false;
      else if(s[i] == '}' && valores[counter] != '{') return false;
    }
  }
  if(counter != 0) return false;
  return true;
}

int main(){
  const char * string = "()";
  printf("%d\n", isValid(string));
}
