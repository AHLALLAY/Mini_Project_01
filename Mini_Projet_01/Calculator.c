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

void addition(){
    int x;
    float a, sum = 0.0f;
    printf("How many numbers do you have? ");
    scanf("%d", &x);
    if(x<1){
        printf("Invalid number.\n");
        return;
    }
    for (int i = 0; i < x; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &a);
        sum += a;
    }
    printf("The sum is %.2f\n", sum);
}

void subtraction(){
    float a, b;
    printf("First number: ");
    scanf("%f", &a);
    printf("Second number: ");
    scanf("%f", &b);
    printf("The subtraction is %.2f\n", a - b);
}

void multiplication(){
    int x;
    float a = 0.0f, product = 1.0f;

    printf("How many numbers do you have? ");
    scanf("%d", &x);
    if(x<1){
        printf("Invalid number.\n");
        return;
    }
    for (int i = 0; i < x; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &a);
        product *= a;
    }
    printf("The product is %.2f\n", product);
}

void division(){
    float a, b;
    printf("First number: ");
    scanf("%f", &a);
    printf("Second number: ");
    scanf("%f", &b);
    if (b != 0) {
        printf("The division is %.2f\n", a / b);
    } else {
        printf("ERROR: Check the denominator!\n");
    }
}

void average(){
    int x;
    float a, sum = 0.0f;
    printf("How many numbers do you have? ");
    scanf("%d", &x);
    if(x<1){
        printf("Invalid number.\n");
        return;
    }
    for (int i = 0; i < x; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &a);
        sum += a;
    }
    printf("The average is %.2f\n", sum / x);
}

void absolute_value(){
    float a;
    printf("Enter a number: ");
    scanf("%f", &a);
    printf("The absolute value of %f is %f\n", a, fabsf(a));
}

void exponentiation(){
    float base, puissance;

    printf("Enter the base: ");
    scanf("%f", &base);
    printf("Enter the exponent: ");
    scanf("%f", &puissance);
    printf("%.2f to the power of %.2f is %.2f\n", base, puissance, pow(base, puissance));
}

void square_root(){
    float a;
    printf("Enter a positive number: ");
    scanf("%f", &a);
    if (a >= 0) {
        printf("The square root of %f is %.2f\n", a, sqrt(a));
    } else {
        printf("ERROR: You must enter a positive number!\n");
    }
}

void close(){
    printf("Goodbye!\n");
}

int main() {
    int choix;
    do {
        head();
        printf("\n\tEnter the number of your choice: ");
        scanf("%d", &choix);
        switch (choix) {
            case 1: // Addition
                addition();
                break;
            case 2: // Subtraction
                subtraction();
                break;
            case 3: // Multiplication
                multiplication();
                break;
            case 4: // Division
                division();
                break;
            case 5: // Average
                average();
                break;
            case 6: // Absolute value
                absolute_value();
                break;
            case 7: // Exponentiation
                exponentiation();
                break;
            case 8: // Square root
                square_root();
                break;
            case 0: // Exit
                close();
                break;
            default:
                printf("The value you entered is not in the menu.\n");
                break;
        }
        if(choix !=0){
            system("pause");
        }
    }while(choix !=0);

    return 0;
}
