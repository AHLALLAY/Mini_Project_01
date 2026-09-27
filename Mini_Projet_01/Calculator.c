#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void show_menu() {
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

int ask_count(){
    int count;
    printf("How many numbers do you have? ");
    scanf("%d", &count);
    if(count<1){
        printf("Invalid number.\n");
        return -1;
    }
    return count;
}

void addition(){
    float number, sum = 0.0f;
    int how_many = ask_count();
    if(how_many<1){
        return;
    }
    for (int i = 0; i < how_many; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &number);
        sum += number;
    }
    printf("The sum is %.2f\n", sum);
}

void subtraction(){
    float first, second;
    printf("First number: ");
    scanf("%f", &first);
    printf("Second number: ");
    scanf("%f", &second);
    printf("The subtraction is %.2f\n", first - second);
}

void multiplication(){
    int how_many = ask_count();
    float number = 0.0f, product = 1.0f;
    if(how_many<1){
        return;
    }
    for (int i = 0; i < how_many; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &number);
        product *= number;
    }
    printf("The product is %.2f\n", product);
}

void division(){
    float first, second;
    printf("First number: ");
    scanf("%f", &first);
    printf("Second number: ");
    scanf("%f", &second);
    if (second != 0) {
        printf("The division is %.2f\n", first / second);
    } else {
        printf("ERROR: Check the denominator!\n");
    }
}

void average(){
    int how_many = ask_count();
    float number, sum = 0.0f;
    if(how_many<1){
        return;
    }
    for (int i = 0; i < how_many; i++) {
        printf("Number %d: ", i + 1);
        scanf("%f", &number);
        sum += number;
    }
    printf("The average is %.2f\n", sum / how_many);
}

void absolute_value(){
    float number;
    printf("Enter a number: ");
    scanf("%f", &number);
    printf("The absolute value of %f is %f\n", number, fabsf(number));
}

void exponentiation(){
    float base, exponent;

    printf("Enter the base: ");
    scanf("%f", &base);
    printf("Enter the exponent: ");
    scanf("%f", &exponent);
    printf("%.2f to the power of %.2f is %.2f\n", base, exponent, pow(base, exponent));
}

void square_root(){
    float number;
    printf("Enter a positive number: ");
    scanf("%f", &number);
    if (number >= 0) {
        printf("The square root of %f is %.2f\n", number, sqrt(number));
    } else {
        printf("ERROR: You must enter a positive number!\n");
    }
}

void show_goodbye(){
    printf("Goodbye!\n");
}

int main() {
    int choice;
    do {
        show_menu();
        printf("\n\tEnter the number of your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addition();
                break;
            case 2:
                subtraction();
                break;
            case 3:
                multiplication();
                break;
            case 4:
                division();
                break;
            case 5:
                average();
                break;
            case 6:
                absolute_value();
                break;
            case 7:
                exponentiation();
                break;
            case 8:
                square_root();
                break;
            case 0:
                show_goodbye();
                break;
            default:
                printf("The value you entered is not in the menu.\n");
                break;
        }
        if(choice !=0){
            system("pause");
        }
    }while(choice !=0);

    return 0;
}
