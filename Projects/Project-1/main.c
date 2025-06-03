#include <stdio.h>
#include "notepad.h"
#include "password.h"

/* ==== COMMAND LIST === */
#define ADD_COMMAND                 1
#define VIEW_COMMAND                2
#define SEARCH_COMMAND              3
#define DELETE_COMMAND              4
#define CHANGE_PASS_COMMAND         5
#define VIEW_CATEGORIES_COMMAND     6
#define EXIT_COMMAND                7

int main()
{   
    if(!checkPassword())
    {
        return 1; // Sifre yanlis oldugundan programdan cikiliyor.
    }    
    
    int choice;

    do
    {
        printf("=== Kisisel Not Defteri ===\n");
        printf("%d. Not Ekle\n", ADD_COMMAND);
        printf("%d. Notlari Goruntule\n", VIEW_COMMAND);
        printf("%d. Not Ara\n", SEARCH_COMMAND);
        printf("%d. Not Sil\n", DELETE_COMMAND);
        printf("%d. Sifre Degistir\n", CHANGE_PASS_COMMAND);
        printf("%d. Kategoriye Gore Notlari Goruntule\n", VIEW_CATEGORIES_COMMAND);
        printf("%d. Cikis\n", EXIT_COMMAND);
        printf("Seciminiz: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case ADD_COMMAND:
                addNote();
                break;
            
            case VIEW_COMMAND:
                viewNotes();
                break;
            
            case SEARCH_COMMAND:
                searchNotes();
                break;

            case DELETE_COMMAND:
                deleteNote();
                break;
            
            case CHANGE_PASS_COMMAND:
                changePassword();
                break;
            
            case VIEW_CATEGORIES_COMMAND:
                viewNotesByCategory();
                break;
            
            case EXIT_COMMAND:
                printf("Programdan cikiliyor...\n");
                break;
            
            default:
                printf("Gecersiz Secim!\n");
        }
    } while (choice != EXIT_COMMAND);
    

    return 0;
}