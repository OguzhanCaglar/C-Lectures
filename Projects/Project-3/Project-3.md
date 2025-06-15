## --------- Rock Paper Scissor ----------------------

- Rock vs Paper --> Paper wins
- Rock vs Scissor --> Rock wins.
- Scissor vs Paper --> Scissor wins.

srand() - rand() --> [0, RAND_MAX] 

- If the number is between 0-33 then the choice will be stone 
- If the number is between 33-66 then the choice will be Paper
- If the number is between 66-99 then the choice will be Scissors.

## ---------------------------- V1 -----------------------------------------------------

```c
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define RANGE_STONE     33
#define RANGE_PAPER     66
#define RANGE_SCISSORS  99

#define USER_WINS       1
#define COMPUTER_WINS   0
#define EQUAL           -1

int rock_paper_scissors(char we, char computer)
{
    if(we == computer)
    {
        return EQUAL;
    }

    if(we == 'r' && computer == 'p')
    {
        return COMPUTER_WINS;
    }

    else if(we == 'p' && computer == 'r')
    {
        return USER_WINS;
    }

    if(we == 'r' && computer == 's')
    {
        return USER_WINS;
    }

    else if(we == 's' && computer == 'r')
    {
        return COMPUTER_WINS;
    }

    if(we == 'p' && computer == 's')
    {
        return COMPUTER_WINS;
    }

    else if(we == 's' && computer == 'p')
    {
        return USER_WINS;
    }
}

int main()
{
    int number; 

    char we, computer, result;

    srand(time(NULL));

    number = rand() % 100; 

    if(number < RANGE_STONE)
    {
        computer = 'r'; //rock
    }
    else if(number > RANGE_STONE && number < RANGE_PAPER)
    {
        computer = 'p';
    }
    else if(number > RANGE_PAPER && number < RANGE_SCISSORS)
    {
        computer = 's';
    }
    else
    {
        computer = ' ';
    }

    printf("---------------------------\n");
    printf("---- Enter r for ROCK -----\n");
    printf("---- Enter p for PAPER ----\n");
    printf("---- Enter s for SCIS. ----\n");
    printf("---------------------------\n");

    scanf("%c", &we);

    if((we != 'r') || (we != 'p') || (we != 's'))
    {
        printf("You entered wrong value: %c!\nExiting....", we);
        return -1;
    }

    result = rock_paper_scissors(we, computer);

    switch (result)
    {
        case EQUAL:
            printf("----- GAME DRAW! ----\n\n");
            break;
        
        case USER_WINS:
            printf("----- GAME WIN! -----\n\n");
            break;

        case COMPUTER_WINS:
            printf("----- GAME LOST! ----\n\n");
            break;
        
        default:
            break;
    }

    printf("----------------------\n");
    printf("We choose: %c\nComputer Choose: %c\n", we, computer);
    printf("----------------------\n");

    return 0;
}
```

## ---------------------------- V2 -----------------------------------------------------

- Skor Sistemi --> Kaç galibiyet, beraberlik, yenilgi
- Tekrar oynama döngüsü --> Kullanıcı "y" dedikçe oyun tekrar eder.
- Bilinmeyen karakter kontrolü --> scanf("%c") sonrası boşluk karakter problemi
- Seçimleri metinle göster --> 'r' yerine ROCK yazsın.
- Büyük harf girdisi kabulü --> 'R', 'P', 'S' gibi girişler de geçerli olsun.

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

## ---------------------------- V3 -----------------------------------------------------

### --- ÖDEV ---

1) Oyun başında kullanıcı adı alınır.
2) Her turnuvada Best-of-3 oynanır (ilk 2 galibiyet alan kazanır.)
3) Skor, en iyi galibiyet serisi (streak) ve toplam oynama, kullanıcı adıyla birlikte score.txt
dosyasına kaydedilir.
4) Kapanışta skor tekrar dosyadan okunup ekrana yazılır.