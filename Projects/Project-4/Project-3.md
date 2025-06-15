## --------- Hangman ----------------------

- Hangman game is basically to take a secret word and guess it letter by letter.

## ---------------------------- V1 -----------------------------------------------------

```C
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define     mMaxTryCount      6
#define     mMaxWordLength    50

struct sWordWithHint {
    char cWord[mMaxWordLength];
    char cHint[mMaxWordLength];
};


void fDrawHangman(int tries)
{
    const char* hangmanParts[] 
    = { "     _________",    "    |         |", 
        "    |         O",   "    |        /|\\",
        "    |        / \\", "    |" };

    
    printf("\n");

    for(int i = 0; i <= tries; i++)
    {
        printf("%s\n", hangmanParts[i]);
    }


}

// elma
// _l_ma

void fDisplayWord(const char word[], const bool guessed[])
{
    printf("Word: ");

    for(int i = 0; word[i] != '\0'; i++)
    {
        if(guessed[word[i] - 'a'])
        {
            printf("%c ", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}

int main()
{
    struct sWordWithHint aWordList[] = {
        { "Ronaldo", "A famous footballer" },
        { "pizza", "A delicious italian dish"},
        { "baklava", "A Famous turkish desert"},
        { "elephant", "A big animal with a trunk"}
    };

    srand(time(NULL)); 

    int iWordIndex = rand() % 4;

    const char* cSecretWord = aWordList[iWordIndex].cWord;
    const char* cSecretHint = aWordList[iWordIndex].cHint;

    int iWordLength = strlen(cSecretWord);
    char cGuessedWord[mMaxWordLength] = { 0 };
    bool cGuessedLetters[26] = { false };

    printf("Welcome to Hangman!\n");
    printf("Hint: %s\n", cSecretHint);

    int iTries = 0;

    while (iTries < mMaxTryCount)
    {
        printf("\n");
        fDisplayWord(cSecretWord, cGuessedLetters);
        fDrawHangman(iTries);

        char cGuess;
        printf("Enter a letter: "),
        scanf(" %c", &cGuess);
        cGuess = tolower(cGuess);

        if(cGuessedLetters[cGuess - 'a'])
        {
            printf("You have already guessed that letter. "
                    "Try Again.\n");
            continue;
        }

        cGuessedLetters[cGuess - 'a'] = true;

        bool bFound = false;
        for (int i = 0; i < iWordLength; i++)
        {
            if(cSecretWord[i] == cGuess)
            {
                bFound = true;
                cGuessedWord[i] = cGuess;
            }
        }

        if (bFound)
        {
            printf("Good guess!\n");
        }
        else
        {
            printf("Sorry, the letter '%c' is not in the word.\n", cGuess);

            iTries++;
        }

        if(strcmp(cSecretWord, cGuessedWord) == 0)
        {
            printf("\nCongratulations! You have guessed the word: %s\n", cSecretWord);
            break;
        }  
    }

    if(iTries >= mMaxTryCount)
    {
        printf("\nSorry, you have run out of tries. The word was: %s\n", cSecretWord);
    }

    return 0;
}
```

```bash
Welcome to Hangman!
Hint: A delicious italian dish

Word: _ _ _ _ _

     _________
Enter a letter: o
Sorry, the letter 'o' is not in the word.

Word: _ _ _ _ _

     _________
    |         |
Enter a letter: g
Sorry, the letter 'g' is not in the word.

Word: _ _ _ _ _

     _________
    |         |
    |         O
Enter a letter: u
Sorry, the letter 'u' is not in the word.

Word: _ _ _ _ _

     _________
    |         |
    |         O
    |        /|\
Enter a letter: z
Good guess!

Word: _ _ z z _

     _________
    |         |
    |         O
    |        /|\
Enter a letter: h 
Sorry, the letter 'h' is not in the word.

Word: _ _ z z _

     _________
    |         |
    |         O
    |        /|\
    |        / \
```

## ---------------------------- V2 -----------------------------------------------------

- Büyük harf ile ilgili bir sorun var. Eğer tahmin edilecek kelimede büyük harf var ise 
bunu programın başında bastırmakta.

Welcome to Hangman!
Hint: A famous footballer

Word: R _ _ _ _ _ _

     _________

-- ÖDEV: ---

- Şu an "Ronaldo" ve "ronaldo" farklı harfler olarak algılanır. Hepsini küçük harfe çevirerek işle.
- Şu an 4 kelime var, kelimeler ve ipucular dosyadan (words.txt) okunabilir.
- Oyun sonunda "tekrar oyna" seçeneği eklenebilir.
- Tüm yanlış tahmin edilen harfleri ekrana listelenebilir.
- Skor tutma (kaç doğru/yanlış, kaç oyun kazanıldı).
- Oyun geçmişi dosyada tutulabilir.
- Kelimeyi veya ipucunu kullanıcı ekleyebilir. 
- İki oyunculu mod eklenebilir.