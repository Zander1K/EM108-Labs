#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure
typedef struct car {
int year;
char registration[9];
char colour[10];
float engine;
int tax;
} car_type;

int option;
int i;

void usermenu();
int tax(car_type cars[],int i);

car_type cars[6];

int main() {
// Opening Files
    char name[100];  /* name of the file to use  */
    FILE *in_file;    /* file for input */
    printf("Name of the File (e.g indata.txt) ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name)-1] = '\0';
    in_file = fopen(name, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Could not open file\n");
        exit(8);
    }
    for (i=0;i<6;i++)
{
  fscanf(in_file , "%d %s %s %f", &cars[i].year, cars[i].registration, cars[i].colour, &cars[i].engine);


// Car Taxation
}
printf("\n\nCar Taxation by Alexander Dare\n");
  usermenu();


fclose(in_file);
  return 0;
}

void usermenu() {
  FILE* outdata;
  outdata = fopen("outdata.txt", "w");

  printf("Please choose one of the options below:\n");
  printf("1.To print the results to the screen only, press 1\n");
  printf("2.To print the results to the file only, press 2\n");
  printf("3.To print the results to both the screen and file, press 3\n");
  scanf("%d", &option);

  switch(option){
    case 1:
      for (i=0; i<6; ++i){
        tax(cars,i);
        printf("\nThe tax on car %d is: €%.3d per year\n",i+1, cars[i].tax);
      }
      break;
    case 2:
      for (i=0; i<6; ++i){
        tax(cars,i);
        fprintf(outdata, "\nThe tax on car %d is: €%d\n",i+1, cars[i].tax);
      }
      break;
    case 3:
      for (i=0; i<6; ++i){
        tax(cars,i);
        printf("\nThe tax on car %d is: €%.3d per year\n",i+1, cars[i].tax);
        fprintf(outdata, "\nThe tax on car %d is: €%d\n",i+1, cars[i].tax);
      }
      break;
    default:
      printf("\n\nYou have made an illegal choice.\n");
      usermenu();
  }
  fclose(outdata);
}

int tax(car_type cars[],int i) {
  if(cars[i].year > 2014){
    if(cars[i].engine <= 1.6){
      cars[i].tax = 150;
    }
    else{
      cars[i].tax = 300;
    }
  }
  else{
    if(cars[i].engine < 1.4){
      cars[i].tax = 200;
    }
    else if(cars[i].engine > 1.6){
      cars[i].tax = 600;
    }
    else{
      cars[i].tax = 400;
    }
  }
  return cars[i].tax;
}
