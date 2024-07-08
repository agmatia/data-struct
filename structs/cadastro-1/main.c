#include <stdio.h>
#include <stdlib.h>

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
    printf("(0) Sair................\n");
    printf("\n");

    printf("Tecle sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int inclusao(){
    printf("Inclusao \n");
    system("pause");
}

int listar(){
    printf("Listar \n");
    system("pause");
}

int main()
{
    tProd vProd[100];
    int qtd;
    int opcao;

    do{
        opcao = mostrar_menu();

        switch(opcao){
        case 1:
            inclusao();
            break;
        case 2:
            listar();
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
