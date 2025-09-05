//Program to implement booths algorithm
#include<stdio.h>
#define  NUMBER_OF_BITS 4

void inputBinaryNumber(int* binaryNumber, int serialNumber){
    int i;
    printf("Enter binary number %d (%d bits signed) : ",serialNumber,NUMBER_OF_BITS);
    for(i = 0; i < NUMBER_OF_BITS; i++){
        scanf("%d", &binaryNumber[i]);
    }
}

void addBinaryNumbers(int* binaryNumber1, int* binaryNumber2, int* finalNumber){
    int i, carry = 0;
    for(i = NUMBER_OF_BITS-1; i >= 0; i--){
        finalNumber[i] = binaryNumber1[i] + binaryNumber2[i] + carry;
        if(finalNumber[i] >= 2){
            carry = 1;
        }
        else carry = 0;
        finalNumber[i] %= 2;
    }
}

void displayBinaryNumber(int* binaryNumber, int numberOfBits){
    int i;
    printf("\nResult: ");
    for(i = 0; i < numberOfBits; i++){
        printf("%d ", binaryNumber[i]);
    }
    printf("\n\n");
}

int main(){
    int serialNumber = 1;
    int multiplicand[NUMBER_OF_BITS], multiplier[NUMBER_OF_BITS],  finalNumber[2*NUMBER_OF_BITS];
    
    inputBinaryNumber(multiplicand, serialNumber++);
    inputBinaryNumber(multiplier, serialNumber++);

    
    return 0;
}