#include <stdio.h>

f_traffic_ticket(float km)
{
    float ticket;

    if(km >= 50 + (km * 0.1)){
        return 230;
    }
    else if(km >= 50 + (km * 0.2)){
        return 340;
    }
    else if(km > 50 + (km * 0.2)){
        while(50 + (km * 0.2) < km){
            ticket += 19.28;
            km -= 1;
        }
        return ticket;
    }
}

int main()
{
    float km;
    printf("Enter the speed in km/h: ");
    scanf("%f", &km);

    float traffic_ticket = f_traffic_ticket(km);

    printf("The traffic ticket is %.2f", traffic_ticket);
}