#include <stdio.h>

int colatz (int n steps);

int main (void)
{
    int number;
    int steps = 0;

    printf("Enter an integer: ");
    scanf("%i", &number);


    colatz(number steps);
    printf("It took '%i' %i steps to get to 1.\n", number, steps);
    return 0;
}

int colatz (int n steps){
    int *stepsT;
    //base cases
    if (n == 1)
    {
        return 0;
    }

    //even cases
    else if ((n % 2) == 0){
        return 1 + (colatz(n/2));
        stepsT++;
    }

    //odd cases
    else
    {
        return 1 + colatz(3*n + 1);
        stepsT++;
    }
}