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

void shiftRight(int* binaryNumber){
    int i;
    for(i = NUMBER_OF_BITS-1; i > 0; i--){
        binaryNumber[i] = binaryNumber[i-1];
    }
}

void multiplyBinaryNumbers(int* multiplicand, int* multiplier, int* finalNumber){
    // q1Bit -> Q₋₁ bit from booths algorithm
    int counter = NUMBER_OF_BITS, q1Bit = 0, i; 
    int accumulator[NUMBER_OF_BITS] = {0};
    int indexOfLastElement = NUMBER_OF_BITS - 1;
    int indexOfFinalNumber = NUMBER_OF_BITS * 2 - 1;

    while(counter != 0){
        if(multiplier[indexOfLastElement] == q1Bit);
        else if((multiplier[indexOfLastElement] == 0) && q1Bit == 1){
            addBinaryNumbers(accumulator, multiplicand);
        }
        else {
            subtractBinaryNumbers(accumulator, multiplicand);
        }
        q1Bit = multiplier[indexOfLastElement];
        shiftRight(multiplier);
        multiplier[0] = accumulator[indexOfLastElement];
        shiftRight(accumulator);

        counter--;
    }
    for(i = indexOfLastElement; i >= 0; i--){
        finalNumber[indexOfFinalNumber--] = multiplier[i];
    }
    for(i = indexOfLastElement; i >= 0; i--){
        finalNumber[indexOfFinalNumber--] = accumulator[i];
    }
}

int main(){
    int serialNumber = 1;
    int multiplicand[NUMBER_OF_BITS], multiplier[NUMBER_OF_BITS],  finalNumber[2*NUMBER_OF_BITS];
    
    inputBinaryNumber(multiplicand, serialNumber++);
    inputBinaryNumber(multiplier, serialNumber++);

    multiplyBinaryNumbers(multiplicand,multiplier,finalNumber);
    displayBinaryNumber(finalNumber,NUMBER_OF_BITS*2);
    return 0;
}