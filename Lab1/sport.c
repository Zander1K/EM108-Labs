#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
 char name[100];
 printf("Welcome to SPORT ...\n");
  printf("Your Favourite Sport?:\n");
  scanf("%s", name);
  if(strcmp(name, "Basketball") == 0)
  printf("Good Choice, %s. I love Basketball!\n", name);
  else
  printf("What!!!, %s.? Not Good Enough! I only like Basketball\n", name);
  printf("Bye from SPORT ...\n");
 return(EXIT_SUCCESS);
}