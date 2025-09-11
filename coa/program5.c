//Division of unsigned binary numbers
#include<stdio.h>
#define  NUMBER_OF_BITS 4

void inputBinaryNumber(int* binaryNumber, int serialNumber){
    int i;
    printf("Enter binary number %d (%d bits signed) : ",serialNumber,NUMBER_OF_BITS);
    for(i = 0; i < NUMBER_OF_BITS; i++){
        scanf("%d", &binaryNumber[i]);
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

void copyArray(int* arrayCopy, int* originalArray){
    for(int i = 0; i < NUMBER_OF_BITS; i++){
        arrayCopy[i] = originalArray[i];
    }
}

void subtractBinaryNumbers(int* minuend, int* subtraend){
    int subtraendCopy[NUMBER_OF_BITS];
    copyArray(subtraendCopy, subtraend);
    find2sComplement(subtraendCopy);
    addBinaryNumbers(minuend, subtraendCopy);
}

void shiftLeft(int* binaryNumber){
	int i;
    for(i = 0; i < NUMBER_OF_BITS - 1; i++){
        binaryNumber[i] = binaryNumber[i + 1];
    }
    binaryNumber[NUMBER_OF_BITS - 1] = 0;
}


int main(){
    int serialNumber = 1;
    int divisor[NUMBER_OF_BITS], divident[NUMBER_OF_BITS];
    
	printf("===RESTORING DIVISION ALGORITHM===\n\n");

    inputBinaryNumber(divisor, serialNumber++);
    inputBinaryNumber(divident, serialNumber++);
    
    return 0;
}



