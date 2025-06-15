/*
Random Number Generator - RNG

rand() --> 0 ile RAND_MAX (genellikle 32767) arasında bir tam sayı döndürür.
Her çalıştırmada aynı sayıları üretir. 

Seed
#include <time.h>
srand(time(NULL)) 

rand() her zaman aynı sırayı üretir.
srand() başlangıç değerini ayarlayarak bu sırayı rasgeleleştirir.

- Belirli aralıkta sayı üretmek istiyorsak - [min, max]
int rastgele = (rand() % (max - min + 1)) + min;

int rastgele = (rand() % (100 - 50 + 1) + 50); // 50 ile 100 arasında

- 5 adet 1-100 arasında rastgele sayı üretelim.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // başlangıç seed

    for(int i = 0; i < 5; i++)
    {
        int sayi = (rand() % 100) + 1; // 1 - 100 arası
        printf("%d\n", sayi);
    }

    return 0;
}

-------------------------------------------------------------------------

--------- Rock Paper Scissor ----------------------

- Rock vs Paper --> Paper wins
- Rock vs Scissor --> Rock wins.
- Scissor vs Paper --> Scissor wins.

srand() - rand() --> [0, RAND_MAX] 

- If the number is between 0-33 then the choice will be stone 
- If the number is between 33-66 then the choice will be Paper
- If the number is between 66-99 then the choice will be Scissors.



*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

#define RANGE_STONE     33
#define RANGE_PAPER     66
#define RANGE_SCISSORS  99

#define USER_WINS       1
#define COMPUTER_WINS   0
#define EQUAL           -1

const char* move_to_string(char move)
{
    switch (move)
    {
        case 'r': return "ROCK";
        case 'p': return "PAPER";
        case 's': return "SCISSORS";
        default: return "UNKNOWN";
    }
}

int rock_paper_scissors(char we, char computer)
{
    if(we == computer) return EQUAL;

    if(we == 'r' && computer == 'p') return COMPUTER_WINS;
    if(we == 'p' && computer == 'r') return USER_WINS;
    if(we == 'r' && computer == 's') return USER_WINS;
    if(we == 's' && computer == 'r') return COMPUTER_WINS;
    if(we == 'p' && computer == 's') return COMPUTER_WINS;
    if(we == 's' && computer == 'p') return USER_WINS;

    return -2; // geçersiz
}

char generate_computer_choice()
{
    int number = rand() % 100;

    if(number < RANGE_STONE) return 'r';
    else if (number < RANGE_PAPER) return 'p';
    else return 's';

}

int main()
{
    srand(time(NULL));

    int win_count = 0, lose_count = 0, draw_count = 0;
    char play_again;

    do
    {
        char we, computer;
        int result;

        printf("---------------------------\n");
        printf("---- Enter r for ROCK -----\n");
        printf("---- Enter p for PAPER ----\n");
        printf("---- Enter s for SCIS. ----\n");
        printf("---------------------------\n");

        // getchar(); // önceki newline temizlenir
        scanf(" %c", &we);
        we = tolower(we);

        if(we != 'r' && we != 'p' && we != 's')
        {
            printf("Gecersiz secim!\n");
            continue;
        }

        computer = generate_computer_choice();
        result = rock_paper_scissors(we, computer);

        switch (result)
        {
            case EQUAL:
                printf("----- GAME DRAW! ----\n\n");
                draw_count++;
                break;
            
            case USER_WINS:
                printf("----- GAME WIN! -----\n\n");
                win_count++;
                break;

            case COMPUTER_WINS:
                printf("----- GAME LOST! ----\n\n");
                lose_count++;
                break;
            
            default:
                printf("Bir hata olustu!\n");
                break;
        }

        printf("You choose:      %s\n", move_to_string(we));
        printf("Computer choose: %s\n", move_to_string(computer));

        printf("\n Do you want to play again? (y/n): ");
        // getchar();
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');
    
    // Skor Tablosu
    printf("\n=====================\n");
    printf("    Final Score     \n");
    printf(" Wins:        %d\n", win_count);
    printf(" Losses:      %d\n", lose_count);
    printf(" Draws:       %d\n", draw_count);
    printf("\n=====================\n");

    return 0;
}