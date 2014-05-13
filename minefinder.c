/*
 * minefinder.c
 * Created on: Dec 22, 2009
 * Author: Sudavar
 */
void minefinder(int ***field , int rows , int columns )     	/* This function was made in order to replace */
{                                                               /* the zero's of Dimension 0 with the correct */
    /* Variables Declaration */                                 /* numbers , so the game could be played      */
    int i , j , treaty ;        /* Variable i represents the row of game board while */
                                /* Variable j represents the column of game board	 */

    for( i = 0 ; i < rows ; ++i )
        for( j = 0 ; j < columns ; ++j )                              	/* What i do is : accessing the whole board */
            if( *(*(*(field+i)+j)+1) == '*' ){                          /* and when i "meet" a mine (1)*/
                int tmp_i , tmp_j ;
                /* Temporary variables : tmp_i for rows & tmp_j for columns */
                for( tmp_i = i-1 ; tmp_i <= i+1 ; ++tmp_i )             /* (1)for every cell that is right next to the cell with the mine */
                    for( tmp_j = j-1 ; tmp_j <= j+1 ; ++tmp_j ){        /* (with those 2 for i achieve to take into consideration all  */
                        treaty = 1 ;                                    /* cell's around the cell i found to have a mine               */
                        if( tmp_i < 0 || tmp_i >= rows )                /* but i must check whether those cell's are inside the board  */
                            treaty = 0 ;                                /* so there would not appear any segmentation fault)           */
                        if( tmp_j < 0 || tmp_j >= columns )
                            treaty = 0 ;
                        if( treaty ){                                   /* So , if the cell is inside the game board      */
                            if ( *(*(*(field+tmp_i)+tmp_j)+1) != '*' )  /* and if there is not a mine placed in this cell */
                                field[tmp_i][tmp_j][1]++ ;              /* i increase the number located in it            */
                        }
                    }
            }
    for( i = 0 ; i < rows ; ++i )
        for( j = 0 ; j < columns ; ++j ){
            if ( *(*(*(field+i)+j)+1) == '0' )          /* Finally , if there are any cell's with a zero inside   */
                field[i][j][1] = '#' ;                  /* I replace the 0 with an # to mark those cell's as void */
        }                                               /* Reason explained in answers */
}

