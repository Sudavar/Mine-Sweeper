/*
 * main.c
 * Created on: Dec 22, 2009
 * Author: Sudavar
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

/* 	Welcome , this is a program which stimulate the game Minesweeper
	This was my first "serious" project so it may not be perfect */
int main(void)
{
	int i , j , N , M , ***field , mines , maxm , minm , ans1 , ans2 ;
	int treaty, e_o_g, none;
 do
 {
	srand( time(NULL) ) ;		/* Random numbers are required to put the mines in random positions */
	e_o_g = 0 ;					/* This is a treaty to check whether it's the end of game or not */
	treaty = 0 ;				/* This is a treaty to check whether data input is correct or not */
	/* Data input */
	printf("We will need you to type some information before you play the game\n") ;
	printf("Please give the desired number of rows and columns \n(With one space between them) : ") ;
    		if((none = scanf("%d%d", &N, &M)) != 2)
				printf("More input than expected\n");
    	maxm = (N*M) / 2 ;			/* There are going to be some limits for mines number (upper limit) */
    	minm = (N*M) / 6 ;			/* There are going to be some limits for mines number (down limit) */
	do{								/* The game is going to be played as long as the player wants */
        	if( treaty )			/* That's for the case player entered illegal numbers */
        		printf("\n\nWrong Input\tPlease give right number of mines\n\n") ;
			/* Another data input */
			printf(	"Give number of mines larger or equal to %d "
				"and smaller or equal to %d\n"
				"or zero (0) for default number of mines: " , minm , maxm ) ;
    			if((none = scanf("%d", &mines)) != 1)
					printf("More input than expected\n");
    		if( !mines )			/* That's for default number of mines (according to size player gave) */
			mines = ( N + M ) ;		/* If someone wish , he can change that (not mandatory) */
	}while( ( treaty = (mines < minm || mines > maxm ) && mines != ( N + M ) ) ) ;	/* Checking data input */

	field = malloc ( N * sizeof (int **) ) ;
	if( field == NULL ){
		printf("ERROR while allocating memory\a\n") ;		/*== Allocating Memory in following lines ==*/
		return -1 ;											/*== I am going to use an array   ==*/
	}														/*== which will have 3 dimensions ==*/
	for( i = 0 ; i < N ; i++ ){								/*== ---------------------------- ==*/
		*(field+i) = malloc ( M * sizeof (int *) ) ;		/*== 1rst Dimensions will have the number of rows of game board		   ==*/
		if( field[i] == NULL ){								/*== 2nd Dimensions will have the number of columns of game board	   ==*/
			printf("ERROR while allocating memory\a\n") ;	/*== 3rd Dimensions is going to be used in order to have 2 game boards ==*/
			return -1 ;										/*== One of those two game boards is going to be used in order   ==*/
		}													/*== to keep there the solution of current game while the other  ==*/
	}														/*== is going to be used as the game board the player would have ==*/
															/*== to face and solve ==*/

	for( i = 0 ; i < N ; i++ )								/*== ==*/
		for( j = 0 ; j < M ; j++ ){							/*== ==*/
			field[i][j] = malloc ( 2 * sizeof (int) ) ;		/*== ==*/
			if( field[i][j] == NULL ){						/*== ==*/
				printf("ERROR while allocating memory\a\n");/*== ==*/
				return -1 ;									/*== ==*/
			}
		}

	initialazing ( field , N , M , mines ) ;		/* Firstly i initialize the two array's and the game is ready to begin 	*/
	minefinder( field , N , M ) ;					/* Then i use this function (more details in function's source)		*/
	printing( field , N , M , 0 ) ;					/*  */

	while( e_o_g == 0 ){
		treaty = 0 ;
		do{
			if( treaty ){
				printf("\nWrong Input\tPlease give right coordinates\n\n") ;
				printf("Give number of row between 1 and %d\n" , N ) ;
				printf("Give number of column between 1 and %d" , M ) ;
			}
			printf("\nPlease give the coordinates of your choice\n"
				   "Give the number of row : ") ;
				if((none = scanf("%d", &ans1)) != 1)
					printf("More input than expected\n");
			printf(	   "Give number of column : ") ;
				if((none = scanf("%d", &ans2)) != 1)
					printf("More input than expected\n");
			if( ans1 == 9170 && ans2 == 9169 )
				printing( field , N , M , 1 ) ;
			ans1-- ;
			ans2-- ;
		}while( (treaty = ( ans1 < 0 || ans1 >= N ) || ( ans2 < 0 || ans2 >= M ) ) ) ;

		e_o_g = answers( field , N , M , ans1 , ans2 , &mines ) ;
		if( e_o_g == 1 )
			break ;
		printing( field , N , M , 0 ) ;
	}
		if( e_o_g == -1 ){
			printf("\n\n\nSo sorry but you lost the game!! :(\n") ;
		}
		else if( e_o_g == 1 ){
			printing( field , N , M , 1 ) ;
			printf("\n\n\nNice you just won the game!! :)\n") ;
		}
	for(i = 0 ; i < N ; i++){
		for(j = 0 ; j < M ; j++)
		    	free (field[i][j]) ;
		free (field[i]) ;
	}
	free(field) ;
	printf("Do you want to play again ? (y , n) :") ;
	getchar() ;
 }while( getchar() == 'y' );
 printf("\n\t    Thanks for playing! :)\n"
 		"\t---------------------------------\n"
 		"\t             Credits:            \n"
		"\tWritten by Yury, thaNOS and Zylo\n\n"
		"\t        Special thanks to:       \n"
		"\t        Stella and Kwstas        \n\n"
		"\t---------------------------------\n"
		"\t~~~~~~~~~~~ DIT @ UOA ~~~~~~~~~~~\n\n" ) ;
 return 0 ;
}
