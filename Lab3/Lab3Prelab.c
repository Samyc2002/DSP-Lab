/*
 * main.c
 */

#include "usbstk5515.h"
#include <stdio.h>

#define IR_length 12
#define In_length 12
#define tmp_l IR_length + In_length - 1

Int16 x[In_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 array[tmp_l];
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;
Int16 coefs[IR_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 input;
Int16 output;

void linearbuff(void) {
    int i;
    long int accumulator = 0;
    static Int16 buffer[In_length] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    /*
     write convolution code here;
     */
    (*outPtr) = ((Int16)accumulator);
}

int main(void) {
    int j = 0;
    coeff = &coefs[0]; // coefs is coefficient of impulse response defined in
                       // fdacoefs_int.h
    inPtr = &input;    // inPtr is a globally declared pointer to a Int16
    outPtr = &output;
    //	SYS_EXBUSSEL = 0x6100;
    //    USBSTK5515_init( );
    // temp_length=IR_length+In_length-1;

    // static Int16 inbuffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (put your condition) // loop
    {
        /*  Read input data using a probe-point connected to a host file. */
        // printf("x=%d\n",x[j]);

        input = x[j];
        // write your code for function call;

        array[j] = output;
        printf("output=%d\n", array[j]);

        j = j + 1;
    }
    return 0;
}

/*
 * FUNCTION:     Read input signal and write processed output signal
 *              using ProbePoints
 * PARAMETERS: none.
 * RETURN VALUE: none.
 */
/*static void dataInput()
{
    do data I/O
    return;
}*/
