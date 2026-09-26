#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_menu(){
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

int ask_count(){
    int count;
    printf("How many books do you have? ");
    scanf("%d", &count);
    if(count<1){
        printf("Invalid number.\n");
        return -1;
    }
    return count;
}

void read_line(char *text, int size){
    fgets(text, size, stdin);
    text[strcspn(text, "\n")] = 0;
}

void add_books(char titles[][100], char authors[][100], int quantities[], float prices[], int *count){
    printf("======== Add a Book to Stock ========\n");
    int how_many = ask_count();
    if(how_many < 1) return;
    if (how_many > 100 - *count) {
        printf("You need a number in this range [1, %d].\n", 100 - *count);
        return;
    }
    getchar();
    for (int i = 0; i < how_many; i++) {
        printf("Enter the title: ");
        read_line(titles[*count], sizeof(titles[*count]));
        printf("Enter the author: ");
        read_line(authors[*count], sizeof(authors[*count]));

        printf("Enter the quantity: ");
        scanf("%d", &quantities[*count]);
        getchar();
        printf("Enter the price: ");
        scanf("%f", &prices[*count]);
        getchar();
        (*count)++;
        printf("------------------------\n");
    }
}

void show_books(char titles[][100], char authors[][100], int quantities[], float prices[], int count){
    if (count != 0) {
        for (int i = 0; i < count; i++) {
            printf("Book %d:\n", i + 1);
            printf("Title: %s\n", titles[i]);
            printf("Author: %s\n", authors[i]);
            printf("Price: %.2f\n", prices[i]);
            printf("Quantity: %d\n", quantities[i]);
            printf("--------------------\n");
        }
        system("pause");
    } else {
        printf("No book in stock.\n");
    }
}

void search_book(char titles[][100], char authors[][100], int quantities[], float prices[], int count){
    char title[100];
    printf("Enter the book title: ");
    read_line(title, sizeof(title));

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", titles[i]);
            printf("Author: %s\n", authors[i]);
            printf("Price: %.2f\n", prices[i]);
            printf("Quantity: %d\n", quantities[i]);
            found = 1;
            return;
        }
    }
    if (!found) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

void edit_quantity(char titles[][100], int quantities[], int count){
    char title[100];
    printf("Enter the title: ");
    read_line(title, sizeof(title));
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(titles[i], title) == 0) {
            printf("New quantity: ");
            scanf("%d", &quantities[i]);
            printf("Quantity updated!\n");
            found = 1;
            return;
        }
    }
    if (!found) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

void delete_book(char titles[][100], char authors[][100], int quantities[], float prices[], int *count){
    char title[100];
    printf("Enter the title: ");
    read_line(title, sizeof(title));
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(titles[i], title) == 0) {
            for (int j = i; j < *count - 1; j++) {
                strcpy(titles[j], titles[j + 1]);
                strcpy(authors[j], authors[j + 1]);
                prices[j] = prices[j + 1];
                quantities[j] = quantities[j + 1];
            }
            (*count)--;
            printf("The book has been deleted!\n");
            found = 1;
            return;
        }
    }
    if (!found) {
        printf("The book does not exist.\n");
        system("pause");
    }
}

int show_book_count(int quantities[], int count){
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += quantities[i];
    }
    printf("Total books in stock: %d\n", total);
    system("pause");
    return total;
}

int main() {
    char titles[100][100], authors[100][100];
    float prices[100];
    int quantities[100];
    int count = 0;
    int choice;

    do {
        show_menu();
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_books(titles, authors, quantities, prices, &count);
                break;

            case 2:
                show_books(titles, authors, quantities, prices, count);
                break;

            case 3: {
                search_book(titles, authors, quantities, prices, count);
                break;
            }

            case 4: {
                edit_quantity(titles, quantities, count);
                break;
            }

            case 5: {
                delete_book(titles, authors, quantities, prices, &count);
                break;
            }

            case 6: {
                show_book_count(quantities, count);
                break;
            }

            case 7:
                printf("Goodbye!\n");
                break;

            default:
                printf("Your choice is not in the menu 0_0 !!\n");
        }
    } while (choice != 7);

    return 0;
}
