#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()

{
float vx;
float x;
float y;
float In_h;
float vy;
float t;
FILE* p;


    printf("Welcome to Projectile Computation\n");
      printf("What is the initial height?:\n");
    scanf("%f", &In_h);
    printf("\nWhat is the initial speed on the x axis?:\n");
    scanf("%f", &vx);
      printf("\nWhat is the initial speed on the y axis?:\n");
    scanf("%f", &vy);
    p = fopen("results printed version.txt", "w");
    printf("\nTime\t\tX Distance\tY Distance\n");
for (t= 0; t <=1000 ; t)
{
x = vx*t ;
y = In_h+((vy*t)+(t*t)*(-9.81));
if (y <= 0)
{
break;
}
printf("%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);
fprintf(p,"%1.2f\t\t%3.2f\t\t%4.3f \n\n", t, x, y);
t=t+0.05;
}
{
while (y >= 0);
fflush(p);
fclose(p);
}
printf("\nGoodbye from Projectile Computation!!\n");
return(0) ;
}
