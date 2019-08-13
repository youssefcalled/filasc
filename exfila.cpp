#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "bexfila.h"

int main()
{
    Fila *afila = criaFila();
    Fila *afilab = criaFila();
    Fila *rbusca;
    char opcao;
    int valor;

    do
    {

        printf("\n\n");
        printf("1- Adicionar elementos na Fila A\n");
        printf("2- Adicionar elementos na Fila B\n");
        printf("3- Remover elemento da Fila A\n");
        printf("4- Remover elemento da Fila B\n");
        printf("5- Buscar elemento na Fila A\n");
        printf("6- Buscar elemento na Fila B\n");
        printf("7- Mostrar Fila A\n");
        printf("8- Mostrar Fila B\n");
        printf("a- Liberar Fila A\n");
        printf("b- Liberar Fila B\n");
        printf("c- Unir Fila A com Fila B\n");
        printf("d- Unir Fila B com Fila A\n");
        printf("e- Passar elemento para o inicio da Fila A\n");
        printf("f- Passar elemento para o inicio da Fila B\n");
        printf("0- Sair\n");


        printf("\nDigite a opcao: ");
        opcao = getch();
        system("clear || cls");


        switch(opcao)
        {
        case '1':
            printf("\nDigite o valor quer inserir: ");
            scanf("%d",&valor);
            afila = inserir(afila,valor);
            break;

        case '2':
            printf("\nDigite o valor quer inserir: ");
            scanf("%d",&valor);
            afilab = inserir(afilab,valor);
            break;

        case '3':
            afila = retirainicio(afila);
            break;

        case '4':
            afilab = retirainicio(afilab);
            break;

        case '5':
            if(FilaVazia(afila))
                printf("Fila vazia");
            else
            {
            printf("\nDigite o valor a ser procurado: ");
            scanf("%d",&valor);
                rbusca = Busca(afila,valor);
                if(rbusca == NULL)
                    printf("Elemento nao encontrado");
                else
                    printf("Elemento encontrado");
            }
            break;

        case '6':
            printf("\nDigite o valor a ser procurado: ");
            scanf("%d",&valor);
            if(FilaVazia(afilab))
                printf("Fila vazia");
            else
            {
                rbusca = Busca(afilab,valor);
                if(rbusca == NULL)
                    printf("Elemento nao encontrado");
                else
                    printf("Elemento encontrado");
            }
            break;

        case '7':
            if(FilaVazia(afila))
                printf("Fila vazia");
            else
                Mostra(afila);
            break;

        case '8':
            if(FilaVazia(afilab))
                printf("Fila vazia");

            else
                Mostra(afilab);
            break;

        case 'a':
            liberaFila(afila);
            afila = criaFila();
            break;

        case 'b':
            liberaFila(afilab);
            afilab = criaFila();
            break;
        case 'c':

            afila = unir(afilab,afila);

            break;

        case 'd':
            afilab = unir(afila,afilab);
            break;
        case 'e':
            printf("Digite o elemento que deseja passar para o inicio: ");
            scanf("%d",&valor);
            rbusca = Busca(afila,valor);
            if(rbusca == NULL)
                printf("Elemento nao encontrado");
            else
                afila = passarinicio(afila,valor);
            break;
        case 'f':
            printf("Digite o elemento que deseja passar para o inicio: ");
            scanf("%d",&valor);
            rbusca = Busca(afilab,valor);
            if(rbusca == NULL)
                printf("Elemento nao encontrado");
            else
                afilab = passarinicio(afilab,valor);
            break;

        case '0':
            printf("\nSaindo do menu");
            break;

        default:
            printf("Opcao invalida");
            break;

        }


    }while(opcao != '0');


    return 0;
}
