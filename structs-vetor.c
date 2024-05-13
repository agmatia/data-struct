#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    float preco;
    char descricao[100];
}  tProduto;

int main(){
int qtd=0, i=0;
int codigo;
tProduto valor[100];

/******************************** ESTRUTURA BASICA S/ STRUCT *********************************

    printf("Codigo do produto: ");
    scanf("%d", &codigo);

    printf("\n");
    while(codigo != 0){
        valor[qtd] = codigo;
        qtd++;
        printf("Codigo do produto: ");
        scanf("%d", &codigo);

    }
    system("cls");
    for(i=0; i<qtd; i++){
        i==0 ? printf("%d", valor[i]) : printf(", %d", valor[i]);   //? = if    //: = else
    }
//********************************************************************************************/

    printf("Codigo...: ");
    scanf("%d", &codigo);

    while(codigo != 0){
        //vetor[indice].campo na struct
        valor[qtd].codigo = codigo;

        fflush(stdin);
        printf("Descricao...: ");
        gets(valor[qtd].descricao);

        printf("Digite o preco...: ");
        scanf("%f", &valor[qtd].preco);

        //variavel de controle para o bloco de instrucoes
        qtd++;

        printf("\n");
        printf("Codigo...: ");
        scanf("%d", &codigo);
    }
    system("cls");
    printf("------- Produtos -------\n");
    for(i=0; i<qtd; i++){
        //i==0 ? printf("%d", valor[i].codigo) : printf(", %d", valor[i].codigo);   //? = if    //: = else

        printf("%3d %20s %6.2f\n", valor[i].codigo, valor[i].descricao, valor[i].preco);
    }
    printf("------------------------");
}
