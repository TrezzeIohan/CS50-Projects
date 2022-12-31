#include <cs50.h>
#include <stdio.h>
#include <math.h> //this library is used to simplify the search for the first and second digits

//  PSEUDOCODE
//
// 1. Get an integer from an imput
// 2. Calculate the Luhn's Algorithm
// 3. Calculate card length
// 4. Find the first and second digits
// 5. Print the corresponding Card or INVALID



int main(void)
{

    //get a card number
    long long card_number;

    do {
        card_number = get_long_long("Tell us your card number: ");
    }
    while (card_number < 1);

    //declaring the variables for the algorithm solution
    int digit, digit_1, digit_2, digit1, digit1_1, digit1_2;
    int sum = 0;
    int sum_1 = 0;
    int sum_total;
    int sum_lastdigit;
    int first2digits;
    int firstdigits;



    //Algorithm for the first group
    long long credit_num1 = card_number / 10;

    while (credit_num1 > 0){
        digit = credit_num1 % 10;
        credit_num1 /= 100;
        digit = digit * 2;

        if (digit > 9){
            digit_1 = digit % 10;
            digit /= 10;
            digit_2 = digit % 10;
            digit = digit_1 + digit_2;
        }

        sum = sum + digit;
    }

    //Algo for the second group
    long long credit_num2 = card_number;

    while (credit_num2 > 0){

        digit1 = credit_num2 % 10;
        credit_num2 /= 100;

        if (digit1 > 9){

            digit1_1 = digit1 % 10;
            digit1 /= 10;
            digit1_2 = digit1 % 10;
            digit1 = digit1_1 + digit1_2;
        }
        sum_1 = sum_1 + digit1;
    }


    //ending the algorithm
    sum_total = sum + sum_1;
    sum_lastdigit = sum_total % 10;


    //checking card length
    long long creditdigit = card_number;
    int digit_length = 0;
    while (creditdigit != 0)
    {

        creditdigit /= 10;
        digit_length++;
    }



    //checking the starting first and second digits
    first2digits = card_number / pow(10, digit_length - 2);
    firstdigits = card_number / pow(10, digit_length - 1);



    //Print the corresponding results
    if (sum_lastdigit == 0 && digit_length == 15 && (first2digits == 34 || first2digits == 37))
    {
        printf("AMEX\n");
    }
    else if (sum_lastdigit == 0 && digit_length == 16 && (first2digits == 51 || first2digits == 52 || first2digits == 53
        || first2digits == 54 || first2digits == 55))
        {
            printf("MASTERCARD\n");
        }
    else if (sum_lastdigit == 0 && (digit_length == 13 || digit_length == 16) && firstdigits == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}