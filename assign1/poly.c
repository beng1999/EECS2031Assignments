/***********************************
* EECS2031 - Assignment 1
* Filename: poly.c 
* Author: Last name, first name
* Email: Your preferred email address
* Login ID: Your EECS login ID
************************************/

#include "poly.h"


/* 
  Initialize all coefficients and exponents of the polynomial to zero.
 */
void init_polynom( int coeff[ ], int exp[ ] )
{

    /* ADD YOUR CODE HERE */
    int i;
    for(i =0; i < ASIZE; i++){
        coeff[i] = 0;
        exp[i] = 0;
    }

}  /* end init_polynom */


/*
  Get inputs from user using scanf() and store them in the polynomial.
 */
void get_polynom( int coeff[ ], int exp[ ] )
{

    /* ADD YOUR CODE HERE */
    int numInputs;
    scanf("%d", &numInputs);
    int i;
    int counter = 0;
    for(i = 0; i< (2*numInputs); i++){
        if(i % 2 == 0){
            scanf("%d", &coeff[counter]);
            continue;
        }
        scanf("%d", &exp[counter]);
        counter++;
    }

}  /* end get_polynom */

/* Converts integer to string */
int intToString(char s[ ], int num){
    int length = 0;
    int n = num;
    while(n != 0){
        length++;
        n = n/10;
    }
    int counter = 1;
    while(num != 0){
        s[length-counter] = '0' + (num % 10);
        num = num/10;
        counter++;
    }
    length;
    return length;
}

/*
  Convert the polynomial to a string s.
 */
void polynom_to_string( int coeff[ ], int exp[ ], char s[ ] )
{

    /* ADD YOUR CODE HERE */
    int counter = 0;
    int arrIndex = 0;
    while(1) {

        //If the string is empty, print 0
        if(coeff[counter] == 0 && counter == 0){
            s[arrIndex] = '0';
            arrIndex++;
            s[arrIndex] = '\0';
            break;
        }

        //If the coefficient is zero, exit the loop, terminate the string
        if(coeff[counter] == 0){
            s[arrIndex] = '\0';
            break;
        } else if (coeff[counter] < 0){
            //If the coefficient is negative, add -, convert value to positive
            s[arrIndex] = '-';
            arrIndex++;
            coeff[counter] = coeff[counter] * -1;
            if(coeff[counter] > 1 || exp[counter]  == 0) arrIndex = arrIndex + intToString(s+arrIndex, coeff[counter]);
            coeff[counter] = coeff[counter] * -1;
        } else if (counter > 0 ){
            s[arrIndex] = '+';
            arrIndex++;
            if(coeff[counter] > 1 || exp[counter]  == 0) arrIndex = arrIndex + intToString(s+arrIndex, coeff[counter]);
        } else{
            if(coeff[counter] > 1 || exp[counter]  == 0) arrIndex = arrIndex + intToString(s+arrIndex, coeff[counter]);
        }

        //Add the number



        //If the exponent is not zero, add the x
        if(exp[counter] != 0){
            s[arrIndex] = 'x';
            arrIndex++;
            //If the exponent is negative, add the -, make the value positive and convert to string
            if(exp[counter] < 0){
                s[arrIndex] = '^';
                arrIndex++;
                s[arrIndex] = '-';
                arrIndex++;
                exp[counter] = exp[counter] * -1;
                arrIndex = arrIndex + intToString(s+arrIndex, exp[counter]);
                exp[counter] = exp[counter] * -1;
            }
            //If it's greater than 1, add the ^ and convert to string, else do nothing
            else if (exp[counter] > 1) {
                s[arrIndex] = '^';
                arrIndex++;
                arrIndex = arrIndex + intToString(s+arrIndex, exp[counter]);
            }
        }
        counter++;
    }

    s[arrIndex] = '\0';

}  /* end polynom_to_string */


/*Function to exponentiate a base 10 number.
 *
 * Note: There are faster implementations of the exponentiation function with logarithms,
 * but this is out of the scope of this assignment
 *
 */
double exponentiator(double number, int exponent){
    int i;
    double base = number;
    for(i = 1; i<exponent; i++){
        base = base * number;
    }
    return base;
}

/*
  Evaluate the polynomial for the value of x and store the result p(x) in variable result.
 */
void eval_polynom( int coeff[ ], int exp[ ], double x, double *result )
{

    * result = 0;
    int counter = 0;
    while(1){
        if(coeff[counter] == 0){
            break;
        }
        if(exp[counter] == 0){
            *result += coeff[counter];
            counter++;
            continue;
        }
        *result += (double)coeff[counter] * exponentiator(x, exp[counter]);
        counter++;
    }


}  /* end eval_polynom */

/*
 Modified quicksort: Sorts in descending order, and the second array based on the swaps of the first.
 */
void quicksort(int firstArray[], int low, int high, int secondArray[]){
    if (low < high) {
        int pivot = partition(firstArray, low, high, secondArray);
        quicksort(firstArray, low, pivot-1, secondArray);
        quicksort(firstArray, pivot+1, high, secondArray);
    }
    return;
}

//Pivot algorithm
int partition(int firstArray[], int low, int high, int secondArray[]){
    int pivot = firstArray[low];
    int i = low +1;
    int j;
    int swapper;
    for(j = low+1; j<=high; j++){
        if(firstArray[j]>=pivot){
            swapper = firstArray[j];
            firstArray[j] = firstArray[i];
            firstArray[i] = swapper;
//            Swap the second array in the same order
            swapper =secondArray[j];
            secondArray[j] = secondArray[i];
            secondArray[i] = swapper;
            i++;
        }
    }

    int finalSwap = firstArray[low];
    firstArray[low] = firstArray[i - 1];
    firstArray[i-1] = finalSwap;

    finalSwap = secondArray[low];
    secondArray[low] = secondArray[i - 1];
    secondArray[i-1] = finalSwap;
    return i-1;
}

int arrayLength(int arr[]){
    int counter=0;
    while(1){
        if (*arr == 0) break;
        arr++;
        counter++;
    }
    return counter;
}

void shiftRight(int arr1[ ], int arr2[ ]){
    int counter = 0;
    do{
        arr1[counter] = arr1[counter + 1];
        arr2[counter] = arr2[counter + 1];
        counter++;
    } while(arr1[counter] != 0);
}

int polynomAddition( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ], int lengthFirst ){
    int i;
    int counter = 0;
    int increments = 0;
    while(1){
        i = 0;
        if(co2[counter] == 0){
            break;
        }
        while(1){
            if(i == lengthFirst){
                co1[lengthFirst + increments] = co2[counter];
                ex1[lengthFirst + increments] = ex2[counter];
                increments++;
                break;
            }
            if (ex2[counter] == ex1[i]){
                co1[i] += co2[counter];
                if(co1[i] == 0){
                    shiftRight(co1 + i, ex1 + i);
                }
                break;
            }
            i++;
        }
        counter++;
    }
    return increments;
}

/*
  Add two polynomials and the result is stored in the first polynomial (arrays co1[] and ex1[]).
  Sort based on exponent
 */
void add_polynom( int co1[ ], int ex1[ ], int co2[ ], int ex2[ ])
{
    int firstLength = arrayLength(co1);
    int secondLength = arrayLength(co2);
    int increment;

    if (firstLength >= secondLength){
        increment = polynomAddition(co1, ex1, co2, ex2, firstLength);
        quicksort(ex1, 0, firstLength-1+increment, co1);
    }
    else {
        increment = polynomAddition(co2, ex2, co1, ex1, secondLength);
        int j;
        for (j = 0; j<secondLength; j++){
            co1[j] = co2[j];
            ex1[j] = ex2[j];
        }
        quicksort(ex1, 0, secondLength-1+increment, co1);
    }



    /* ADD YOUR CODE HERE */

}  /* end add_ polynom */






/************************** END OF FILE ***************************/




