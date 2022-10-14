// main.c
#include <stdio.h>
#include "usbstk5515.h"

#define IR_length 12
#define In_length 12


Int16 x[In_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 array[IR_length];
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;

Int16 coefs[IR_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 input;
Int16 output;

void linearbuff(void)
{
  int i, k;

  for (k=0; k < IR_length/2; k++){
      	int temp;
      	temp = coefs[k];
      	coefs[k] = coefs[IR_length-k - 1];
      	coefs[IR_length-k - 1] = temp;
      }
  // write convolution code here;

  for (i = 0; i < IR_length; i++)
  {
    array[i] = 0;
    int temp;

    temp = coefs[IR_length-1];
    for(k = IR_length -1;k > 0 ;k--){
    	coefs[k] = coefs[k -1];
    }
    coefs[0] = temp;

    for (k = 0; k < IR_length; k++){
    	array[i] = array[i] + x[k] * coefs[k];
    }
    //printf("%d ", array[i]);
  }
  //*/
}

int main(void){
  int j = 0;
  int u = 0;
  coeff = &coefs[0];

  while (j < In_length) // loop
  {
    /* Read input data using a probe-point connected to a host file. */
    input = x[j];
    // write your code for function call;
    j = j + 1;
  }
  linearbuff();

  while (u < IR_length) // loop
  {
    /* Read input data using a probe-point connected to a host file. */
    // write your code for function call;
    //array[u] = output;
    printf("%d ", array[u]);
    u = u + 1;
  }
  return 0;
}

