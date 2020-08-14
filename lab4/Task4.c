#include <stdio.h>
int main(void)
{
    char text[100], t;
    int i, key;

    printf("What text would you like to encrypt: ");
    gets(text);
    printf("Enter key: ");
    scanf("%d", &key);

    for(i=0; text[i]; i++){
        t = text[i];

        if(t >= 'a' && t <= 'z'){
			t = t + key;

			if(t > 'z'){
				t = t - 'z' + 'a' - 1;
			}

			text[i] = t;
		}
		else if(t >= 'A' && t <= 'Z'){
			t = t + key;

			if(t > 'Z'){
				t = t - 'Z' + 'A' - 1;
			}

			text[i] = t;
		}
	}

	printf("Encrypted text: %s", text);

	return 0;

}
