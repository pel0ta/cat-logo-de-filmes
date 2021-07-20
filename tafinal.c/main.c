#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis Globais
int op,op3,catego,anoFilFilme,anopro,alterar,novaCategoria, novaCensura, novoAno,i=0,j=0;
char nome1[100],alteraNome[100], nomeNovo[100],novaDescricao[200],excluirNome[100];
double novaDuracao;

//Struct com as informações do filme
struct filme
{
    char nome[100];
    char descricao[200];
    int ano;
    int categoria;
    int censura;
    double duracao;
};

//Inicializando a Struct
struct filme movie[15];

//Função para inicializar o arquivo
void caregar()
{
    struct filme m;

    FILE * file = fopen("filme.bin","r");
    if(file)
    {
        while(fread(&m,sizeof(struct filme), 1, file))
        {
            movie[i]=m;
            i++;
        }
        fclose(file);
   // } else {
        //printf("Nao abriu");
    }
}

//Função para salvar oarquivo
void salvar()
{
    FILE * file = fopen("filme.bin","w");
    if(file)
    {
        for(j=0; j<i; j++)
        {
            fwrite(&movie[j],sizeof(struct filme), 1, file);
        }
        fclose(file);
    }
}

//Função que mostra os arquivos salvos
void list() {

    for (j = 0; j < i; j ++) {

        printf("Nome do filme: %s\n",movie[j].nome);
        printf("Descricao: %s\n",movie[j].descricao);
        printf("Categoria: %d\n",movie[j].categoria);
        printf("Ano: %d\n",movie[j].ano);
        printf("Censura: %d\n",movie[j].censura);
        printf("Duracao: %.2lf\n",movie[j].duracao);
        printf("\n\n");
    }
}

//Função de cadastro dos filmes
void cadastro()
{
    system("cls");
    if(i<15){
    printf("     CADASTRO    \n");
    fflush(stdin);
    printf("Digite o nome do filme: ");
    gets(movie[i].nome);
    strlwr(movie[i].nome);
    fflush(stdin);
    printf("Digite a descricao do filme: ");
    gets(movie[i].descricao);
    strlwr(movie[i].descricao);
    fflush(stdin);
    printf("Digite o ano do filme: ");
    scanf("%d",&movie[i].ano);
    printf("Digite a categoria:\n1-Drama\n2-Comedia\n3-Terror\n4-Ficcao\n5-Fantasia\n");
    scanf("%d",&movie[i].categoria);
    while(movie[i].categoria>5||movie[i].categoria<1){
        printf("Categoria Invalida\n   Digite novamente:  ");
        scanf("%d",&movie[i].categoria);
    }
    printf("Digite a censura em anos: ");
    scanf("%d",&movie[i].censura);
    printf("Digite a duracao (ex:1.20): ");
    scanf("%lf",&movie[i].duracao);
    i++;
    system("cls");
    printf("Filme cadastrado com sucesso:\n\n");
    }
    else
        printf("\nOpcao invalida exclua alguns filmes\n");
}

//Função de pesquisar filmes
void pesquisar()
{
    system("cls");
    printf("      PESQUISAR     \n\n");
    printf("Selecione uma opcao para encontar o filme que deseja:\n1-Nome\n2-Categoria\n3-Ano\n");
    scanf("%d",&op3);
    while(op3>3||op3<1){
        printf("opcao invalida\n   Digite a forma de pesquisa novamente:  ");
        scanf("%d",&op3);
    }
    if(op3==1)
    {
        printf("Digite o nome do filme que deseja procurar: ");
        fflush(stdin);
        gets(nome1);
        strlwr(nome1);

        for(j=0; j<i; j++)
        {
            if(strcmp(movie[j].nome,nome1)==0)
            {
                fflush(stdin);
                printf("Nome do filme: %s\n",movie[j].nome);
                printf("Descricao: %s\n",movie[j].descricao);
                printf("Categoria: %d\n",movie[j].categoria);
                printf("Ano: %d\n",movie[j].ano);
                printf("Censura: %d\n",movie[j].censura);
                printf("Duracao: %.2lf\n",movie[j].duracao);
                printf("\n\n");
            }
        }
    }
    if(op3==2)
    {
        printf("Digite a categoria:\n1-Drama\n2-Comedia\n3-Terror\n4-Ficcao\n5-Fantasia\n");
        scanf("%d",&catego);
        for(j=0; j<i; j++)
        {
            if(movie[j].categoria==catego)
            {
                printf("Nome do filme: %s\n",movie[j].nome);
                printf("Descricao: %s\n",movie[j].descricao);
                printf("Categoria: %d\n",movie[j].categoria);
                printf("Ano: %d\n",movie[j].ano);
                printf("Censura: %d\n",movie[j].censura);
                printf("Duracao: %.2lf\n",movie[j].duracao);
                printf("\n\n");
            }
        }
    }

    if(op3==3)
    {
        printf("Digite o ano: ");
        fflush(stdin);
        scanf("%d",&anopro);
        for(j=0; j<i; j++)
        {
            if(movie[j].ano==anopro)
            {
                fflush(stdin);
                printf("Nome do filme: %s\n",movie[j].nome);
                printf("Descricao: %s\n",movie[j].descricao);
                printf("Categoria: %d\n",movie[j].categoria);
                printf("Ano: %d\n",movie[j].ano);
                printf("Censura: %d\n",movie[j].censura);
                printf("Duracao: %.2lf\n",movie[j].duracao);
                printf("\n\n");
            }
        }
    }
}

//Função de alterar os filmes
void mudanca()
{
    system("cls");
    printf("     ALTERACAO:    \n");
    printf("O que deseja alterar:\n1-Nome\n2-Descricao\n3-Categoria\n4-Ano\n5-Censura\n6-Duracao\n");
    scanf("%d",&alterar);
    while(alterar>6||alterar<1){
        printf("opcao invalida\n   Digite novamente a opcao:  ");
        scanf("%d",&alterar);
    }
    if(alterar==1)
    {
        printf("Digite o nome do filme que deseja alterar: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite o novo nome do filme: ");
                gets(nomeNovo);
                strlwr(nomeNovo);
                strcpy(movie[j].nome,nomeNovo);

                printf("O nome atualizado do filme e %s!\n",nomeNovo);

            }
        }
    }

    if(alterar==2)
    {
        printf("Digite o nome do filme que deseja alterar a descricao: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite a nova descricao do filme ");
                gets(novaDescricao);
                strlwr(novaDescricao);
                strcpy(movie[j].descricao,novaDescricao);
                printf("A descricao atualizada do filme e %s!\n",novaDescricao);
            }
        }
    }

    if(alterar==3)
    {
        printf("Digite o nome do filme que deseja alterar a categoria: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite a nova categoria do filme: ");
                scanf("%d",&novaCategoria);
                movie[j].categoria=novaCategoria;
                printf("A categoria atualizada do filme e %d!\n",novaCategoria);
            }
        }
    }

    if(alterar==4)
    {
        printf("Digite o nome do filme que deseja alterar o ano: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite o novo ano do filme: ");
                scanf("%d",&novoAno);
                movie[j].ano=novoAno;
                printf("O ano atualizado do filme e %d!\n",novoAno);
            }
        }
    }

    if(alterar==5)
    {
        printf("Digite o nome do filme que deseja alterar a censura: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite a nova censura do filme: ");
                scanf("%d",&novaCensura);
                movie[j].censura=novaCensura;
                printf("A censura atualizada do filme e %d!\n",novaCensura);
            }
        }
    }

    if(alterar==6)
    {
        printf("Digite o nome do filme que deseja alterar a duracao: ");
        fflush(stdin);
        gets(alteraNome);
        strlwr(alteraNome);

        for(j=0; j<15; j++)
        {
            if(strcmp(alteraNome,movie[j].nome)==0)
            {
                printf("Digite a nova duracao do filme: ");
                scanf("%lf",&novaDuracao);
                movie[j].duracao=novaDuracao;
                printf("A duracao atualizado do filme e %.2lf!\n",novaDuracao);
            }
        }
    }

}

//Função de excluir os filmes
void excluir()
{
    system("cls");
    printf("          EXCLUIR:\n\n");
    printf("Digite o nome do filme que deseja excluir: ");
    fflush(stdin);
    gets(excluirNome);
    strlwr(excluirNome);


    for(j=0; j<15; j++)
    {
        if(strcmp(excluirNome,movie[j].nome)==0)
        {
            while(j<i)
            {
                movie[j]=movie[j+1];
                j++;
            }
        }
    }

    printf("Filme excluido com sucesso!\n");
}

//Função do menu inicial
void menu()
{
    printf("       Bem-vindo!      \n\n");
    printf("Voce esta no Sistema de Catalago de Filmes!\n\n");
    do
    {
        printf("Selecione uma opcao:\n\n1 - Cadastrar\n2 - Pesquisar\n3 - Alterar\n4 - Excluir\n5 - Sair\n6 - Mostrar dados salvos\n");
        scanf("%d",&op);
        while(op>6 || op<1)
        {
            printf("Opcao invalida!\n");
            printf("selecione outra opcao :\n1 - Cadastrar\n2 - Pesquisar\n3 - Alterar\n4 - Excluir\n5 - Sair\n6 - Mostrar dados salvos\n");
            scanf("%d",&op);
        }

        switch (op)
        {
        case 1:
            cadastro();
            break;

        case 2:
            pesquisar();
            break;

        case 3:
            mudanca();
            break;

        case 4:
            excluir();
            break;

        case 5 :
            salvar();
            getch();
            system("cls");
            printf("Bye Bye. Ate a proxima!\n");
            break;

        case 6:
            list();
            break;
        }
    }
    while(op!=5);
}


int main()
{
    caregar();

    menu();

    return 0;
}
