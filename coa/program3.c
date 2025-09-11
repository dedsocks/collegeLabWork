#include<stdio.h>
#include<conio.h>
#define  NUMBER_OF_BITS 4

void inputBinaryNumber(int* binaryNumber, int serialNumber){
    int i;
    printf("Enter binary number %d (%d bits signed) : ",serialNumber,NUMBER_OF_BITS);
    for(i = 0; i < NUMBER_OF_BITS; i++){
        scanf("%d", &binaryNumber[i]);
    }
}

void addBinaryNumbers(int* binaryNumber1, int* binaryNumber2){
    int i, carry = 0;
    int* finalNumber = binaryNumber1;
    for(i = NUMBER_OF_BITS-1; i >= 0; i--){
        finalNumber[i] = binaryNumber1[i] + binaryNumber2[i] + carry;
        if(finalNumber[i] >= 2){
            carry = 1;
        }
        else carry = 0;
        finalNumber[i] %= 2;
    }
}

void find1sComplement(int* binaryNumber){
    for(int i = 0; i < NUMBER_OF_BITS; i++){
        binaryNumber[i] = !binaryNumber[i];
    }
}

void find2sComplement(int* binaryNumber){
    int addToLsb[NUMBER_OF_BITS] = {0};
    addToLsb[NUMBER_OF_BITS - 1] = 1;
    find1sComplement(binaryNumber);
    addBinaryNumbers(binaryNumber, addToLsb);
}

void subtractBinaryNumbers(int* minuend, int* subtraend){
    find2sComplement(subtraend);
    addBinaryNumbers(minuend, subtraend);
}

int checkAdditionOverflow(int num1Sign, int num2Sign, int* result){
    int resultSign = result[0];
    if((num1Sign == 0 && num2Sign == 0 && resultSign == 1) ||
       (num1Sign == 1 && num2Sign == 1 && resultSign == 0)){
        return 1;
    }
    return 0;
}

int checkSubtractionOverflow(int minuendSign, int subtrahendSign, int* result){
    int resultSign = result[0];
    if((minuendSign == 0 && subtrahendSign == 1 && resultSign == 1) ||
       (minuendSign == 1 && subtrahendSign == 0 && resultSign == 0)){
        return 1;
    }
    return 0;
}

void displayBinaryNumber(int* binaryNumber, int numberOfBits){
    int i;
    for(i = 0; i < numberOfBits; i++){
        printf("%d ", binaryNumber[i]);
    }
}

void copyArray(int* source, int* destination, int size){
    for(int i = 0; i < size; i++){
        destination[i] = source[i];
    }
}

int main(){
    int num1Sign, num2Sign;
    int serialNumber = 1;
    int number1[NUMBER_OF_BITS], number2[NUMBER_OF_BITS];
    int copy1[NUMBER_OF_BITS], copy2[NUMBER_OF_BITS];
    
    printf("=== BINARY ARITHMETIC CALCULATOR ===\n\n");
    
    inputBinaryNumber(number1, serialNumber++);
    inputBinaryNumber(number2, serialNumber++);
    
    num1Sign = number1[0];
    num2Sign = number2[0];
    
    printf("\n=== RESULTS ===\n");
    
    printf("\nADDITION:\n");
    copyArray(number1, copy1, NUMBER_OF_BITS);
    copyArray(number2, copy2, NUMBER_OF_BITS);
    
    addBinaryNumbers(copy1, copy2);
    displayBinaryNumber(copy1, NUMBER_OF_BITS);
    
    if(checkAdditionOverflow(num1Sign, num2Sign, copy1)){
        printf("\nOVERFLOW OCCURRED in addition!\n");
    } else {
        printf("\nNo overflow detected in addition.\n");
    }

    printf("\nSUBTRACTION:\n");
    copyArray(number1, copy1, NUMBER_OF_BITS);
    copyArray(number2, copy2, NUMBER_OF_BITS);
    
    subtractBinaryNumbers(copy1, copy2);
    displayBinaryNumber(copy1, NUMBER_OF_BITS);
    
    if(checkSubtractionOverflow(num1Sign, num2Sign, copy1)){
        printf("\nOVERFLOW OCCURRED in subtraction!\n");
    } else {
        printf("\nNo overflow detected in subtraction.\n");
    }

    getch();
    return 0;
}