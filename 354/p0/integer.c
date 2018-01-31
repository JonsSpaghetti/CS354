#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int convertToHex(int num){
    if (num >= 10){
        return num += 7; //Add 7 to prepare to convert to ASCII value.
    }
    else{
        return num;
    }
}

int convertToBase(int num, int base){
    int remainder, divResult;
    divResult = num / base;
    remainder = num % base; 
    if (divResult > 0){
        return remainder + 10 * convertToBase(divResult, base);
    }
    else{
        return (remainder);
    }
}

int isPrime(int num){
    int squareRoot = sqrt(num);
    for (squareRoot; squareRoot > 0; squareRoot --){
        if (num % squareRoot == 0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int input;
    //call convert to base for hex/oct (base 16/8)
    printf("Enter an integer between 1 to 100 (1 and 100 excluded): \n");
    scanf("%d", &input);
    if (input <= 1 || input >= 100){
        printf("not in range");
        return 1;
    }
    else {
        
        //hexadecimal output
        //printf("0x%d\n", convertToHex(input)); //where convertToHex uses convertToBase but handles > 9;
        printf("%#x\n", input);

        //octal output
        //printf("0%d\n", convertToBase(input, 8));
        printf("%#o\n", input);

        //prime output
        if (isPrime(input)){
            printf("composite\n");
        }
        else{
            printf("prime\n");
        }
        
        return 0;
    }
}
