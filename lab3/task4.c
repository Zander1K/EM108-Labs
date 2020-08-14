#include <stdio.h>
#include <stdlib.h>
int main()
{

float sum, average, product;
int i, n;
float nums[20];

printf("Welcome to Sum and Average computation!");
printf("\nEnter the number of numbers (n < 20): ");
scanf("%d", &n);

product=1;
for (i = 0; i < n; i++)
{

printf("\nEnter the %d-th number: ");
scanf("%f", &nums[i]);
}

sum = 0;

for (i = 0; i < n; i++)
{

sum += nums[i];
product *=  nums[i];
}

average = sum / n;
printf("\nThe average is: %f\n", average);

printf("\nThe sum is: %f\n",sum);


printf("\nThe product is: %f\n", product);
printf("\nThank you for using this Program, Goodbye");


return(EXIT_SUCCESS);

}
