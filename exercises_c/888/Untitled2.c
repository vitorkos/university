#include<stdio.h>
#include<math.h>

int delta(int a, int b, int c){
    return (b^2) - (4*a*c);
}
int raizx1(int a, int b, int delta){
    return (-b + sqrt(delta)) / (2*a);
}
int raizx2(int a, int b, int  delta){
    return (-b - sqrt(delta)) / (2*a);
}

int main(){
    int a, b, c;
    printf("insira o valor de a, b e c: ");
    scanf("%d%d%d", &a, &b, &c);

    if(a == 0){
        printf("não é uma funcao do segundo grau");
    }
    else{
        printf("as raizes da funcao sao %d e %d", raizx1, raizx2);
    }

    return 0;
}
