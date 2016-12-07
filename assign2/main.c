/***********************************
 * * EECS 2031 - Assignment 2
 * * Filename: mmMain.c
 * * Author: U. T. Nguyen
 * *
 * ************************************/


#include <stdio.h>
#include <stdlib.h>


/*
 *    Allocate a 2-dimensional array of size [nrows][ncols].
 *       Display an eror message and exit the program is the allocation fails.
 *        */


static int** alloc2D( int nrows, int ncols )
{

	int **array, i;

	/* Allocate an array of pointers, each pointing to a row. */
	array = ( int** ) malloc( nrows * sizeof( int* ) );
	if ( array == NULL ) {
		printf( "Insufficient memory!\n" );
		exit ( 1 );
	}

	/* Allocate each row. */
	for(i = 0; i < nrows; i++) {
		array[i] = ( int* ) malloc( ncols * sizeof( int ) );
		if ( array[i] == NULL ) {
			printf( "Insufficient memory!\n" );
			exit ( 1 );
		}
	}

	return( array );

}



/*
 *    Display the matrix on standard output.
 *     */

void prtMatrix ( int **a, int nrows, int ncols )
{

	int i, j;
	for ( i = 0; i < nrows; i++ ) {
		for ( j = 0; j < ncols; j++ )
			printf( "%5d", a[i][j] );
		printf( "\n" );
	}
	printf( "\n" );

}




/* main function */

main(  int argc, char *argv[] )
{

	int nr1, nc1, nr2, nc2;   
	int **ap, **bp, **cp;

	if ( argc != 4 ) {
		printf( "Usage: mm [number_of_rows_1] [number_of_columns_1] [number_of_columns_2]\n " );
		exit( 1 );
	}


	get_args( argv, &nr1, &nc1, &nc2 );
	nr2 = nc1;	/* for matrix multiplication */


	/* Allocate and initialize two 2-dimensional arrays (matrices) */
	ap = alloc2D( nr1, nc1 );
	initMatrix( ap, nr1, nc1 );

	bp = alloc2D( nr2, nc2 );
	initMatrix( bp, nr2, nc2 );


	/* Display matrices ap and bp */
	prtMatrix( ap, nr1, nc1 );
	prtMatrix( bp, nr2, nc2 );


	/* Matrix multiplication */
	cp = (int **) matrix_mult( ap, bp, nr1, nc1, nc2 );
	if ( cp )
		prtMatrix( cp, nr1, nc2 ); 

}

