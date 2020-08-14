#include <stdio.h>
#include <stdlib.h>
int main()
{
	float volume, depth, width,length, paint;


		printf("Welcome to the Water Basin Computation");
		printf("\nPlease enter depth of basin:_");
		scanf("%f", &depth);
		printf("\nPlease enter width of basin:_");
		scanf("%f", &width);
		printf("\nPlease enter length of basin:_");
		scanf("%f", &length);

		paint = (length*width + 2*length*depth + 2*width*depth);

		volume = (length*depth*width);

		printf("\nThe Volume is: %f\n", volume);
		printf("\nThe Amount of Paint Required is: %f\n", paint);
		printf("nThank you for using this Program, Goodbye");

return(EXIT_SUCCESS);
}