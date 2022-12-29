//certo

#include<stdio.h>

int main(){
    int x , y = 0 ;
    int *p = &y ;
    x = *p ;
    x = 10;
    (*p )++;
    x--;
    printf( "%d\n" , *p ) ;
    (*p ) += x ;
    printf( "%d\n" , y ) ;
    printf( "%d\n" , &x == p ) ;
    return 0 ;
}