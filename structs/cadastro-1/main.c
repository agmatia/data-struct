#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int codigo;
    char desc[50];
    float valor;
} tProd;

void print_spaces(int n){
    int i;
    for (i=0; i<n; i++){
        printf(" ");
    }
}

int mostrar_menu(){
    int opcao;
    system("cls");
    printf("-----Menu Principal-----\n");
    printf("(1) Incluir.............\n");
    printf("(2) Listar..............\n");
    printf("(3) Pesquisar...........\n");
    printf("(4) Alterar.............\n");
    printf("(5) Ordenar Produtos....\n");
    printf("(0) Sair................\n");
    printf("\n");

    printf("Tecle sua opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int inclusao(tProd* vProd, int qtd){
    system("cls");

    printf("+-----------------------------------------+\n");
    printf("|                 Cadastro                |\n");
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
    //system("pause");

    gravar(vProd, qtd);
    return qtd+1;
}

void ordenar_produtos(tProd* vProd, int qtd){
    int tempI, i;
    float tempP;
    char tempS[50];
    int houve_troca = 1;

    while(houve_troca == 1){
        houve_troca = 0;

        for(i=0; i<qtd-1; i++){
            //se as descrições estão fora de ordem
            if(strcmp(vProd[i].desc, vProd[i+1].desc) > 0){

                //efetua as trocas de valor
                houve_troca = 1;

                //primeira troca do codigo
                tempI = vProd[i].codigo;
                vProd[i].codigo =  vProd[i+1].codigo;
                vProd[i+1].codigo = tempI;

                tempP = vProd[i].valor;
                vProd[i].valor =  vProd[i+1].valor;
                vProd[i+1].valor = tempP;

                strcpy(tempS, vProd[i].desc);
                strcpy(vProd[i].desc, vProd[i+1].desc);
                strcpy(vProd[i+1].desc,tempS );
            }
        }
    }
    gravar(vProd, qtd);
    listar(vProd, qtd);
}

int listar(tProd* vProd, int qtd){
    system("cls");
    int i;

    printf("+-----------------------------------------+\n");
    printf("|                  Listagem               |\n");
    printf("+-----------------------------------------+\n");
    for(i=0; i<qtd; i++){
        printf("| %5d | %-22s | %6.2f |\n", vProd[i].codigo, vProd[i].desc, vProd[i].valor);
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
    print_spaces(26-strlen(buscar));
    printf("\n");
    printf("+-----------------------------------------+\n");
    for(i=0; i<qtd; i++){
                        //onde          //o que
        if (    strstr(   strlwr(vProd[i].desc)   ,   strlwr(buscar)   )   !=0   ){
            printf("| %5d | %-22s | %6.2f |\n", vProd[i].codigo, vProd[i].desc, vProd[i].valor);
            cont++;
                    //%-30s é para alinhar a esquerda!
        }
    }
    printf("+-----------------------------------------+\n");
    printf("| Total de registros:  %d                | \n", cont);
    printf("+-----------------------------------------+\n");

    system("pause");
}

int gravar(tProd * vProd, int qtd){
    int i;
    char nomeArquivo[] = "produtos.csv";

    //funçoes fopen
    FILE* file = fopen(nomeArquivo, "w"); //"w" para write.
    if(file == NULL){
        printf("Erro ao tentar gravar o arquivo.\n");
    }else {
       for(i=0; i<qtd; i++){
            fprintf(file,"%d;%s;%f\n", vProd[i].codigo, vProd[i].desc, vProd[i].valor);
       }
       printf("Arquivo gravado com sucesso!\n");
       system("pause");
    }
    fclose(file);
}

int leitura(tProd* vProd){
    system("cls");

    int cont=0;
    char linha[256] = " ";
    char* token;
    char nomeArquivo[] = "produtos.csv";

    //funçoes fopen
    FILE* file = fopen(nomeArquivo, "r"); //"r" para read.
    if(file == NULL){
        printf("Erro ao ler o arquivo.\n");
    }else {
       //ler linhas
       while(fgets(linha, 256, file)){
            printf("| %s", linha);

            token = strtok(linha, ";\n");
            //codigo
            vProd[cont].codigo = atoi(token);

            //token = strtok(NULL, ";");
            //descricao
            strcpy(vProd[cont].desc, strtok(NULL, ";\n"));

            //token = strtok(NULL, ";");
            //preco
            vProd[cont].valor = atof(strtok(NULL, ";\n"));

            cont++;
            }
       }
       printf("+-----------------------------------------+\n");
       printf("| Total de registros:  %3d                | \n", cont);
       printf("+-----------------------------------------+\n");

    fclose(file);
    system("pause");
    return cont;
}

void alterar(tProd* vProd, int qtd){

    int item;
    int j=0;
    int posicao=-1;

    pesquisar(vProd, qtd); //para o usuario identificar o codigo do produto

    printf("\n \n");
    printf("Informe o codigo do produto: ");
    scanf("%d", &item);

    for(j=0; posicao<0; j++){
        if(vProd[j].codigo == item){
            inclusao(vProd, j);
            posicao += 1;
            break;
        }
    }
    system("pause");
}

int main()
{
    tProd vProd[100];
    int qtd =0;
    int opcao;

    qtd = leitura(vProd);

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
        case 4:
            alterar(vProd, qtd);
            break;
        case 5:
            ordenar_produtos(vProd, qtd);
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
