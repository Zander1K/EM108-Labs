#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    char print='*';
int row, col;

for(row=1; row<=5; row++){
printf("**********\n");
}
printf("\n");


 for(row=10;row>0;--row){
    for(col=row;col>0;--col){
        printf("%c",print);
    }
    printf("\n");
 }
  printf("\n");

 for(row=0;row<11;++row){
    for(col=0;col<row;col++){
        printf("%c",print);
    }
printf("\n");



}
  }
