#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCENDING  1
#define DESCENDING 2

typedef struct {
    char name[50];
    char phone[15];
    char email[60];
} Contact;

void show_main_menu(){
    system("cls");
    system("color 0F");
    printf("============== Main Menu ==============\n");
    printf("1- Add Contacts\n");
    printf("2- Display Contacts\n");
    printf("3- Edit Contacts\n");
    printf("4- Delete Contacts\n");
    printf("5- Search Contacts\n");
    printf("6- Statistics\n");
    printf("7- Exit\n");
}

void show_add_menu(){
    system("cls");
    printf("============== Add Menu ==============\n");
    printf("1- Add one Contact\n");
    printf("2- Add several Contacts\n");
    printf("3- Back\n");
}

void show_display_menu(){
    system("cls");
    printf("============== Display Menu ==============\n");
    printf("1- Simple display\n");
    printf("2- Display in ascending order\n");
    printf("3- Display in descending order\n");
    printf("4- Back\n");
}

int ask_count(){
    int count;
    printf("How many contacts do you have? ");
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

void copy_contacts(Contact destination[], Contact source[], int count){
    for(int i = 0; i < count; i++){
        destination[i] = source[i];
    }
}

void sort_contacts(Contact contacts[], int count, int order){
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            int comparison = strcmp(contacts[i].name, contacts[j].name);
            if((order == ASCENDING && comparison > 0)||(order == DESCENDING && comparison < 0)) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
}

void show_contacts(Contact contacts[], int count){
    printf("========= Contact List =========\n");
    printf("| %-25s | %-15s | %-30s |\n", "Name", "Phone", "Email");
    printf("+---------------------------+-----------------+-------------------------------+\n");
    for (int i = 0; i < count; i++) {
        printf("| %-25s | %-15s | %-30s |\n", contacts[i].name, contacts[i].phone, contacts[i].email);
    }
    printf("+---------------------------+-----------------+-------------------------------+\n");
}

void show_sorted_contacts(Contact ordered[], Contact contacts[], int count, int order){
    if(count == 0){
        printf("No contact to display.\n");
    }else{
        copy_contacts(ordered, contacts, count);
        sort_contacts(ordered, count, order);
        show_contacts(ordered, count);
    }
    system("pause");
}

void add_one_contact(Contact contacts[], int *count){
    if (*count < 100) {
        printf("Name: ");
        read_line(contacts[*count].name, sizeof(contacts[*count].name));
        printf("Phone: ");
        read_line(contacts[*count].phone, sizeof(contacts[*count].phone));
        printf("Email: ");
        read_line(contacts[*count].email, sizeof(contacts[*count].email));
        (*count)++;
        printf("Contact added successfully.\n");
    } else {
        printf("/_\\ Memory is full !!\n");
    }
}

void add_many_contacts(Contact contacts[], int *count){
    int how_many = ask_count();
    if(how_many < 1) return;
    if (how_many > 100 - *count) {
        printf("You need a number in this range [1, %d].\n", 100 - *count);
        return;
    }
    getchar();
    for (int i = 0; i < how_many; i++) {
        add_one_contact(contacts, count);
    }
}

void show_contact_list(Contact contacts[], int count){
    if (count == 0) {
        printf("No contact to display.\n");
    } else {
        show_contacts(contacts, count);
    }
    system("pause");
}

void edit_contact(Contact contacts[], int count){
    printf("========= Edit Contact =========\n");
    char name[50];
    printf("Enter the name of the contact to edit: ");
    read_line(name, sizeof(name));

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            printf("New name: ");
            read_line(contacts[i].name, sizeof(contacts[i].name));
            printf("New phone: ");
            read_line(contacts[i].phone, sizeof(contacts[i].phone));
            printf("New email: ");
            read_line(contacts[i].email, sizeof(contacts[i].email));
            printf("Contact updated successfully.\n");
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void delete_contact(Contact contacts[], int *count){
    printf("========= Delete Contact =========\n");
    char name[50];
    printf("Enter the name of the contact to delete: ");
    read_line(name, sizeof(name));

    int found = 0;
    for (int i = 0; i < *count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *count - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*count)--;
            printf("Contact deleted successfully.\n");
            return;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void search_contact(Contact contacts[], int count){
    printf("========= Search Contact =========\n");
    char name[50];
    printf("Enter the name of the contact to search: ");
    read_line(name, sizeof(name));

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            found = 1;
            printf("Contact found:\n");
            printf("Name: %s\n", contacts[i].name);
            printf("Phone: %s\n", contacts[i].phone);
            printf("Email: %s\n", contacts[i].email);
            return;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

void show_contact_count(int count){
    printf("Total number of contacts: %d\n", count);
}

int main() {
    Contact contacts[100];
    Contact ordered[100];
    int count = 0;
    int choice;

    do {
        show_main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1: {
                int add_choice;
                do {
                    show_add_menu();
                    printf("Enter your choice: ");
                    scanf("%d", &add_choice);
                    getchar();

                    switch (add_choice) {
                        case 1: {
                            add_one_contact(contacts, &count);
                            break;
                        }
                        case 2: {
                            add_many_contacts(contacts, &count);
                            break;
                        }
                        case 3:
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (add_choice != 3);
                break;
            }
            case 2: {
                int display_choice;
                do {
                    show_display_menu();
                    printf("Enter your choice: ");
                    scanf("%d", &display_choice);
                    getchar();

                    switch (display_choice) {
                        case 1: {
                            show_contact_list(contacts, count);
                            break;
                        }
                        case 2:{
                            show_sorted_contacts(ordered, contacts, count, ASCENDING);
                            break;
                        }
                        case 3: {
                            show_sorted_contacts(ordered, contacts, count, DESCENDING);
                            break;
                        }
                        case 4:
                            break;
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (display_choice != 4);
                break;
            }
            case 3: {
                edit_contact(contacts, count);
                break;
            }
            case 4: {
                delete_contact(contacts, &count);
                break;
            }
            case 5: {
                search_contact(contacts, count);
                break;
            }
            case 6: {
                show_contact_count(count);
                break;
            }
            case 7: {
                printf("Goodbye!\n");
                break;
            }
            default:
                printf("Invalid choice!\n");
                break;
        }
        system("pause");
    } while (choice != 7);

    return 0;
}
