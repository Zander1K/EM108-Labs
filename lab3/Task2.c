#include <stdio.h>
#include <stdlib.h>
int main()
{
	float litres, width,length;


		printf("Welcome to the Weed Killing Computation");
		printf("\nPlease enter width of basin (in meters): ");
		scanf("%f", &width);
		printf("\nPlease enter length of basin(in metres): ");
		scanf("%f", &length);

		litres = (length*3.28*width*3.28);

		printf("\nThe Amount of Litres/Square feet required is: %f\n", litres);

		printf("Thank you for using this Program, Goodbye");

return(EXIT_SUCCESS);
}
