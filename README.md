# Simple-FIR-filter

Prompt:
In this exercise you will develop a program that implements a discrete-time moving average filter, which is a simple discrete-time finite impulse response (FIR) filter, an important filter used in signal processing.  In a discrete FIR filter, given an input signal x[n] of data stored in an array of doubles, the idea is to compute an output signal y[n], where

  y[n] = b(0)*x[n] + b(1)*x[n-1] + ... + b(N)*x[n-N] = (i=0) Σ (N) b(i)*x[n-i]. (That is the sum from 'i=0' to 'N' of 'b(i)*x[n-i]')

N is called the filter order.  From the definition of y[n] above, an Nth-order filter is the sum of N+1 terms.  The bi terms are weights.  For a moving average filter, set for all i.

Download signal.dat and store the file in the same directory as your project Debug directory where your compiled executable resides.  Here is example code that opens and reads the contents of the signal.dat data file, line by line:

  #include <stdio.h>
  
  int main(void)
  {
       FILE *fPtr;
       // fopen opens file; exits program if file cannot be opened
       if ((fPtr = fopen("signal.dat", "r")) == NULL) {
             puts("File could not be opened");
       }
       else {
             double sample;
             // while not end of file
             while (!feof(fPtr)) {
                  fscanf(fPtr, "%lf", &sample);
                  printf("%7.3f\n", sample);
             }
             fclose(fPtr); // fclose closes the file
       }
  }

Write a program to read the data in the file signal.dat into array x[n] and compute the filtered output signal y[n], for N = 10 and N = 100.  Using a plotting application you prefer, based on information you learned from the Canvas Discussion exercise, plot the input signal (raw data) x[n] in red, and the filtered output signal y[n], for N = 10 and N = 100, in blue and green, respectively.  Your plot should resemble that shown in the figure below.  As you can see, a moving average filter averages or smooths the raw (input) data.

[moving_window.png]([url](https://drive.google.com/file/d/1dMUQx7FqQERbeEDdEjVfpkdMDe7yF4ua/view?usp=sharing))

Demonstrate your program and show your plot to your laboratory section TA to receive credit for this assignment.
