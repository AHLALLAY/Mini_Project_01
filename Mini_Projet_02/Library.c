#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char author[100];
    float price;
    int quantity;
} Book;

// helpers
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

void format_books(Book book[], int count){
    printf("========= Books List =========\n");
    printf("| %-25s | %-15s | %-20s | %-20s |\n", "Title", "Author", "Price", "Quantity");
    printf("+---------------------------+-----------------+----------------------+----------------------+\n");
    for (int i = 0; i < count; i++) {
        printf("| %-25s | %-15s | %-20.2f | %-20d |\n", book[i].title, book[i].author, book[i].price, book[i].quantity);
    }
    printf("+---------------------------+-----------------+----------------------+----------------------+\n");   
}

int find_book(Book book[], int count, char title[]){
    for (int i = 0; i < count; i++) {
        if (strcmp(book[i].title, title) == 0) {        
            return i;
        }
    }
    return -1;
}
// main functions
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

void add_books(Book book[], int *count){
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
        read_line(book[*count].title, sizeof(book[*count].title));
        printf("Enter the author: ");
        read_line(book[*count].author, sizeof(book[*count].author));

        printf("Enter the quantity: ");
        scanf("%d", &book[*count].quantity);
        getchar();
        printf("Enter the price: ");
        scanf("%f", &book[*count].price);
        getchar();
        (*count)++;
        printf("------------------------\n");
    }
}

void show_books(Book book[], int count){
    if (count != 0) {
        format_books(book, count);
        system("pause");
    } else {
        printf("No book in stock.\n");
    }
}

void search_book(Book book[], int count){
    char title[100];
    printf("Enter the book title: ");
    read_line(title, sizeof(title));

    int index = find_book(book, count, title);
    if(index >-1){
        format_books(&book[index], 1);
    }else {
        printf("The book does not exist.\n");
    }
    system("pause");
}

void edit_quantity(Book book[], int count){
    char title[100];
    printf("Enter the title: ");
    read_line(title, sizeof(title));

    int index = find_book(book, count, title);
    if(index >-1){
        printf("New quantity: ");
        scanf("%d", &book[index].quantity);
        printf("Quantity updated!\n");
    }else {
        printf("The book does not exist.\n");
    }
    system("pause");
}

void delete_book(Book book[], int *count){
    char title[100];
    printf("Enter the title: ");
    read_line(title, sizeof(title));
    int index = find_book(book, *count, title);
    
    if(index >-1){
        for (int j = index; j < *count - 1; j++) {
            book[j] = book[j + 1];
        }
        (*count)--;
        printf("The book has been deleted!\n");
    }else {
        printf("The book does not exist.\n");
    }
    system("pause");
}

int show_book_count(Book book[], int count){
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += book[i].quantity;
    }
    printf("Total books in stock: %d\n", total);
    system("pause");
    return total;
}

int main() {
    Book book[100];
    int count = 0;
    int choice;

    do {
        show_menu();
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_books(book, &count);
                break;

            case 2:
                show_books(book, count);
                break;

            case 3: {
                search_book(book, count);
                break;
            }

            case 4: {
                edit_quantity(book, count);
                break;
            }

            case 5: {
                delete_book(book, &count);
                break;
            }

            case 6: {
                show_book_count(book, count);
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
