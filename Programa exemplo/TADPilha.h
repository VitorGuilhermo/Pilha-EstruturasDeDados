#define MAXPILA 9

struct TpPilha{
    int topo;
    char pilha[MAXPILA];
};

void inicializa(TpPilha &p){
    p.topo = -1;
}

void insere(TpPilha &p, char elemento){
    p.pilha[++p.topo] = elemento;
}
char retira(TpPilha &p){
    return p.pilha[p.topo--];
}

char elementoTopo(TpPilha p){
    return p.pilha[p.topo];
}

int cheia(int topo){
    return topo == MAXPILA-1;
}
int vazia(int topo){
    return topo == -1;
}

int exibe(TpPilha p){
    TpPilha aux;
    inicializa(aux);
    char letra;
    int linha = 19;

    while(!vazia(p.topo)){
        letra = retira(p    );
        insere(aux, letra);
   }
   while(!vazia(aux.topo)){
        gotoxy(59, linha);
        printf("%c",retira(aux));
        linha -= 2;
   }
}

//desenhos
void desenhaPilha(int linha, int coluna){
    char vetor[][100] = {
                                " ____",
                                "|    |",
                                "|____|7",
                                "|    |",
                                "|____|6",
                                "|    |",
                                "|____|5",
                                "|    |",
                                "|____|4",
                                "|    |",
                                "|____|3",
                                "|    |",
                                "|____|2",
                                "|    |",
                                "|____|1",
                                "|    |",
                                "|____|0"
                                };
    textcolor(3);
    for(int i = 0; i<17; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", vetor[i]);
    }
    textcolor(15);
}
void desenhaDescricao(){
    textcolor(11);
    gotoxy(8, 1);
    printf("==========================================================================================================");
    gotoxy(42, 2);
    printf("        SIMULACAO DE UMA PILHA              ");
    gotoxy(8, 3);
    printf("==========================================================================================================");
    textcolor(15);
}
void desenhaPlacaInformacoes(int linha, int coluna){
    int i;
    char placa [][150] = {
                        " _____________________________________________________________________________________________________________",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|                                                                                                             |",
                        "|_____________________________________________________________________________________________________________|"
                        };
    textcolor(3);
    for(i = 0; i<7; i++){
        gotoxy(coluna, linha+i);
        printf("%s\n", placa[i]);
    }
    textcolor(15);
}

void limpaLinha(int x, int y){
    int i;
    for(i=0; i< 25; i++){
        gotoxy(x+i, y);
        printf(" ");
    }
}
void limpaVetor(TpPilha p){
    int linha = 19;
    while(!vazia(p.topo)){
        gotoxy(59, linha);
        printf("%c",retira(p));
        linha -= 2;
   }
}
