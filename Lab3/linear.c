/*
  main.c
*/

#include <stdio.h>
#include "usbstk5515.h"

#define IR_length 5
#define In_length 5
#define tmp_l IR_length+In_length-1

Int16 x[tmp_l] = {1, 7, 10, 55, 29};
Int16 array[tmp_l];	// made for output
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;
Int16 coefs[tmp_l] = {1, 5, 10, 15, 20};
Int16 input;
Int16 output;


void linearbuff(int j) {
	long int accumulator=0;
	static Int16 buffer[tmp_l]={0, 0, 0, 0, 0};
	/*
	 write convolution code here;
	*/
   int k;
   for(k=0;k<=j;k++) {
	   accumulator = accumulator + x[k]*coefs[j-k];
   }
   (*outPtr)=(buffer[j]+accumulator);
}

int main(void) {
	int i, j=0;
	coeff = &coefs[0]; 	//coefs is coefficient of impulse response defined in fdacoefs_int.h
	inPtr = &input;		//inPtr is a globally declared pointer to a Int16
	outPtr = &output;
	//	SYS_EXBUSSEL = 0x6100;
	//    USBSTK5515_init( );
	//temp_length=IR_length+In_length-1;

	//static Int16 inbuffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	for(i=IR_length; i<tmp_l; i++) {
		coefs[i] = 0;
	}

	for(i=In_length; i<tmp_l; i++) {
		x[i] = 0;
	}

//   for(i=1; i<len/2; i++) {
//	   int temp = coefs[i];
//	   coefs[i] = coefs[len-i-1];
//	   coefs[len-i-1] = temp;
//   }

    while(j<tmp_l) // loop
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);

    	//input=x[j];

    	//write your code for function call;
    	linearbuff(j);
    	array[j]=output;
    	printf("output=%d\n",array[j]);

    	j=j+1;
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

