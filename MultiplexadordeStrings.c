#include <stdio.h>
#include <string.h>

void multiplexador(char primeiro[40], char segundo[40], int tamanho1, int tamanho2, int M, int aux){
    char texto[80] = {0};
    int i=0, j=0, k=0, l=0;

    if(aux == 1 || aux ==0){
        for (i = 0; i < 2*M; i++){
        //NUMERO DO LAÇO PAR
        if(i % 2 ==0){
            texto[i] = primeiro[j];
            j++;
        }
        //NUMERO DO LAÇO IMPAR
        else{
            texto[i] = segundo[k];
            k++;
        }
        }
        //MENOR É B ENTÃO O RESTO DEVE SER PREENCHIDO POR A
        if(aux == 0){
            for (l = 2*M; l < (tamanho2+ tamanho1); l++){
                texto[l] = primeiro[j];
                j++;
            }
        }
        //MENOR É A ENTÃO O RESTO DEVE SER PREENCHIDO POR B
        else if(aux == 1){
            for (l = 2*M; l < (tamanho2+ tamanho1); l++){
                texto[l] = segundo[k];
                k++;
            }
        }
    }
    else{
        for (i = 0; i < (tamanho2+ tamanho1); i++){
        //NUMERO DO LAÇO PAR
        if(i % 2 ==0){
            texto[i] = primeiro[j];
            j++;
        }
        //NUMERO DO LAÇO IMPAR
        else{
            texto[i] = segundo[k];
            k++;
        }
        }
    }

    printf("%s\n", texto);

}

int main(){

    char A[40]={0}, B[40] = {0};
    int tam_A=0, tam_B=0, menor =0, controle=0;

    //LER A
    fgets(A, 40, stdin);
    //LER B
    fgets(B, 40, stdin);

    //TAMANHO DE A
    tam_A = (int) strlen(A)-1;
    //TAMANHO DE B
    tam_B = (int) strlen(B)-1;

    //CASO TAMANHO DE A SEJA MAIOR Q TAMANHO DE B
    if(tam_A > tam_B){
        menor = tam_B;
        multiplexador(A, B, tam_A, tam_B, menor, controle);
    }
    //CASO TAMANHO DE B SEJA MAIOR Q TAMANHO DA A
    else if (tam_A < tam_B){
        menor = tam_A;
        multiplexador(A, B, tam_A, tam_B, menor, controle =1);
    }
    //TAMANHOS IGUAIS
    else{
        multiplexador(A, B, tam_A, tam_B, menor, controle =2);
    }

    return 0;
}