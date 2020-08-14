#include <stdio.h>
#include <stdlib.h>

int main()
{
    int clients, x;
    float average, total;

    printf("Welcome to the Soccer Tickets computation");
    printf("\nEnter The number of clients: ");
    scanf("%d", &clients);
    int tickets[clients];
    for(x=0;x<clients;x++){
    printf("How many Tickets did Client %d buy:",x+1);
    scanf("%d",&tickets[x]);
    total = total + tickets[x];
}
printf("CLIENT NO    NO.TICKETS\n");
	for(x=0; x<clients;x++){
		printf("    %d       ",x+1);printf("      %d\n",tickets[x]);
	}
	average = total/clients;
	printf("The average number of tickets bought is: %.2f",average);
	printf("\nThank you for using my program\n");

return(0);
}
