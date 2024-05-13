#include <stdio.h>

typedef struct{
    int cod;
    char desc[100];
    float valor;
} tProduto;

int main(){
    tProduto p1;

    //entrada dados
    printf("Informe a descricao do produto: \n");
    printf("Codigo...: ");
    scanf("%d", &p1.cod);
    printf("Valor...: ");
    scanf("%f", &p1.valor);
    fflush(stdin);
    printf("Descricao...:  ");
    gets(p1.desc);

    //exibir dados digitados
    printf("\nDados informados: \n");
    printf("Codigo:...%d \n", p1.cod);
    printf("Valor:...R$%.2f \n", p1.valor);
    printf("Descricao:...%s \n", p1.desc);
}
