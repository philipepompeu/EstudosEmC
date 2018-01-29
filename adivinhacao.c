#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{  
 
    printf("_______  ______   ___  __   __  ___  __    _  __   __  _______  ______   \n");
    printf("|   _   ||      | |   ||  | |  ||   ||  |  | ||  | |  ||   _   ||      | \n");
    printf("|  |_|  ||  _    ||   ||  |_|  ||   ||   |_| ||  |_|  ||  |_|  ||___   | \n");
    printf("|       || | |   ||   ||       ||   ||       ||       ||       |  __|  | \n");
    printf("|       || |_|   ||   ||       ||   ||  _    ||       ||       | |_____| \n");
    printf("|   _   ||       ||   | |     | |   || | |   ||   _   ||   _   |   __    \n");
    printf("|__| |__||______| |___|  |___|  |___||_|  |__||__| |__||__| |__|  |__|   \n");
    
    srand(time(0));
    int numeroSecreto = (rand() % 100);
    int chute;
    int ganhou = 0;
    int tentativas = 1;
    int numeroTentativas = 5;
    int acertou = 0;
    double pontos = 1000;

    int nivel;
    printf("Escolha a dificuldade do jogo:\n");
    printf("(1)Facil (2) Medio (3) Dificil \n");
    scanf("%d", &nivel);

    switch(nivel)
    {
        case 1: 
            numeroTentativas = 20;
            break;
        case 2: 
            numeroTentativas = 12;
            break;
        default: 
            numeroTentativas = 6;
            break;
    }
    
    for(int i = 1; i <= numeroTentativas; i++)
    //while(/*ganhou == 0*/1)
    {
        //printf("Chute %d de %d \n", i, NUMERO_TENTATIVAS);
        //printf("Chute %d\n", tentativas);
        printf("[Tentativa n.%d] Qual eh o seu chute? ", tentativas);
        
        scanf("%d", &chute);
        //printf("Seu chute foi %d \n", chute);

        if(chute < 0)
        {
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = (chute > numeroSecreto);
        //int menor = (chute < numeroSecreto);
    
        tentativas++;

        pontos -= abs(chute - numeroSecreto) / (double)2;//Pontos perdidos
        if(acertou)
        {
            //printf("Voce acertou!\n");
           // ganhou = 1;
            break;
        }else if(maior)
        {
            printf("%d eh maior que o numero secreto\n", chute);            
        }else// if(menor)
        {
            printf("%d eh menor que o numero secreto\n", chute);
        }
    }    
    
    
    if(acertou)
    {        
        printf(" _______  _______  __    _  __   __  _______  __   __   ___  ____   \n");
        printf("|       ||   _   ||  |  | ||  | |  ||       ||  | |  | |   ||    |  \n");
        printf("|    ___||  |_|  ||   |_| ||  |_|  ||   _   ||  | |  | |___||_    | \n");
        printf("|   | __ |       ||       ||       ||  | |  ||  |_|  |  ___   |   | \n");
        printf("|   ||  ||       ||  _    ||       ||  |_|  ||       | |   |  |   | \n");
        printf("|   |_| ||   _   || | |   ||   _   ||       ||       | |___| _|   | \n");
        printf("|_______||__| |__||_|  |__||__| |__||_______||_______|      |____|  \n");
 
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n",pontos);
    }else
    {        
        printf("_______  _______  ______    ______   _______  __   __   ___   ____  \n");
        printf("|       ||       ||    _ |  |      | |       ||  | |  | |   | |    | \n");
        printf("|    _  ||    ___||   | ||  |  _    ||    ___||  | |  | |___||    _| \n");
        printf("|   |_| ||   |___ |   |_||_ | | |   ||   |___ |  |_|  |  ___ |   |   \n");
        printf("|    ___||    ___||    __  || |_|   ||    ___||       | |   ||   |   \n");
        printf("|   |    |   |___ |   |  | ||       ||   |___ |       | |___||   |_  \n");
        printf("|___|    |_______||___|  |_||______| |_______||_______|       |____| \n"); 
        printf("O numero era %d. \n", numeroSecreto);
    }
    
    printf("Fim de jogo.\n");   
}