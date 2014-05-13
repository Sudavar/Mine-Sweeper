/*
 * printing.c
 * Created on: Dec 22, 2009
 * Author: Sudavar
 */
#include <stdio.h>

void printing(int ***field , int x , int y , int cheat)		/* This function was made in order to print the game board      */
{                       /* Variables declaration */
	int i , j ;                                             /* Variable i represents the row of game board while            */
															/* Variable j represents the colummn of game board              */

	if(cheat)                                               /* If a person knows the passwords , he can unlock Dimension 0  */
		printf("\n\tCheat below\n") ;                   	/* This feature was made mostly in order for me having access   */
															/* to Dimension 0 , anytime while i was developing the programm */
	/* Printing Game Board */
	printf("\n__|") ;
	for(j = 0 ; j < y ; j++)
		printf("%02d|" , j+1 ) ;
	printf("\n") ;

	for(i = 0 ; i < x ; i++){
		printf("%02d| " , i+1) ;
		for( j = 0 ; j < y ; j++){
			putchar(field[i][j][cheat]) ;
			printf("  ") ;
		}
		printf("\n") ;
	}
}
