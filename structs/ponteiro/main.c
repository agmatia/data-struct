#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char desc[50];
    float valor;
} tProd;

int mostrar_menu(){
    int opcao;
    system("cls");
    printf("-----Menu Principal-----\n");
    printf("(1) Incluir.............\n");
    printf("(2) Listar..............\n");
    printf("(3) Pesquisar...........\n");
    printf("(0) Sair................\n");
    printf("\n");

    printf("Tecle sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int inclusao(tProd* vProd, int qtd){
    system("cls");

    printf("+-----------------------------------------+\n");
    printf("|                 Inclusao                |\n");
    printf("+-----------------------------------------+\n");

    //printf("Codigo...: ");
    //scanf("%d", &vProd[qtd].codigo);
    vProd[qtd].codigo = qtd+1;

    printf("Descricao: ");
    fflush(stdin);
    gets(vProd[qtd].desc);

    printf("Preco....: ");
    scanf("%f", &vProd[qtd].valor);

    printf("\n");
    printf("Registro incluido! \n");
    system("pause");
    return qtd+1;
}

int listar(tProd* vProd, int qtd){
    system("cls");
    int i;

    printf("+-----------------------------------------+\n");
    printf("|                  Listagem               |\n");
    printf("+-----------------------------------------+\n");
    for(i=0; i<qtd; i++){
        printf("%5d %-30s %6.2f", vProd[i].codigo, vProd[i].desc, vProd[i].valor);
    }               //%-30s é para alinhar a esquerda!
    printf("+-----------------------------------------+\n");
    printf("| Total de registros:  %3d                | \n", qtd);
    printf("+-----------------------------------------+\n");

    system("pause");
}

int pesquisar(tProd* vProd, int qtd){
    int i=0;
    int cont = 0;
    char buscar[50];

    system("cls");
    printf("Informe a expressao de busca: ");
    fflush(stdin);
    gets(buscar);

    printf("+-----------------------------------------+\n");
    printf("| Pesquisando o produto: '%s'             |", buscar);
    print_space(26-strlen(buscar));
    printf("+-----------------------------------------+\n");
    for(i=0; i<qtd; i++){
                        //onde          //o que
        if(strstr(strulwr(vProd[cont].desc), strlwr(buscar)!=NULL)){
            printf("%5d %-30s %6.2f", vProd[i].codigo, vProd[i].desc, vProd[i].valor);
        }                //%-30s é para alinhar a esquerda!
    }
    printf("+-----------------------------------------+\n");
    printf("| Total de registros:  %3d                | \n", qtd);
    printf("+-----------------------------------------+\n");

    system("pause");
}

int main()
{
    tProd vProd[3];
    int qtd =0;
    int opcao;

    do{
        opcao = mostrar_menu();

        switch(opcao){
        case 1:
            qtd = inclusao(vProd, qtd);
            break;
        case 2:
            listar(vProd, qtd);
            break;
        case 3:
            pesquisar(vProd, qtd);
            break;
        case 0:
            printf("Encerrar.\n");
            break;
        default:
            printf("Opcao invalida! \n");
            system("pause");
        }
    }while (opcao != 0);
}
