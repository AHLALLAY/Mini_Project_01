#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void head(){
    system("cls");
    system("color 09");
    printf("/============== Library Manager ===============\\\n");
    printf("|1- Add a book to stock.                       |\n");
    printf("|2- Display all available books.               |\n");
    printf("|3- Search a book by title.                    |\n");
    printf("|4- Update a book quantity.                    |\n");
    printf("|5- Delete a book from stock.                  |\n");
    printf("|6- Display the total number of books in stock.|\n");
    printf("|7- Exit.                                      |\n");
    printf("\\==============================================/\n");
}

int demander_combien(){
    int x;
    printf("How many books do you have? ");
    scanf("%d", &x);
    if(x<1){
        printf("Invalid number.\n");
        return -1;
    }
    return x;
}

void getLine(char *buff, int size){
    fgets(buff, size, stdin);
    buff[strcspn(buff, "\n")] = 0;
}

void createBook(char titre[][100], char auteur[][100], int Quantite[], float prix[], int *livre){
    printf("======== Add a Book to Stock ========\n");
    int n = demander_combien();
    if(n < 1) return;
    if (n > 100 - *livre) {
        printf("You need a number in this range [1, %d].\n", 100 - *livre);
        return;
    }
    getchar();
    for (int i = 0; i < n; i++) {
        printf("Enter the title: ");
        getLine(titre[*livre], sizeof(titre[*livre]));
        printf("Enter the author: ");
        getLine(auteur[*livre], sizeof(auteur[*livre]));

        printf("Enter the quantity: ");
        scanf("%d", &Quantite[*livre]);
        getchar();
        printf("Enter the price: ");
        scanf("%f", &prix[*livre]);
        getchar();
        (*livre)++;
        printf("------------------------\n");
    }
}

void readAllbooks(char titre[][100], char auteur[][100], int Quantite[], float prix[], int livre){
    if (livre != 0) {
        for (int i = 0; i < livre; i++) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", titre[i]);
            printf("Author: %s\n", auteur[i]);
            printf("Price: %.2f\n", prix[i]);
            printf("Quantity: %d\n", Quantite[i]);
            printf("--------------------\n");
        }
        system("pause");
    } else {
        printf("No book in stock.\n");
    }
}

void findBook(char titre[][100], char auteur[][100], int Quantite[], float prix[], int livre){
    char searchTitle[100];
    printf("Enter the book title: ");
    getLine(searchTitle, sizeof(searchTitle));
    
    int exist = 0;
    for (int i = 0; i < livre; i++) {
        if (strcmp(titre[i], searchTitle) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", titre[i]);
            printf("Author: %s\n", auteur[i]);
            printf("Price: %.2f\n", prix[i]);
            printf("Quantity: %d\n", Quantite[i]);
            exist = 1;
            return;
        }
    }
    if (!exist) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

void updateBookQuantity(char titre[][100], int Quantite[], int livre){
    char updateTitle[100];
    printf("Enter the title: ");
    getLine(updateTitle, sizeof(updateTitle));
    int a_jour = 0;
    for (int i = 0; i < livre; i++) {
        if (strcmp(titre[i], updateTitle) == 0) {
            printf("New quantity: ");
            scanf("%d", &Quantite[i]);
            printf("Quantity updated!\n");
            a_jour = 1;
            return;
        }
    }
    if (!a_jour) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

void deleteBook(char titre[][100], char auteur[][100], int Quantite[], float prix[], int *livre){
    char deleteTitle[100];
    printf("Enter the title: ");
    getLine(deleteTitle, sizeof(deleteTitle));
    int deleted = 0;
    for (int i = 0; i < *livre; i++) {
        if (strcmp(titre[i], deleteTitle) == 0) {
            for (int j = i; j < *livre - 1; j++) {
                strcpy(titre[j], titre[j + 1]);
                strcpy(auteur[j], auteur[j + 1]);
                prix[j] = prix[j + 1];
                Quantite[j] = Quantite[j + 1];
            }
            (*livre)--;
            printf("The book has been deleted!\n");
            deleted = 1;
            return;
        }
    }
    if (!deleted) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

int bookTotal(int Quantite[], int livre){
    int total = 0;
    for (int i = 0; i < livre; i++) {
        total += Quantite[i];
    }
    printf("Total books in stock: %d\n", total);
    system("pause");
    return total;
}

int main() {
    char titre[100][100], auteur[100][100]; // store multiple titles and authors
    float prix[100];
    int Quantite[100];
    int livre = 0;
    int choix;
    
    do {
        head();
        printf("Your choice: ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                createBook(titre, auteur, Quantite, prix, &livre);
                break;

            case 2:
                readAllbooks(titre, auteur, Quantite, prix, livre);
                break;

            case 3: {
                findBook(titre, auteur, Quantite, prix, livre);
                break;
            }

            case 4: {
                updateBookQuantity(titre, Quantite, livre);
                break;
            }

            case 5: {
                deleteBook(titre, auteur, Quantite, prix, &livre);
                break;
            }

            case 6: {
                bookTotal(Quantite, livre);
                break;
            }

            case 7:
                printf("Goodbye!\n");
                break;

            default:
                printf("Your choice is not in the menu 0_0 !!\n");
        }
    } while (choix != 7);

    return 0;
}
