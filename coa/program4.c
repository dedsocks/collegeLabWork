//Program to implement booths algorithm
#include<stdio.h>
#define  NUMBER_OF_BITS 4

void inputBinaryNumber(int* binaryNumber, int serialNumber){
    int i;
    printf("Enter binary number %d (%d bits unsigned) : ",serialNumber,NUMBER_OF_BITS);
    for(i = 0; i < NUMBER_OF_BITS; i++){
        scanf("%d", &binaryNumber[i]);
    }
}

int main(){
    int serialNumber = 1;
    int multiplicand[NUMBER_OF_BITS], multiplier[NUMBER_OF_BITS],  finalNumber[2*NUMBER_OF_BITS];
    
    inputBinaryNumber(multiplicand, serialNumber++);
    inputBinaryNumber(multiplier, serialNumber++);

    


}