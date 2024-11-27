
/******************
Name: Gilad Bergfroind
ID: 331749978
Assignment: ex2
*******************/

#include <stdio.h>
int main() {
	char ss;
	int selection, i = 1;
// Case 1: Draw Happy Face with given symbols for eyes, nose and mouse
/* Example:
* n = 3:
* 0   0
*   o
* \___/
*/

	while(i == 1)
	{
		printf("Choose an option:\n     1. Happy Face\n     2. Balanced Nmber\n     3. Generous Number\n     4. Circle Of Joy\n     5. Happy Numbers\n     6. Festival Of Laughter\n     7. Exit\n");
		selection = -1;
		scanf("%d", &selection);
		switch(selection) {
		case 1:
		{
			printf("Enter symbols for the eyes, nose and mouth:\n");
			char eyes, nose, mouth;
			scanf(" %c %c %c", &eyes, &nose, &mouth);
			printf("Enter face size:\n");
			int size;
			while(scanf("%d", &size) && (size < 1 || size % 2 == 0))
			{
				printf("The face's size must be an odd and positive number, please try again:\n");
			}
			printf("%c", eyes);
			for(int i = 0; i < size; i++)
				printf(" ");
			printf("%c\n", eyes);
			for(int i = 0; i < size / 2 + 1; i++)
				printf(" ");
			printf("%c\n", nose);
			printf("\\");
			for(int i = 0; i < size; i++)
				printf("%c", mouth);
			printf("/\n");
			break;
		}
// Case 2: determine whether the sum of all digits to the left of the middle digit(s)
// and the sum of all digits to the right of the middle digit(s) are equal
/* Examples:
Balanced: 1533, 450810, 99
Not blanced: 1552, 34
Please notice: the number has to be bigger than 0.
*/

		case 2:
		{
			int oldNum, newNum,singles = 0, positive = 0;
			printf("Enter a number:\n");
			scanf("%d", &oldNum);
			int numOfDigits;
			newNum = oldNum;
			while(positive == 0)
			{
				if(newNum < 0)
				{
					printf("Only positive number is allowed, please try again:\n");
					printf("Enter a number\n");
					scanf("%d", &newNum);
				}
				else
				{
					positive = 1;
					while(oldNum > 0)
					{
						oldNum = oldNum / 10;
						numOfDigits++;
					}
					int sumLeft = 0, sumRight = 0;
					if(numOfDigits % 2 > 0)
					{
						for(int i = numOfDigits; i > (numOfDigits / 2); i--)
						{
							sumRight = sumRight + (newNum % 10);
							singles = newNum % 10;
							newNum = newNum / 10;
						}
						newNum = (newNum * 10) + singles;
						numOfDigits = (numOfDigits / 2) + 1;
						for(int i = numOfDigits ; i > 0; i--)
						{
							sumLeft = sumLeft + (newNum % 10);
							newNum = newNum / 10;
						}
					}
					else
					{
						for(int i = numOfDigits; i > (numOfDigits / 2); i--)
						{
							sumRight = sumRight + (newNum % 10);
							singles = newNum % 10;
							newNum = newNum / 10;
						}
						for(int i = numOfDigits / 2; i > 0; i--)
						{
							sumLeft = sumLeft + (newNum % 10);
							newNum = newNum / 10;
						}
					}
					if(sumLeft == sumRight)
						printf("This number is balanced and brings harmony!");
					else
						printf("This number isn't balanced and destroys harmony.");
				}
			}
			break;
		}
// Case 3: determine whether the sum of the proper divisors (od an integer) is greater than the number itself
/* Examples:
Abudant: 12, 20, 24
Not Abudant: 3, 7, 10
Please notice: the number has to be bigger than 0.
*/
		case 3:
			{
			printf("Enter a number:\n");
			int num,divider,sumOfDividers = 0;
			while(scanf("%d",&num) && num < 1)
			printf("Only positive number is allowed, please try again:\n");
			for(divider = 1; divider < num; divider++)
			{
			    if(num % divider == 0)
			    sumOfDividers = sumOfDividers + divider;
			}
			if (sumOfDividers > num)
			printf("This number is generous!\n");
			else
			printf("This number does not share.\n");
			break;
			}
// Case 4: determine wether a number is a prime.
/* Examples:
This one brings joy: 3, 5, 11
This one does not bring joy: 15, 8, 99
Please notice: the number has to be bigger than 0.
*/
		case 4:
		{
			int happyNumber = 0;
			int counter = 0;
			printf("Enter a number\n");
			scanf("%d", &happyNumber);
			int reversedNum = 0, oldNum = happyNumber, c = 1;
			while(oldNum > 0)
			{
				reversedNum = reversedNum * 10;
				reversedNum = oldNum % 10 + reversedNum;
				oldNum = oldNum / 10;
			}
			while(c == 1)
			{
				if(happyNumber > 0)
				{
					c = 0;
					for(int divider = 2; divider < happyNumber; divider++)
					{
						int primeReversed = reversedNum % divider;
						int prime = happyNumber % divider;
						if(prime == 0 || primeReversed == 0)
						{
							printf("The circle remains incomplete.\n");
							break;
						}
						else
							counter++;
					}
					if(counter == happyNumber - 2)
						printf("This number completes the circle of joy!\n");
				}
				else
				{
					printf("Only positive number is allowed, please try again:\n");
					printf("Enter a number\n");
					scanf("%d", &happyNumber);
				}
			}
			break;
		}
// Happy numbers: Print all the happy numbers between 1 to the given number.
// Happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
/* Examples:
Happy :) : 7, 10
Not Happy :( : 5, 9
Please notice: the number has to be bigger than 0.
*/
		case 5:
			{
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
			}
// Festival of Laughter: Prints all the numbers between 1 the given number:
// and replace with "Smile!" every number that divided by the given smile number
// and replace with "Cheer!" every number that divided by the given cheer number
// and replace with "Festival!" every number that divided by both of them
/* Example:
6, smile: 2, cheer: 3 : 1, Smile!, Cheer!, Smile!, 5, Festival!
*/
		case 6:
		{
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
		}
		case 7:
			printf("Thank you for your journey through Numeria!\n");
			i = 0;
			break;
		default:
			printf("BG --- This option is not available, please try again.");
			break;
		}
	}
	return 0;
}
