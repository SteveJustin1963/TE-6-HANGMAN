 




#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char secret_word[20];
    char player_guess;
    int i, length, chances, flag;
    
    printf("Enter the secret word: ");
    scanf("%s", secret_word);
    length = strlen(secret_word);
    
    char player_guess_word[length];
    
    chances = length + 2;
    
    for(i=0; i<length; i++)
    {
        player_guess_word[i] = '_';
    }
    
    while(chances != 0)
    {
        flag = 0;
        printf("\nEnter your guess: ");
        scanf(" %c", &player_guess);
        
        for(i=0; i<length; i++)
        {
            if(secret_word[i] == player_guess)
            {
                player_guess_word[i] = player_guess;
                flag = 1;
            }
        }
        
        if(flag == 0)
        {
            chances--;
        }
        
        printf("\n");
        
        for(i=0; i<length; i++)
        {
            printf("%c ", player_guess_word[i]);
        }
        
        if(strcmp(secret_word, player_guess_word) == 0)
        {
            printf("\nCongratulations, you won the game!\n");
            break;
        }
        
        printf("\n\nYou have %d chances left.\n", chances);
    }
    
    if(chances == 0)
    {
        printf("\nYou lost the game!\n");
        printf("The secret word was: %s\n", secret_word);
    }
    
    return 0;
}
