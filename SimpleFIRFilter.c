#include <stdio.h>

#define MAX_SAMPLES 100

int main(void) {
    FILE *fPtr;
    double x[MAX_SAMPLES], y10[MAX_SAMPLES], y100[MAX_SAMPLES];
    int i, j, n;
    
    // Open signal.dat file
    if ((fPtr = fopen("C:\\Users\\Amarjot Singh\\Code\\C\\FIRFilter\\Simple-FIR-filter\\signal.dat", "r")) == NULL) {
        puts("File could not be opened");
        return 1;
    }
    
    printf("File opened successfully...\n");
    
    // Read data from file into x array
    i = 0;
    while (!feof(fPtr) && i < MAX_SAMPLES) {
        if (fscanf(fPtr, "%lf", &x[i]) == 1) {
            printf("Read: %lf\n", x[i]); // Print the read value
            i++;
        } else {
            // fscanf failed to read a value (e.g., end of file)
            break;
        }
    }
    
    fclose(fPtr);
    printf("File reading complete...\n");

    // Compute filtered output signals y10 and y100
    for (n = 0; n < MAX_SAMPLES; n++) {
        y10[n] = 0.0;
        y100[n] = 0.0;
        
        for (j = 0; j < 10; j++) {
            if (n - j >= 0) {
                y10[n] += x[n - j];
            }
        }
        
        y10[n] /= 10.0;
        
        for (j = 0; j < 100; j++) {
            if (n - j >= 0) {
                y100[n] += x[n - j];
            }
        }
        
        y100[n] /= 100.0;
        printf("y100[%d] = %lf\n", n, y100[n]);
    }
    
    return 0;
}
