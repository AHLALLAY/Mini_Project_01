#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char titre[100][100], auteur[100][100]; // store multiple titles and authors
    float prix[100];
    int Quantite[100];
    int livre = 0, n;
    int choix;

    do {
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
        printf("Your choice: ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                printf("======== Add a Book to Stock ========\n");
                printf("How many books do you want to add: ");
                scanf("%d", &n);
                getchar();
                for (int i = 0; i < n; i++) {
                    printf("Enter the title: ");
                    fgets(titre[livre], sizeof(titre[livre]), stdin); // fgets: titles may contain spaces
                    titre[livre][strcspn(titre[livre], "\n")] = 0; // strip newline
                    printf("Enter the author: ");
                    fgets(auteur[livre], sizeof(auteur[livre]), stdin);
                    auteur[livre][strcspn(auteur[livre], "\n")] = 0; // strip newline

                    printf("Enter the quantity: ");
                    scanf("%d", &Quantite[livre]);
                    getchar();
                    printf("Enter the price: ");
                    scanf("%f", &prix[livre]);
                    getchar();
                    livre++;
                    printf("------------------------\n");
                }
                break;

            case 2:
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
                break;

            case 3: {
                char searchTitle[100];
                printf("Enter the book title: ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = 0; // strip newline

                int exist = 0;
                for (int i = 0; i < livre; i++) {
                    if (strcmp(titre[i], searchTitle) == 0) {
                        printf("Book found:\n");
                        printf("Title: %s\n", titre[i]);
                        printf("Author: %s\n", auteur[i]);
                        printf("Price: %.2f\n", prix[i]);
                        printf("Quantity: %d\n", Quantite[i]);
                        exist = 1;
                        break;
                    }
                }
                if (!exist) {
                    printf("The book does not exist.\n");
                    system("pause");
                }
                break;
            }

            case 4: {
                char updateTitle[100];
                printf("Enter the title: ");
                fgets(updateTitle, sizeof(updateTitle), stdin);
                updateTitle[strcspn(updateTitle, "\n")] = 0; // strip newline
                int a_jour = 0;
                for (int i = 0; i < livre; i++) {
                    if (strcmp(titre[i], updateTitle) == 0) {
                        printf("New quantity: ");
                        scanf("%d", &Quantite[i]);
                        printf("Quantity updated!\n");
                        a_jour = 1;
                        break;
                    }
                }
                if (!a_jour) {
                    printf("The book does not exist.\n");
                    system("pause");
                }
                break;
            }

            case 5: {
                char deleteTitle[100];
                printf("Enter the title: ");
                fgets(deleteTitle, sizeof(deleteTitle), stdin);
                deleteTitle[strcspn(deleteTitle, "\n")] = 0; // strip newline
                int deleted = 0;
                for (int i = 0; i < livre; i++) {
                    if (strcmp(titre[i], deleteTitle) == 0) {
                        for (int j = i; j < livre - 1; j++) {
                            strcpy(titre[j], titre[j + 1]);
                            strcpy(auteur[j], auteur[j + 1]);
                            prix[j] = prix[j + 1];
                            Quantite[j] = Quantite[j + 1];
                        }
                        livre--;
                        printf("The book has been deleted!\n");
                        deleted = 1;
                        break;
                    }
                }
                if (!deleted) {
                    printf("The book does not exist.\n");
                    system("pause");
                }
                break;
            }

            case 6: {
                int total = 0;
                for (int i = 0; i < livre; i++) {
                    total += Quantite[i];
                }
                printf("Total books in stock: %d\n", total);
                system("pause");
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
