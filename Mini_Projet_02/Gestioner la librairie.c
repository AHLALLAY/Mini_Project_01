#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char titre[100][100], auteur[100][100]; // Adjusted for storing multiple titles and authors
    float prix[100];
    int Quantite[100];
    int livre = 0, n;
    int choix;

    do {
        system("cls");
        system("color 09");
        printf("/============= Gestioner la librairie =============\\\n");
        printf("|1- Ajouter un livre au stock.                     |\n");
        printf("|2- Afficher tous les livres disponibles.          |\n");
        printf("|3- Rechercher un livre par son titre.             |\n");
        printf("|4- Mettre à jour la quantité d'un livre.          |\n");
        printf("|5- Supprimer un livre du stock.                   |\n");
        printf("|6- Afficher le nombre total de livres en stock.   |\n");
        printf("|7- Exit.                                          |\n");
        printf("\\==================================================/\n");
        printf("Votre choix: ");
        scanf("%d", &choix);
        getchar();
        switch (choix) {
            case 1:
                printf("======== Ajouter un Livre au Stock ========\n");
                printf("Combien de livre tu veux taper : ");
                scanf("%d",&n);
                getchar();
                for(int i=0;i<n;i++){
                    printf("Taper le titre : ");
                    fgets(titre[livre], sizeof(titre[livre]), stdin); //scanf ne marche avec les titres contient des espaces ==> solution fgets
                    titre[livre][strcspn(titre[livre], "\n")] = 0; // \n
                    printf("Taper l'auteur : ");
                    fgets(auteur[livre], sizeof(auteur[livre]), stdin);
                    auteur[livre][strcspn(auteur[livre], "\n")] = 0; // annuler \n

                    printf("Taper la quantité : ");
                    scanf("%d", &Quantite[livre]);
                    getchar();
                    printf("Taper le Prix : ");
                    scanf("%f", &prix[livre]);
                    getchar();
                    livre++;
                    printf("------------------------\n");
                }
                break;

            case 2:
                if (livre != 0) {
                    for (int i = 0; i < livre; i++) {
                        printf("Livre %d:\n", i + 1);
                        printf("Titre: %s\n", titre[i]);
                        printf("Auteur: %s\n", auteur[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantité: %d\n", Quantite[i]);
                        printf("--------------------\n");
                    }
                    system("pause");
                } else {
                    printf("Pas de livre dans le stock.\n");
                }
                break;

            case 3: {
                char searchTitle[100];
                printf("Taper le titre de livre : ");
                fgets(searchTitle, sizeof(searchTitle), stdin);
                searchTitle[strcspn(searchTitle, "\n")] = 0; // annuler \n

                int exist = 0;
                for (int i = 0; i < livre; i++) {
                    if (strcmp(titre[i], searchTitle) == 0) {
                        printf("Livre trouvé:\n");
                        printf("Titre: %s\n", titre[i]);
                        printf("Auteur: %s\n", auteur[i]);
                        printf("Prix: %.2f\n", prix[i]);
                        printf("Quantité: %d\n", Quantite[i]);
                        exist = 1;
                        break;
                    }
                    system("pause");
                }
                if (!exist) {
                    printf("Le livre n'existe pas.\n");
                    system("pause");
                }
                break;
            }

            case 4: {
                char updateTitle[100];
                printf("Taper le titre : ");
                fgets(updateTitle, sizeof(updateTitle), stdin);
                updateTitle[strcspn(updateTitle, "\n")] = 0; // annuler \n
                int a_jour = 0;
                for (int i = 0; i < livre; i++) {
                    if (strcmp(titre[i], updateTitle) == 0) {
                        printf("Nouvelle quantité: ");
                        scanf("%d", &Quantite[i]);
                        printf("La quantité a été mise à jour!\n");
                        a_jour = 1;
                        break;
                    }
                    system("pause");
                }
                if (!a_jour) {
                    printf("Le livre n'existe pas.\n");
                    system("pause");
                }
                break;
            }

            case 5: {
                char deleteTitle[100];
                printf("Taper le titre : ");
                fgets(deleteTitle, sizeof(deleteTitle), stdin);
                deleteTitle[strcspn(deleteTitle, "\n")] = 0; // annuler \n
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
                        printf("Le livre a été supprimé!\n");
                        deleted = 1;
                        break;
                    }
                    system("pause");
                }
                if (!deleted) {
                    printf("Le livre n'existe pas.\n");
                    system("pause");
                }
                break;
            }

            case 6: {
                int total = 0;
                for (int i = 0; i < livre; i++) {
                    total += Quantite[i];
                }
                printf("Total de livres en stock: %d\n", total);
                system("pause");
                break;
            }

            case 7:
                printf("Au revoir!\n");
                break;

            default:
                printf("Votre choix n'est pas inclus dans le menu 0_0 !!\n");
        }
    } while (choix != 7);

    return 0;
}
