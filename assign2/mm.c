/***********************************
 * * EECS 2031 - Assignment 2
 * * Filename: mm.c
 * * Author: Jose Cardona
 * * Email: jmcardon@my.yorku.ca	 	
 * * Login ID: jmcardon	
 * ************************************/


#include <stdio.h>
#include <stdlib.h>


/***************** DO NOT USE ARRAY INDEXING *****************/
/************** USE ONLY POINTERS IN THIS FILE ***************/

/* You may define additional functions and local variables. */

int baseTenConvert(int num,  int exp) {
	int i;
	for (i = 1; i < exp; i++)
		num = num * 10;
	return num;
}


int strToInt(char* str){
	int length = 0;
	int result = 0;
	int counter = 0;
	while( *(str+length) != '\0'){
		length++;
	}
	while(length > 0){
		result += baseTenConvert(*(str + counter)-'0',length--);
		counter++;
	}
	return result;
}

/* 
 *    Save the three command-line arguments into nr1, nc1 and nc2.
 *     */

void get_args( char **argv, int *nr1, int *nc1, int *nc2 )
{

	/*************** ADD YOUR CODE HERE ***************/
	/*Assuming Three args, any incorrect input on the arglist */
	*nr1 = strToInt(*(argv+1));
	*nc1 = strToInt(*(argv+2));
	*nc2 = strToInt(*(argv+3));

}


/*
 *    Initialize a 2-dimensional array.  
 *       Element (i, j) is assigned value i+j.
 *        */

void initMatrix ( int **a, int nrows, int ncols )
{

	/*************** ADD YOUR CODE HERE ***************/
	int i, j;
	for(i=0; i < nrows; ++i){
		for(j=0; j < ncols; ++j){
			*( *(a + i) + j) = i + j;
		}
	}

}





/* 
 *    Multiply arrays a and b.  
 *       Array a has nr1 rows and nc1 columns.
 *          Array b has nc1 rows and nc2 columns.
 *             Allocate an array c having nr1 rows and nc2 columns.
 *                Compute a x b and store the result in array c.
 *                   Return array c.
 *                      If an error occurs (e.g., insufficient memory), return NULL pointer.
 *                       */


int **matrix_mult( int **a, int **b, int nr1, int nc1, int nc2 )
{

	/*************** ADD YOUR CODE HERE ***************/
	int **c;
	int i, j, k;
	int buffer;
	c = (int **)malloc(sizeof(int *) * nr1);
	//Matrix dimensions are mxn, nxp, mxp
	//i = m
	for(i=0;i<nr1; ++i){
		*(c+i) = (int *)malloc(sizeof(int) * nc2);
		//j = p
		for(j = 0; j < nc2; ++j){
			buffer = 0;
			//k = n
			for(k=0; k < nc1; ++k){
				buffer += *( *(a+i)+k) * *( *(b+k) + j);
			}
			*( *(c+i)+j) = buffer;
		}
	}


	return( c );	/* replace this line with your code */
}


/************************* END OF FILE *************************/


