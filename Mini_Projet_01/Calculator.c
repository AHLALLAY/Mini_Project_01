#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void head() {
    system("cls");
    system("color 0c");
    printf("/================================= Calculator ================================\\\n");
    printf("|                                                                             |\n");
    printf("|  1- Addition : Add two or more numbers.                                     |\n");
    printf("|  2- Subtraction : Subtract two numbers.                                     |\n");
    printf("|  3- Multiplication : Multiply two or more numbers.                          |\n");
    printf("|  4- Division : Divide two numbers.                                          |\n");
    printf("|  5- Average : Compute the average of a list of numbers.                     |\n");
    printf("|  6- Absolute value : Compute the absolute value of a number.                |\n");
    printf("|  7- Exponentiation : Raise a number to a given power.                       |\n");
    printf("|  8- Square root : Compute the square root of a positive number.             |\n");
    printf("|  0- Exit                                                                    |\n");
    printf("\\=============================================================================/\n");
}

int main() {
    int choix, x, base, puissance, a, b;
    char answer = 'y';

    while (answer == 'y') {
        head();
        printf("\n\tEnter the number of your choice: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: // Addition
                printf("How many numbers do you have? ");
                scanf("%d", &x);
                int sum = 0;
                for (int i = 0; i < x; i++) {
                    printf("Number %d: ", i + 1);
                    scanf("%d", &a);
                    sum += a;
                }
                printf("The sum is %d\n", sum);
                break;

            case 2: // Subtraction
                printf("First number: ");
                scanf("%d", &a);
                printf("Second number: ");
                scanf("%d", &b);
                printf("The subtraction is %d\n", a - b);
                break;

            case 3: // Multiplication
                printf("How many numbers do you have? ");
                scanf("%d", &x);
                int product = 1;
                for (int i = 0; i < x; i++) {
                    printf("Number %d: ", i + 1);
                    scanf("%d", &a);
                    product *= a;
                }
                printf("The product is %d\n", product);
                break;

            case 4: // Division
                printf("First number: ");
                scanf("%d", &a);
                printf("Second number: ");
                scanf("%d", &b);
                if (b != 0) {
                    printf("The division is %d\n", a / b);
                } else {
                    printf("ERROR: Check the denominator!\n");
                }
                break;

            case 5: // Average
                printf("How many numbers do you have? ");
                scanf("%d", &x);
                sum = 0;
                for (int i = 0; i < x; i++) {
                    printf("Number %d: ", i + 1);
                    scanf("%d", &a);
                    sum += a;
                }
                printf("The average is %.2f\n", (float)sum / x);
                break;

            case 6: // Absolute value
                printf("Enter a number: ");
                scanf("%d", &a);
                printf("The absolute value of %d is %d\n", a, abs(a));
                break;

            case 7: // Exponentiation
                printf("Enter the base: ");
                scanf("%d", &base);
                printf("Enter the exponent: ");
                scanf("%d", &puissance);
                int result = 1;
                for (int i = 0; i < puissance; i++) {
                    result *= base;
                }
                printf("%d to the power of %d is %d\n", base, puissance, result);
                break;

            case 8: // Square root
                printf("Enter a positive number: ");
                scanf("%d", &a);
                if (a >= 0) {
                    printf("The square root of %d is %.2f\n", a, sqrt(a));
                } else {
                    printf("ERROR: You must enter a positive number!\n");
                }
                break;

            case 0: // Exit
                printf("Goodbye!\n");
                exit(0);
                break;

            default:
                printf("The value you entered is not in the menu.\n");
                break;
        }

        printf("Do you want to continue? (y/n) ");
        scanf(" %c", &answer);
    }

    return 0;
}
