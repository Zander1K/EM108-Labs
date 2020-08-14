#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <unistd.h>

int input()
{

   char choice[5];

 int cpu, odd, even;
    printf("\n\nWould you like to be odd or even?\n");
    scanf("%s", &choice);
    if (strcmp(choice, "odd")==0)
    {
        return 1;

    }
    else {
    return 2; }
     if (strcmp(choice, "odd")==0) cpu==even;
if (strcmp(choice, "even")==0) cpu==odd;
}



int main()
{
printf("\nRules:\n1. Pick whether being an odd or even Player\n2. You will then pick a number between 1 to 10 and the CPU will also pick a random number\n3. If the sum of the numbers is even and you are an even player and vice versa, you win the round and get 2 points\n4. The game ends when a player reaches 6 points\n");

 int  i,j, r, a, b,e=0, cont, points_computer=0, points_player=0,c[6]={0};
 int cpu_array[6]={0};
 int pl=0,cl=0, ep=0, ec=0;



   j=input();
     for(j=0; j<6;j++)
     {

         sleep(1);
         printf("\nThe Round will begin in 3 seconds");
         printf("\n3");
         sleep(1);
         printf("\n2");
         sleep(1);
         printf("\n1");
         sleep(1);

   printf("\n\nEnter a number between 1 and 10\n");
   scanf("%d", &c[j]);

   sleep(1);
srand(time(NULL));
rand();
int cpu;
cpu = rand() %10+1;
    printf("The cpu has picked: %d\n", cpu);
    cpu_array[j] = cpu;
    sleep(1);
 r= (c[j] + cpu);


    a= (r-c[j]);
       b= (r-cpu);

 {if (a<b)
       {
       points_player+=1;
       printf("\nplayer has won an extra point\n");
       ep++;
       }
      else if (b<a)
       {
       points_computer+=1;
       printf("\ncomputer has won an extra point\n");
       ec++;
       }
 }
 int winner;
   if (r%2 == 0) {
       printf(" Sum is even\n");


         if (i==1) {
                points_computer+= 2;
                winner = printf("Computer has won this round");
                printf("\ncomputer has 2 points\n");
                cl++;
        }else {
            points_player+= 2;
            winner = printf("Player has won this round");
            printf("\nplayer has 2 points\n");
            pl++;
            }

   }
   else {
      printf("Sum is odd\n");
       if (i==1) {
                points_player+= 2;
                winner = printf("\nPlayer has won this round");
                 printf("\nplayer has 2 points\n");
                 pl++;
            } else {
            points_computer+= 2;
            winner = printf("\nComputer has won this round");
            printf("\ncomputer has 2 points\n");
            cl++;
            }
   }
   if (points_computer>=6) {
    printf("\ncomputer has won the game\n");
    break;
   }
   else if (points_player>=6) {
       printf("\nplayer has won the game\n");

       break;
   }


}
printf("\n\nEven and Odd Numbers Picked by the Player:\n");
for (i=0; i<4; i++)
{
    printf("%d \n", c[i]);

}

printf("\n\nEven and Odd Numbers Picked by the CPU:\n");
for (i=0; i<4; i++)
{
    printf("%d \n", cpu_array[i]);

}
printf("\n\nThe Rounds won by the User is: %d", pl);
printf("\nThe Rounds lost by thr CPU is: %d", cl);
printf("\nThe Amount of Extra Points won by the User is: %d", ep);
printf("\nThe Amount of Extra Points won by the User is: %d", cl);

printf("\n");
    for (;;)
    {
      printf("Continue [YN]? ");
      cont = toupper(getchar());
      if (cont == 'Y')
          return main();
      else if (cont == 'N')
          return EXIT_SUCCESS;
    }
}
