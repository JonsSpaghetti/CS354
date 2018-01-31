#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int isPrime(int num){
    int squareRoot = sqrt(num);
    for (squareRoot; squareRoot > 1; squareRoot --){
        if (num % squareRoot == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int input;
    printf("Enter an integer between 1 to 100 (1 and 100 excluded): \n");
    scanf("%d", &input);
    if (input <= 1 || input >= 100){
        printf("not in range\n");
        return 1;
    }
    else {
        
        //hexadecimal output
        printf("%#x\n", input);

        //octal output
        printf("%#o\n", input);

        //prime output
        if (isPrime(input)){
            printf("prime\n");
        }
        else{
            printf("composite\n");
        }
        
        return 0;
    }
}
