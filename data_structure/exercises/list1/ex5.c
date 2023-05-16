#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Coordenates{
    double x, y;
};
// formula da distancia euclidiana
double calculateDistance(struct Coordenates c1, struct Coordenates c2){
    double dx = c1.x - c2.x;
    double dy = c1.y - c2.y;
    return sqrt(dx * dx + dy * dy);
}
int main()
{
    int n, closerspot = 0;
    double shorterdistance = 0;
    printf("Enter the number of coordenates to be inserted: ");
    scanf("%d", &n);
    struct Coordenates *coordenate;
    struct Coordenates mediumspot;
    coordenate = (struct Coordenates *)calloc(n, sizeof(struct Coordenates));
    for(int i = 0; i < n; i++){
        printf("Enter coordenate %d: ", i);
        scanf("%lf %lf", &coordenate[i].x, &coordenate[i].y);
    }

    mediumspot.x = 0;
    mediumspot.y = 0;
    for(int i = 0; i < n; i++){
        mediumspot.x += coordenate[i].x;
        mediumspot.y += coordenate[i].y;
    }
    mediumspot.x /= n;
    mediumspot.y /= n;

    shorterdistance = calculateDistance(coordenate[0], mediumspot);

    for(int i = 0; i < n; i++){
        double distance = calculateDistance(coordenate[i], mediumspot);
        if(distance < shorterdistance){
            shorterdistance = distance;
            closerspot = i;
        }
    }
    free(coordenate);
    return 0;
}