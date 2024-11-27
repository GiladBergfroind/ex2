
/******************
Name: Gilad Bergfroind
ID: 331749978
Assignment: ex2
*******************/

#include <stdio.h>
int main() {
    int exit = 0;
    while (!exit) {
        printf(
            "Choose an option:\n\t1. Happy Face\n\t2. Balanced Number\n\t3. Generous Number\n\t4. Circle Of Joy\n\t5. "
            "Happy Numbers\n\t6. Festival Of Laughter\n\t7. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            // Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
            /* Example:
            * n = 3:
            * 0   0
            *   o
            * \___/
            */
            case 1:
                printf("Enter symbols for the eyes, nose, and mouth:\n");
                char eye, nose, mouth;
                scanf(" %c %c %c", &eye, &nose, &mouth);
                printf("Enter face size:\n");
                int size;

            //asking the user for the size of the smile and continuing only if positive and even
                while (scanf("%d", &size) && (size < 1 || size % 2 == 0)) {
                    printf("The face's size must be an odd and positive number, please try again:\n");
                }
                printf("%c", eye);
                for (int i = 0; i < size; i++) {
                    printf(" ");
                }
                printf("%c\n", eye);
                for (int i = 0; i < size / 2 + 1; i++) {
                    printf(" ");
                }
                printf("%c\n", nose);
                printf("\\");
                for (int i = 0; i < size; i++) {
                    printf("%c", mouth);
                }
                printf("/\n");
                break;
            // Case 2: determine whether the sum of all digits to the left of the middle digit(s)
            // and the sum of all digits to the right of the middle digit(s) are equal
            /* Examples:
            Balanced: 1533, 450810, 99
            Not blanced: 1552, 34
            Please notice: the number has to be bigger than 0.
            */
            case 2:
                int num, rightSum = 0, leftSum = 0, digitCounter = 0;
                printf("Enter a number:\n");
                while (scanf("%d", &num) && num < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                }
                int temp = num;
            //counting the amount of digits in the number
                while (temp > 0) {
                    digitCounter++;
                    temp /= 10;
                }
                for (int i = 0; i < digitCounter / 2; i++) {
                    rightSum += num % 10;
                    num /= 10;
                }
            //getting rid of the number in the middle if the amount of digits is odd
                if (digitCounter % 2 == 1) num /= 10;
                for (int i = 0; i < digitCounter / 2; i++) {
                    leftSum += num % 10;
                    num /= 10;
                }
                if (rightSum == leftSum) {
                    printf("This number is balanced and brings harmony!\n");
                } else {
                    printf("This number isn't balanced and destroys harmony.\n");
                }
                break;
            // Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
            /* Examples:
            Abudant: 12, 20, 24
            Not Abudant: 3, 7, 10
            Please notice: the number has to be bigger than 0.
            */
            case 3:
                printf("Enter a number:\n");
                int number, sum = 0;
                while (scanf("%d", &number) && number < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                }
                for (int i = 1; i < number / 2 + 1; i++) {
                    if (number % i == 0) sum += i;
                }
                if (sum > number) printf("This number is generous!\n");
                else printf("This number does not share.\n");
                break;
            // Case 4: determine wether a number is a prime.
            /* Examples:
            This one brings joy: 3, 5, 11
            This one does not bring joy: 15, 8, 99
            Please notice: the number has to be bigger than 0.
            */
            case 4:
                printf("Enter a number:\n");
                int num1, flippedNum = 0, isPrime = 1;
                while (scanf("%d", &num1) && num1 < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                }
                int temp0 = num1;
                while (temp0 != 0) {
                    flippedNum *= 10;
                    flippedNum += temp0 % 10;
                    temp0 /= 10;
                }
                if (num1 > 1) {
                    for (int i = 2; i < num1; i++) {
                        if (num1 % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                } else isPrime = 0;
                if (isPrime) {
                    for (int i = 2; i < num1; i++) {
                        if (flippedNum % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                }
                if (isPrime)printf("This number completes the circle of joy!\n");
                else printf("The circle remains incomplete.\n");
                break;
            // Happy numbers: Print all the happy numbers between 1 to the given number.
            // Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
            /* Examples:
            Happy :) : 7, 10
            Not Happy :( : 5, 9
            Please notice: the number has to be bigger than 0.
            */
            case 5:
                printf("Enter a number:\n");
                int num2;
                while (scanf(" %d", &num2) && num2 < 1) {
                    printf("Only positive number is allowed, please try again:\n");
                }
                printf("Between 1 and %d only these numbers bring happiness: ", num2);
                for (int i = 1; i <= num2; i++) {
                    int temp1 = i;
                    int squareDigitSum = 0;
                    //the only 2 outcomes are squareDigitSum = 1 and 4
                    while (squareDigitSum != 1 && squareDigitSum != 4) {
                        squareDigitSum = 0;
                        while (temp1 != 0) {
                            int digit = temp1 % 10;
                            squareDigitSum += digit * digit;
                            temp1 /= 10;
                        }
                        temp1 = squareDigitSum;
                    }
                    if (squareDigitSum == 1) printf("%d ", i);
                }
                printf("\n");
                break;
            // Festival of Laughter: Prints all the numbers between 1 the given number:
            // and replace with "Smile!" every number that divided by the given smile number
            // and replace with "Cheer!" every number that divided by the given cheer number
            // and replace with "Festival!" every number that divided by both of them
            /* Example:
            6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
            */
            case 6:
                printf("Enter a smile and cheer number:\n");
                int smile, cheer, max;
                while (scanf(" smile:%d, cheer:%d", &smile, &cheer) != 2 || smile < 1 || cheer < 1 ||
                       smile == cheer) {
                    printf("Only 2 different positive numbers in the given format are allowed for "
                        "the festival, please try again:\n");
                    //clean the buffer
                    scanf("%*[^\n]");
                    scanf("%*c");
                }
                printf("Enter maximum number for the festival:\n");
                while (scanf("%d", &max) && max < 1) {
                    printf("Only positive maximum number is allowed, please try again:\n");
                }
                for (int i = 1; i <= max; i++) {
                    if (i % cheer == 0 && i % smile == 0) printf("Festival!\n");
                    else if (i % cheer == 0) printf("Cheer!\n");
                    else if (i % smile == 0) printf("Smile!\n");
                    else printf("%d\n", i);
                }
                break;
            case 7:
                printf("Thank you for your journey through Numeria!");
                exit = 1;
                break;
            default:
                printf("This option is not available, please try again.\n");
                break;
        }
    }

    return 0;
}
