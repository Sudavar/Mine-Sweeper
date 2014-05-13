/* 
 * answers.c 
 * Created on: Dec 22, 2009 
 * Author: Sudavar 
 */
int answers(int ***field , int x , int y , int a , int b , int *mines)
{
	int tmp_i , tmp_j , treaty , target , counter ;

	target = x*y - (*mines) ;
	counter = 0 ;

	if (field[a][b][1] != '#') {
		if (field[a][b][1] == '*') {
			field[a][b][0] = field[a][b][1] ;
			for( tmp_i = 0 ; tmp_i < x ; ++tmp_i )
				for( tmp_j = 0 ; tmp_j < y ; ++tmp_j )
					if( field[tmp_i][tmp_j][1] == '*' )
						field[tmp_i][tmp_j][0] = field[tmp_i][tmp_j][1] ;
			return -1 ;
		}
		field[a][b][0] = field[a][b][1] ;
	}
	else{
		field[a][b][1] = ' ' ;
		for( tmp_i = a-1 ; tmp_i <= a+1 ; ++tmp_i ){
			for( tmp_j = b-1 ; tmp_j <= b+1 ; ++tmp_j ){
				treaty = 1 ;
				if( tmp_i < 0 || tmp_i >= x )
					treaty = 0 ;
				if( tmp_j < 0 || tmp_j >= y )
						treaty = 0 ;
				if( treaty && field[tmp_i][tmp_j][1] != '#' )
						field[tmp_i][tmp_j][0] = field[tmp_i][tmp_j][1] ;
				else if( treaty && field[tmp_i][tmp_j][1] == '#' )
						answers( field , x , y , tmp_i , tmp_j , mines ) ;
			}
		}
	}
	for( tmp_i = 0 ; tmp_i < x ; ++tmp_i )
		for( tmp_j = 0 ; tmp_j < y ; ++tmp_j )
			if( field[tmp_i][tmp_j][1] == field[tmp_i][tmp_j][0] )
				counter++ ;
	if( counter == target )
		return 1 ;
 return 0 ;
}
