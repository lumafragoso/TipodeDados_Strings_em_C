#include<stdio.h>
#include<ctype.h>
#include <string.h>

int main (){
    char string[500];
    int i;

    //RECEBER A STRING
    fgets(string, 499, stdin);

    //LOOP Q VERÁ O TAMANHO DA STRING E CASO O CARACTERE SEJA " "
    for(i=0; i<strlen(string); i++){
        //CASO SEJA " ", LOGO i+1 SERA MAIÚSCULO
        if(string[i]  == ' '){
            string[i+1] = toupper(string[i+1]);
        }
        //CASO PARA O RESTO DAS LETRAS DAS PALAVRAS MINÚSCULAS
        else{
            if(string[0]  != ' '){
                string[0] = toupper(string[0]);
            }
            if(string[i-1]  != ' '){
                string[i] = tolower(string[i]);
            }
        }
    }

    printf("%s\n", string);

    return 0;
}