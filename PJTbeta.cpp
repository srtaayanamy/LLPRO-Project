//anna codou aq
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

//inicio da �rea das fun��esss
int quantfav = 0;
float avalifav[100];
char nomesfav[100][50];

//void pq n�o retorna nenhum resultado
void listafavoritos() {
    if (quantfav == 0) {
        printf("A lista de favoritos est� vazia.\n");
        return;
    }
    
    printf("Filmes favoritos:\n");
    
    //fun��o que traz o negocinho de "carregando"
    Sleep(500);
	printf(".");
	Sleep(500);
	printf(".");
	Sleep(500);
	printf(".\n");
	
    //parte q mostra os fav e suas avalia�oes
    for (int i = 0; i < quantfav; i++) {
        printf("Nome: %s --> %.1f\n", nomesfav[i], avalifav[i]);
    }
}
//fim da �rea das fun�oes

int main() {
//defini�oes da tela e dec. das vari�veis
	setlocale(LC_ALL, "portuguese");
	system ("color 70");
	
    char nome_filme[50];
    char resposta;
    
    printf("AVALIADOR DE FILMES E LIVROS\n");
	printf("---------------------\n");

//parte de apura�ao de dados

    do {
        printf("Digite o nome do filme: ");
        scanf("%s", nome_filme);

        float avaliacao;
        printf("Digite a avalia��o para o filme %s (avalie de 1 a 5): ", nome_filme);
        scanf("%f", &avaliacao);

//condi��es p ser fav

        if (avaliacao >= 4 && avaliacao <= 5) {
            if (quantfav < 100) {
                strcpy(nomesfav[quantfav], nome_filme);
                avalifav[quantfav] = avaliacao;
                quantfav++;
                printf("Filme adicionado aos favoritos.\n");
            } else {
                printf("Reinicie a lista, por favor.\n");
            }
        } else {
            printf("N�o entra nos favoritos.\n");
        }

        printf("Deseja colocar outro filme? [S/n]: ");
        scanf(" %c", &resposta);
    //fun�ao limpa tela
    system("cls");		
    
    printf("AVALIADOR DE FILMES E LIVROS\n");
	printf("---------------------\n");
//repei�ao de todo o codigo
    } while (resposta == 'S' || resposta == 's');
//chamada da fun�ao q mostra os favs
    listafavoritos();

    return 0;
}
