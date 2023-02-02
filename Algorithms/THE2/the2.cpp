#include "the2.h"
#include <cmath>
// You may write your own helper functions here
void countingSort(int* originalArr, int* digitArr, int arraySize, long &iterationCount, bool ascending, int groupSize) {
    int max = -1, sortedArr[arraySize], reqTemp;
    reqTemp = pow(10, groupSize);
    for(int i = 0; i < arraySize; i++) {
        if(digitArr[i] > max)
        max = digitArr[i];
    }
    int tempArr[reqTemp] = {0};
    for(int j = 0; j < arraySize; j++) {
        tempArr[digitArr[j]] += 1;
        iterationCount++;
    }
    for(int i = 1; i < reqTemp; i++) {
        tempArr[i] += tempArr[i-1];
        iterationCount++;
    }
    for(int j = arraySize-1; j >= 0; j--) {
        sortedArr[tempArr[digitArr[j]]-1] = originalArr[j];
        tempArr[digitArr[j]] -= 1;
        iterationCount++;
    }
    for(int i = 0; i < arraySize; i++) {
        originalArr[i] = sortedArr[i];
        iterationCount++;
    }

}
long multiDigitRadixSort(int* arr, bool ascending, int arraySize, int groupSize, int maxDigitLength){
    long numberOfIterations = 0;

        int digitArr[arraySize], MDL, temp, count;
        for(int i = 0; i < ceil(maxDigitLength / double(groupSize)); i++) {
            count = MDL = 1;
            for(int j = 0; j < arraySize; j++) {
                digitArr[j] = int((arr[j] / pow(10, i * groupSize))) % int(pow(10, groupSize));
                temp = digitArr[j];
                count = 1;
                while(temp / 10 != 0) {
                    count++;
                    temp /= 10;
                }
                if(count > MDL)
                MDL = count;
            }
            countingSort(arr, digitArr, arraySize, numberOfIterations, true, MDL);
        }
        if(!ascending) {
            for(int i = 0; i < arraySize / 2; i++) {
            temp = arr[i];
            arr[i] = arr[arraySize - 1 - i];
            arr[arraySize - 1 - i] = temp;
        }
        }
    
    return numberOfIterations;
}