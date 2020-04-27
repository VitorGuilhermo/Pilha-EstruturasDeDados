#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio2.h>
#include <string.h>
#include <windows.h>
#include "TADPilha.h"

char menu(){
    system("cls");
    textcolor(15);
    printf("\n\n\n\n\n\n\n\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t           SIMULACAO PILHA            \n");
    printf("\t\t\t\t\t====================================\n");
    printf("\t\t\t\t\t   [ ENTER ]  -  Iniciar\n");
    printf("\t\t\t\t\t   [ Qualquer tecla ]  - Sair\n");
    printf("\t\t\t\t\t====================================\n");

    return toupper(getch());
}

int main(){
    TpPilha pilha;

    char op, letra;
    int ut;

    op = menu();
    while(op == 13){

        //desenhos
        system("cls");
        desenhaPilha(4, 57);
        desenhaDescricao();
        desenhaPlacaInformacoes(22, 5);

        //inicializacoes
        inicializa(pilha);
        ut = 1;
        letra = 65;

        while(!cheia(pilha.topo) && !kbhit()){

            //mostra informacoes
            limpaVetor(pilha);
            exibe(pilha);
            textcolor(6);
            limpaLinha(20, 24);
            gotoxy(20, 24);
            printf("UT = %d", ut);
            limpaLinha(20, 25);
            gotoxy(20, 25);
            printf("Elemento do topo = %c", elementoTopo(pilha));

            //insercao
            if(ut % 3 == 0){
                insere(pilha, letra++);
            }

            //remocao
            if(ut % 30 == 0){
                retira(pilha);
            }

            Sleep(1000);
            ut++;
        }

        getch();
        op = menu();
    }
}

