/*
 * initialazing.c
 * Created on: Dec 22, 2009
 * Author: Sudavar
 */
#include <stdlib.h>

void initialazing(int ***field , int x , int y , int max )
{
    int mines, i, j, r_i, r_j;  	/* Variables declaration */

    for( i = 0 ; i < x ; ++i)       /* Here i initialize the two arrays's               */
        for( j = 0 ; j < y ; ++j){  /* Dimension 0 of the board will be covered by x's  */
                                    /* in order to player see the board covered         */
            field[i][j][0] = 'x' ;  /* Dimension 0 of the board (as i said before)      */
            field[i][j][1] = '0' ;  /* represent the solution of current game but first */
        }                           /* it must be initialized to zero                   */

    mines = 0 ;                     /* This variable represent the number of mines i have already place */
    while( mines < max ){			/* Starting from 1rst mine until it reaches last mine (max) */
		r_i = rand() % (x) ;        /* The r_i becomes a random number (0<r_i<x (x == horizontal size of board) ) and represent the row where mine will be placed */
		r_j = rand() % (y) ;        /* The r_j becomes a random number (0<r_j<x (x == vertical size of board)) and represent the column where mine will be placed */
        if( field[r_i][r_j][1] != '*' ){    /* Unless of course if there is already another mine in the specified cell */
            field[r_i][r_j][1] = '*' ;		/* If everything is ok , i put the mine there   */
            mines++ ;				        /* and increase the number of mines placed      */
        }
    }
 return ;
}
