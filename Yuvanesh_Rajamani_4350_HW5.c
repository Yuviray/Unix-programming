// NAME :Yuvanesh Rajamani
//CS 4350 – Unix Systems Programming
//Section Number: 251
//Serial Number: 9
//Assignment Number: 5
//Due Date: 3 / 29 / 2023
#include <stdio.h>

int prime(int number);
void squarePrime(int input);
int main() {
    int loop1 = 0; // initialization for loop that repeats program 0=repeat, 1=stop
    printf("Mathematics and Computer Programming\n");
    printf("\nPrime number is a number that is divisible by itself and one only such as\n"
           "2, 3, 5, 7, 11, 13 ...\n");
    printf("\nSquare numbers are certain pairs of numbers when added together\n"
           "give a square number and when subtracted also give a square number.\n"
           "This program displays all the pairs of numbers.\n");
    // program starts the math portion
    while (loop1 == 0){
        int input; // user input
        printf("\nEnter A Positive Integer ---- >  ");
        scanf("%d", &input);
        if(input >0 && input <= 1000){
            int k = 0;
            k = prime(input);
            if (k==0)
                printf("\n%d  is not prime \n", input);
            else
                printf("\n%d  is prime \n", input);
            squarePrime(input);
        }
        else if(input>1000)
            printf("\nInvalid Number, Number must be between 1 and 1000");
        else
            printf("\nInvalid Number, Number must be positive");
        // loop that asks to continue
        int loop2 = 0 ; // this is the 2nd loop to check repeat 0=ask again, 1=stop asking
        while (loop2 == 0){
            char repeat;
            printf("\nWould you like repeat the process for another number?  ");
            scanf(" %c",&repeat);
            if(repeat == 'Y' || repeat == 'y')
                loop2++;
            else if(repeat == 'N' || repeat == 'n'){
                loop2++;
                loop1++;
            }
            else
                printf("invalid choice, Must enter Y, y or N , n\n" );
        }
    }
    printf("\nMathetics and Computer Programming\nPrepared by Yuvanesh Rajamani\n"
           "3 - 29- 2023");
}
int prime(int number) {
    if (number <= 1) return 0;
    int i=2;
    for (i; i<number; i++) {
        if (number % i == 0 && i != number) return 0;
    }return 1;
}

void squarePrime(int input){
    printf("\nThe square pair numbers are:-");
    printf("\n   N    P    N+P    P-N");
    printf("\n-----------------------");
    int iVar1,iVar2; // iVar1 holds the sqrt of n+p, iVar2 holds the sqrt of p-n
    float fVar1,fVar2; // fvar1 holds the float of iVar1,fVar2 hold the float of iVar2
    int add,sub; // add = p+n, sub = p-n
    int i = 1;
    for(i ;i<=input;i++){
        int n=1;
        for(n; n<i; n++){
            add = n +i;
            sub = i-n;
            float temp, sqrt, temp2, sqrt2;  // variables to help calculate sqrt for add and sub
            sqrt = add / 2;
            sqrt2 = sub / 2;
            temp = 0;
            temp2 = 0;
            while(sqrt != temp){ // calculates sqrt for add
                temp = sqrt;
                sqrt = ( add/temp + temp) / 2;
            }
            while(sqrt2 != temp2){ // calculates sqrt for sub
                temp2 = sqrt2;
                sqrt2 = ( sub/temp2 + temp2) / 2;
            }
            fVar1=sqrt;
            iVar1=fVar1; // checks if add is a square pair
            fVar2=sqrt2;
            iVar2=fVar2; // checks is sub is a square pair
            if(iVar1==fVar1 && iVar2 == fVar2)
                printf("\n   %2d    %2d   %2d   %2d",n,i,add,sub);
        }
    }
}
