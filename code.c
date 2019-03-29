//
//  project-term.c
//
//  Created by Mahdi Kheirmand on 2/23/19.
//
//projec term

#include <stdio.h>

void choose (int a[][8] , int p[][8],int *x , int *y );
void strategy (int board[][8],int p[][8],int c, int a[][8]);
void eligible ( int board[][8] , int a[][8] , int c , int ce ,int i , int j , int *x , int *y);
int check (int board[][8],int c,int i,int j);

int main(int argc, char * argv[]){
    int board[8][8];                        // the board given //
    int a[8][8];                            // the array for function 'eligible'//
    int x,y;                                //x = i-Max ;  y = j-Max //

    // p is the points of each house //
    int p[8][8] = {
        {10000,-3000,1000,800,800,1000,-3000,10000},
        {-3000,-5000,-450,-500,-500,-450,-5000,-3000},
        {1000,-450,30,10,10,30,-450,1000},
        {800,-500,10,50,50,10,-500,800},
        {800,-500,10,50,50,10,-500,800},
        {1000,-450,30,10,10,30,-450,1000},
        {-3000,-5000,-450,-500,-500,-450,-5000,-3000},
        {10000,-3000,1000,800,800,1000,-3000,10000}
    };
    
    int c = argv[9][0] - '0' ;                       //  c  : our colour ; -'0' : char to int//
    int ce;                                          //  ce : enemy's colour//
    if ( c == 1 ){
        ce = 2;
    }
    else{
        ce = 1 ;
    }
    
    int i,j;
    // board //
    for ( i = 0 ; i < 8 ; i++ ){
        for ( j = 0 ; j < 8 ; j++ ){
            board[i][j] = argv[i+1][j] - '0';    // input to board ; -'0' : char to int //
        }
    }
    // board //
    
    // fuction eligible //
    for( i = 0 ; i < 8 ; i++ ){
        for( j = 0 ; j < 8 ; j++ ){
            if( board[i][j] == 0 ){
                eligible(board,a,c,ce,i,j,&x,&y);
            }
            if( board[i][j] != 0 ){
                a[i][j] = -1 ;
            }
        }
    }
    // fuction eligible //
    
    strategy(board,p,c,a);                    // function strategy //
    
    choose(a,p,&x,&y);                        // function choose //
    
    printf("%d %d",y,x);
    
    return 0;
}



void eligible ( int board[][8] , int a[][8] , int c , int ce ,int i , int j , int *x , int *y){
    int ai,aj;                  //  ai : auxilary i  ;   aj : auxilary j //
    int d,e;                    //  d : j   ; e : i  //
    int check = 0;              // not founded //
    for( d = -1  ; check == 0 && d <= 1 ; d++ ){
        for( e = -1 ; check == 0 && e <= 1 ; e++ ){
            if( d != 0  ||  e != 0 ){               // if d == 0 & e == 0 => it checks the same house continously//     
                if ( j + d >= 0  &&  j + d < 8  &&  i + e < 8  &&  i + e >= 0  &&  board[i+e][j+d] == ce ){
                    ai = i + e;
                    aj = j + d;
                    while( board[ai][aj] == ce  &&  ai >= 0  &&  ai < 8  &&  aj >= 0  && aj < 8 ){
                        ai = ai + e;
                        aj = aj + d;
                    }
                    if(board[ai][aj]==c){
                        a[i][j]=0;                   // a[i][j] = 0 => board[i][j] is eligible//
                        *x = i;                      // initial value //
                        *y = j;                      // initial value //
                        check = 1;                     // founded //
                    }
                }
            }
        }
    }

    if( check == 0 ){                                       // not founded //
        a[i][j] = -1 ;                                      // a[i][j] = -1 => board[i][j] is not eligible //
    }
}

void choose (int a[][8] , int p[][8] , int *x, int *y ){
    int i,j;
    for( i = 0 ; i < 8 ; i++ ){                                       // check all the places //
        for( j = 0 ; j < 8 ; j++ ){
            if( a[i][j] == 0 ) {                                // eligible places //
                if( p[*x][*y] < p[i][j] ){
                    *x = i;
                    *y = j;
                }
            }
        }
    }
}

void strategy (int board[][8],int p[][8],int c, int a[][8]){
    int i,j;
    for ( i = 0 ; i < 8 ; i++ ){
        for ( j = 0 ; j < 8 ; j++ ){
            if ( p[i][j] < 0 && a[i][j] == 0 ){
                if ( check(board,c,i,j) == -1 ){
                    p[i][j] = (-1) * p[i][j];
                }
            }
        }
    }
}

int check (int board[][8],int c,int i,int j){
    int h = 0 ;
    int ai = i ;                        // ai : auxilary i //
    int aj = j ;                        // aj : auxilary j //
    int hh = 0;
    int d,e;                            // d : j  ;  e : i //
    if( i == 0 || i == 7 ){
        for( d = -1 ; d <= 1 && h == 0 ; d++ ){
            if( d != 0  &&  h == 0 ){
                hh = 0;
                while( board[ai][aj+d] == c  && hh == 0  &&  ai >= 0  &&  ai < 8  &&  aj+d >= 0  && aj+d < 8 ){
                    aj = aj + d;
                }
                if( aj+d >= 0 && aj+d < 8 ){
                    if( hh == 0 && board[ai][aj+d] != c ){
                        hh = 1;
                    }
                }
                if( aj + d < 0 || aj + d >= 8 ){
                    if( hh == 0 && board[ai][aj] == c ){
                        h = 0;
                        return -1;
                    }
                }
            }
        }
    }
    else{
        for( d = -1 ; d <= 1  && h == 0 ; d++){
            for( e = -1 ; e <= 1  && h == 0 ; e++ ){
                if( d != 0  &&  e != 0  &&  h == 0 ){
                    hh = 0 ;
                    if ( ai + e >= 0 && ai + e < 8 ){
                        while( board[ai+e][aj] == c  && hh == 0  &&  ai+e >= 0  &&  ai+e < 8  &&  aj >= 0  && aj < 8 ){
                            ai = ai + e;
                        }
                        if( ai + e >= 0 && ai+e < 8 ){
                            if( board[ai+e][aj] != c ){
                                hh = 1;
                            }
                        }
                    }
                    if( aj + d >= 0 && aj + d < 8 ){
                        while( board[ai][aj+d] == c  && hh == 0  &&  ai >= 0  &&  ai < 8  &&  aj+d >= 0  && aj+d < 8 ){
                            aj = aj + d;
                        }
                        if( aj+d >= 0 && aj+d < 8 ){
                            if( hh == 0 && board[ai][aj+d] != c ){
                                hh = 1;
                            }
                        }
                    }
                    while( board[ai+e][aj+d] == c  && hh == 0  &&  ai+e >= 0  &&  ai+e < 8  &&  aj+d >= 0  && aj+d < 8 ){
                        ai = ai + e;
                        aj = aj + d;
                    }
                    if( ai + e < 0  ||  ai + e >= 8 || aj + d < 0  ||  ai + d >= 8 ){
                        if( hh == 0 && board[ai][aj] == c ){
                            h = 1 ;
                            return -1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}