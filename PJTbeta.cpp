//anna codou aq 
 #include <stdio.h> 
 #include <string.h> 
 #include <stdlib.h> 
 #include <locale.h> 
  
 //inicio da área das funçõess
 int quantfav = 0; 
 float avalifav[100]; 
 char nomesfav[100][50]; 
  
 //void pq não retorna nenhum resultado 
 void listafavoritos() { 
     if (quantfav == 0) { 
         printf("A lista de favoritos está vazia.\n"); 
         return; 
     } 
  
     printf("Filmes favoritos:\n"); 
  
     //parte q mostra os fav e suas avaliaçoes 
     for (int i = 0; i < quantfav; i++) { 
         printf("Nome: %s --> %.1f\n", nomesfav[i], avalifav[i]); 
     } 
 } 
 //fim da área das funçoes 
  
 int main() { 
 //definiçoes da tela e dec. das variáveis 
         setlocale(LC_ALL, "portuguese"); 
         system ("color 70"); 
  
     char nome_filme[50]; 
     char resposta; 
  
  	  printf("=============================\n"); 
     printf("AVALIADOR DE FILMES\n"); 
        printf("=============================\n"); 
  
 //parte de apuraçao de dados 
  
     do { 
         printf("Digite o nome do filme: "); 
         //" %[^\n]" é usado p ler a linha inteira incluindo os espaços
         scanf(" %[^\n]", nome_filme); 
  
         float avaliacao; 
         printf("Avalie o filme %s (avalie de 1 a 5): ", nome_filme); 
         scanf("%f", &avaliacao); 
  
 //condições p ser fav 
  
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
             printf("Não entra nos favoritos.\n"); 
         } 
  
         printf("Deseja colocar outro filme? [S/n]: "); 
         scanf(" %c", &resposta); 
     //funçao limpa tela 
     system("cls");                 
  
     printf("AVALIADOR DE FILMES\n");
     printf("======================\n"); 
 //repeiçao de todo o codigo 
     } while (resposta == 'S' || resposta == 's'); 
 //chamada da funçao q mostra os favs 
     listafavoritos(); 
     
     return 0; 
 }
