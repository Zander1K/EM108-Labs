#include <stdio.h>
#include <stdlib.h>
int main()
{
	float average, num1,num2 ,num3, product;


		printf("Welcome to Sum and Average Computation");
		printf("\nPlease enter num1: ");
		scanf("%f", &num1);
		printf("\nPlease enter num2: ");
		scanf("%f", &num2);
		printf("\nPlease enter num3: ");
		scanf("%f", &num3);

		if (num1>num2 && num1>num3)
		printf("\nThe Maximum Value is: %f\n", num1);

		if (num2>num1 && num2>num3)
		printf("\nThe Maximum Value is: %f\n", num2);

		if (num3>num1 && num3>num2)
		printf("\nThe Maximum Value is: %f\n", num3);

		if (num1<num2 && num1<num3)
		printf("\nThe Minimum Value is: %f\n", num1);

		if (num2<num1 && num2<num3)
		printf("\nThe Minimum Value is: %f\n", num2);

		if (num3<num1 && num3<num2)
		printf("\nThe Minimum Value is: %f\n", num3);



		average = (num1+num2+num3)/3;

		product = (num1*num2*num3);

		printf("\nThe Average is: %f\n", average);
		printf("\nThe Product of the three numbers are: %f\n", product);
		printf("\nThank you for using this Program, Goodbye");

return(EXIT_SUCCESS);
}
