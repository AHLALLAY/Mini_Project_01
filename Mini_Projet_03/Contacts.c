#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char tele[15];
    char mail[60];
} Contact;

int main() {
    Contact c[100]; // fixed-size array
    Contact swap[100];
    int compteur = 0;
    int choix;

    do {
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
        printf("Enter your choice: ");
        scanf("%d", &choix);
        getchar(); // clear leftover newline

        switch (choix) {
            case 1: {
                int add_choice;
                do {
                    system("cls");
                    printf("============== Add Menu ==============\n");
                    printf("1- Add one Contact\n");
                    printf("2- Add several Contacts\n");
                    printf("3- Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &add_choice);
                    getchar(); // clear leftover newline

                    switch (add_choice) {
                        case 1: {
                            if (compteur < 100) {
                                printf("Name: ");
                                fgets(c[compteur].name, sizeof(c[compteur].name), stdin);
                                strtok(c[compteur].name, "\n"); // remove newline
                                printf("Phone: ");
                                fgets(c[compteur].tele, sizeof(c[compteur].tele), stdin);
                                strtok(c[compteur].tele, "\n"); // remove newline
                                printf("Email: ");
                                fgets(c[compteur].mail, sizeof(c[compteur].mail), stdin);
                                strtok(c[compteur].mail, "\n"); // remove newline
                                compteur++;
                                printf("Contact added successfully.\n");
                            } else {
                                printf("/_\\ Memory is full !!\n");
                            }
                            break;
                        }
                        case 2: {
                            int n;
                            printf("How many contacts do you want to add? ");
                            scanf("%d", &n);
                            getchar(); // clear leftover newline
                            for (int i = 0; i < n && compteur < 100; i++) {
                                printf("Contact #%d\n", compteur + 1);
                                printf("Name: ");
                                fgets(c[compteur].name, sizeof(c[compteur].name), stdin);
                                strtok(c[compteur].name, "\n");
                                printf("Phone: ");
                                fgets(c[compteur].tele, sizeof(c[compteur].tele), stdin);
                                strtok(c[compteur].tele, "\n");
                                printf("Email: ");
                                fgets(c[compteur].mail, sizeof(c[compteur].mail), stdin);
                                strtok(c[compteur].mail, "\n");
                                compteur++;
                            }
                            if (compteur >= 100) {
                                printf("/_\\ Memory is full !!\n");
                            }
                            break;
                        }
                        case 3:
                            break; // Back
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
                    system("cls");
                    printf("============== Display Menu ==============\n");
                    printf("1- Simple display\n");
                    printf("2- Display in ascending order\n");
                    printf("3- Display in descending order\n");
                    printf("4- Back\n");
                    printf("Enter your choice: ");
                    scanf("%d", &display_choice);
                    getchar(); // clear leftover newline

                    switch (display_choice) {
                        case 1: {
                            if (compteur == 0) {
                                printf("No contact to display.\n");
                            } else {
                                printf("========= Contact List =========\n");
                                printf("| %-25s | %-15s | %-30s |\n", "Name", "Phone", "Email");
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                                for (int i = 0; i < compteur; i++) {
                                    printf("| %-25s | %-15s | %-30s |\n", c[i].name, c[i].tele, c[i].mail);
                                }
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                            }
                            system("pause");
                            break;
                        }
                        case 2:{
                            if(compteur ==0){
                                printf("No contact to display.\n");
                            }else{   
                                // Copy array list
                                for(int i = 0; i <compteur; i++){
                                    swap[i] = c[i];
                                }
                                // sort contacts
                                for (int i = 0; i < compteur - 1; i++) {
                                    for (int j = i + 1; j < compteur; j++) {
                                        if (strcmp(swap[i].name, swap[j].name) > 0) {
                                            Contact temp = swap[i];
                                            swap[i] = swap[j];
                                            swap[j] = temp;
                                        }
                                    }
                                }
                                // display after sort
                                printf("========= Contact List =========\n");
                                printf("| %-25s | %-15s | %-30s |\n", "Name", "Phone", "Email");
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                                for (int i = 0; i < compteur; i++) {
                                    printf("| %-25s | %-15s | %-30s |\n", swap[i].name, swap[i].tele, swap[i].mail);
                                }
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                            }
                            system("pause");
                            break;
                        }
                        case 3: {
                            if(compteur == 0){
                                printf("No contact to display.\n");
                            }else{
                                // Copy array list
                                for(int i = 0; i <compteur; i++){
                                    swap[i] = c[i];
                                }
                                // sort contacts
                                for (int i = 0; i < compteur - 1; i++) {
                                    for (int j = i + 1; j < compteur; j++) {
                                        if (strcmp(swap[i].name, swap[j].name) < 0) {
                                            Contact temp = swap[i];
                                            swap[i] = swap[j];
                                            swap[j] = temp;
                                        }
                                    }
                                }
                                // display after sort
                                printf("========= Contact List =========\n");
                                printf("| %-25s | %-15s | %-30s |\n", "Name", "Phone", "Email");
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                                for (int i = 0; i < compteur; i++) {
                                    printf("| %-25s | %-15s | %-30s |\n", swap[i].name, swap[i].tele, swap[i].mail);
                                }
                                printf("+---------------------------+-----------------+-------------------------------+\n");
                            }
                            system("pause");
                            break;
                        }
                        case 4:
                            break; // Back
                        default:
                            printf("Invalid choice!\n");
                            break;
                    }
                } while (display_choice != 4);
                break;
            }
            case 3: {
                printf("========= Edit Contact =========\n");
                char nom[50];
                printf("Enter the name of the contact to edit: ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].name, nom) == 0) {
                        found = 1;
                        printf("New name: ");
                        fgets(c[i].name, sizeof(c[i].name), stdin);
                        strtok(c[i].name, "\n");
                        printf("New phone: ");
                        fgets(c[i].tele, sizeof(c[i].tele), stdin);
                        strtok(c[i].tele, "\n");
                        printf("New email: ");
                        fgets(c[i].mail, sizeof(c[i].mail), stdin);
                        strtok(c[i].mail, "\n");
                        printf("Contact updated successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 4: {
                printf("========= Delete Contact =========\n");
                char nom[50];
                printf("Enter the name of the contact to delete: ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].name, nom) == 0) {
                        found = 1;
                        for (int j = i; j < compteur - 1; j++) {
                            c[j] = c[j + 1];
                        }
                        compteur--;
                        printf("Contact deleted successfully.\n");
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 5: {
                printf("========= Search Contact =========\n");
                char nom[50];
                printf("Enter the name of the contact to search: ");
                fgets(nom, sizeof(nom), stdin);
                strtok(nom, "\n");

                int found = 0;
                for (int i = 0; i < compteur; i++) {
                    if (strcmp(c[i].name, nom) == 0) {
                        found = 1;
                        printf("Contact found:\n");
                        printf("Name: %s\n", c[i].name);
                        printf("Phone: %s\n", c[i].tele);
                        printf("Email: %s\n", c[i].mail);
                        break;
                    }
                }
                if (!found) {
                    printf("Contact not found.\n");
                }
                break;
            }
            case 6: {
                printf("Total number of contacts: %d\n", compteur);
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
    } while (choix != 7);

    return 0;
}
