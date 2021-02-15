#include <stdio.h>
#include <stdlib.h>

// function declarations
int isEven(const int num);
int isPrime(const int num);

int main() {
    FILE *fPtrIn = NULL;
    int num = 0, success = 0;

    fPtrIn = fopen("testFile.txt", "r");

    if (fPtrIn == NULL) {
        printf("Unable to open file.\n");
        printf("Please check if file exists.\n");
        exit(EXIT_FAILURE);
    }

    // file open success message
    printf("File opened successfully. Reading integers from file.\n\n");

    // read an integer and store read status in success. (initial read)
    success = fscanf(fPtrIn, "%d", &num);

    do {
        // write prime, even and odd numbers to standard output
        if (isPrime(num)){
            printf("Prime number found: %d\n", num);
        }
        else if (isEven(num)) {
            printf("Even number found: %d\n", num);
        }
        else {
            printf("Odd number found: %d\n", num);
        }
        // read another integer
        success = fscanf(fPtrIn, "%d", &num);
    } while (success != -1);

    fclose(fPtrIn);

    return 0;
}

int isEven(const int num) {
    return !(num & 1);
}

int isPrime(const int num) {
    int i = 0;

    // only positive integers are prime
    if (num < 0) {
        return 0;
    }

    for (i = 2; i <= num/2; i++) {
        // if number is divisible by any number other than 1 and self then it's not prime
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}