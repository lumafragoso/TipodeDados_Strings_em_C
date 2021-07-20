#include <stdio.h>
#include <string.h>

void ordem(){

}

void decifrar(char cripto[], const char S[], int original[]){
    int i=0, j=0, inicio=0, final=8, a=0, b=0, k=0, control=0, aux=0, merda=0, p=0, tamanho=0, posicao=0;
    int K[8] ={0};
    
    //CALCULO DO TAMANHO DA STRING 
    tamanho = (int)strlen(cripto) -9;

    for (p = 0; p < tamanho; p++){
        //VERIFICAR DE ONDE COMEÇA E TERMINA A CHAVE
        if(posicao ==4){
            posicao =0;
        }
        //CASO AINDA NÃO TENHA ENCONTRADO A CHAVE
        if(merda != 1){
            for (i = inicio; i < final; i++){
                for (j = 0; j < 40; j++){
                    //ENCONTRAR A POSIÇÃO DA LETRA CRIPTOGRAFADA NO VETOR S
                    if(cripto[i] == S[j]){
                        a = j;
                    }
                }
                K[aux] = a - original[aux];
                //printf("AUX: %d ", aux);
                if(a - original[aux] < 0){
                    K[aux] = a-original[aux] +40;
                }
                //printf("K%d: %d, ", aux, K[aux]);
                aux++;
            }
            //printf("\n");
            aux=0;
            //LOOP PARA VERIFICAR SE A CHAVE ESTÁ CORRETA
            for (k = 0; k < 4; k++){
                if(K[k] == K[k+4]){
                    control++;
                }
            }
            //printf("Control: %d\n", control);
            if(control == 4){
                merda =1;
            }
            else{
                inicio++;
                final++;
                a=0;
                b=0;
                //RESETAR CONTROLE
                control =0;
            }
        }
        posicao++;
    }

    if(merda != 1){
        printf("Mensagem nao e da Resistencia!");
    }
    /*else{
        ordem();
    }*/
    /*for (i = 0; i < 8; i++){
        printf("%d\n", K[i]);
    }*/
    
    
}

int main(){
    const char S[]=
    {'0','1','2','3','4','5','6','7','8','9',
     'A','B','C','D','E','F','G','H','I','J',
     'K','L','M','N','O','P','Q','R','S','T',
     'U','V','W','X','Y','Z','.',',','?',' '};
    const char KP[] =
    {'Q', 'U', 'E', ' ', 'A', ' ', 'F', 'O', '\0'};
    char C[200]={0};
    int kp[9]={0}, i=0, j=0;

    //ENCONTRAR A POSIÇÃO DA LETRA DE KP NO VETOR S
    for (i = 0; i < 8; i++){
        for (j = 0; j < 40; j++){
            if(KP[i] == S[j]){
                kp[i] = j;
            }
        }
    }
    //LER MENSAGEM CIFRADA
    fgets(C, 200, stdin);
    
    //CHAMAR A FUNÇÃO QUE DECIFRA A MENSAGEM CRIPTOGRAFADA
    decifrar(C, S, kp);

    return 0;
}