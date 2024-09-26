#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void head() {
    system("cls");
    system("color 0c");
    printf("/================================= Calculatrice =================================\\\n");
    printf("|                                                                               |\n");
    printf("|  1- Addition : Ajouter deux ou plusieurs nombres.                             |\n");
    printf("|  2- Soustraction : Soustraire deux nombres.                                   |\n");
    printf("|  3- Multiplication : Multiplier deux ou plusieurs nombres.                    |\n");
    printf("|  4- Division : Diviser deux nombres.                                          |\n");
    printf("|  5- Moyenne : Calculer la moyenne d'une série de nombres.                     |\n");
    printf("|  6- Valeur absolue : Calculer la valeur absolue d'un nombre.                  |\n");
    printf("|  7- Exponentiation : Calculer un nombre à une certaine puissance.             |\n");
    printf("|  8- Racine carrée : Calculer la racine carrée d'un nombre positif.            |\n");
    printf("|  0- Quitter                                                                   | \n");
    printf("\\===============================================================================/\n");
}

int main() {
    int choix, x, base, puissance, a, b;
    char answer = 'y';

    while (answer == 'y') {
        head();
        printf("\n\tTapez le numéro de votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Addition
                printf("Combien de nombres avez-vous ? ");
                scanf("%d", &x);
                int sum = 0;
                for (int i = 0; i < x; i++) {
                    printf("%dème nombre : ", i + 1);
                    scanf("%d", &a);
                    sum += a;
                }
                printf("La somme est %d\n", sum);
                break;

            case 2: // Soustraction
                printf("1er nombre : ");
                scanf("%d", &a);
                printf("2ème nombre : ");
                scanf("%d", &b);
                printf("La soustraction est %d\n", a - b);
                break;

            case 3: // Multiplication
                printf("Combien de nombres avez-vous ? ");
                scanf("%d", &x);
                int product = 1;
                for (int i = 0; i < x; i++) {
                    printf("%dème nombre : ", i + 1);
                    scanf("%d", &a);
                    product *= a;
                }
                printf("Le produit est %d\n", product);
                break;

            case 4: // Division
                printf("1er nombre : ");
                scanf("%d", &a);
                printf("2ème nombre : ");
                scanf("%d", &b);
                if (b != 0) {
                    printf("La division est %d\n", a / b);
                } else {
                    printf("ERROR ===> Vérifiez le dénominateur !\n");
                }
                break;

            case 5: // Moyenne
                printf("Combien de nombres avez-vous ? ");
                scanf("%d", &x);
                sum = 0;
                for (int i = 0; i < x; i++) {
                    printf("%dème nombre : ", i + 1);
                    scanf("%d", &a);
                    sum += a;
                }
                printf("La moyenne est %.2f\n", (float)sum / x);
                break;

            case 6: // Valeur absolue
                printf("Tapez un nombre : ");
                scanf("%d", &a);
                printf("La valeur absolue de %d est %d\n", a, abs(a));
                break;

            case 7: // Exponentiation
                printf("Tapez la base : ");
                scanf("%d", &base);
                printf("Tapez l'exposant : ");
                scanf("%d", &puissance);
                int result = 1;
                for (int i = 0; i < puissance; i++) {
                    result *= base;
                }
                printf("L'exponentiation de %d à la puissance %d est %d\n", base, puissance, result);
                break;

            case 8: // Racine carrée
                printf("Tapez un nombre positif : ");
                scanf("%d", &a);
                if (a >= 0) {
                    printf("La racine carrée de %d est %.2f\n", a, sqrt(a));
                } else {
                    printf("ERROR ===> Vous devez saisir un nombre positif !\n");
                }
                break;

            case 0: // Quitter
                printf("À bientôt !\n");
                exit(0);
                break;

            default:
                printf("La valeur que vous avez saisie n'est pas dans le menu.\n");
                break;
        }

        printf("Voulez-vous continuer ? (y/n) ");
        scanf(" %c", &answer);
    }

    return 0;
}
