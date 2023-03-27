#include <stdio.h>

void countFile(void) {
    FILE *fp;
    char ch;
    int charCount = 0, wordCount = 0, inWord = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error: File not found.\n");
        return;
    }

    while ((ch = fgetc(fp)) != EOF) {
        charCount++;

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }

    printf("Total number of characters: %d\n", charCount);
    printf("Total number of words: %d\n", wordCount);

    fclose(fp);
}

void insertionSort(int L[], int size) {

    for(int i = 1; i < size; i++) {
        for(int j = i; j > 0; j--) {
            if(L[j-1] > L[j]) {
                int temp = L[j-1];
                L[j-1] = L[j];
                L[j] = temp;
            } else {
                break;
            }
        }



    }
}


int main() {
    countFile();
    int arr[5] = {5,3, 1, 2,4};
    insertionSort(arr, 5);

    for(int i = 0; i < 5; i++) {

        printf("%d ", arr[i]);

    }
    
    return 0;
}
