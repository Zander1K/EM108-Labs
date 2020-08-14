#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dvd_type_tag{
	char name[20];
	char cat[20];
	int  year;
	char code[20];
	float price;
	int disc;
}dvd_type;

typedef struct merch_type_tag{
	char name[20];
	char code[20];
	float price;
}merch_type;

int read_dvd_file(char* filename, dvd_type dvd[]);
int read_merch_file(char* filename, merch_type merch[]);
int get_discount(char* name, dvd_type dvd[], int size);
char* get_code(char* name, dvd_type dvd[], int size);
void apply_discount_to_merch(char* name, merch_type merch[], int size);
void apply_reduction(char* cat, int year, dvd_type dvd[], int size);
void write_file();
void print_screen(char* cat);

dvd_type dvd[100];  // maximum of 100 entries
merch_type merch[100];

int nodvd = 0; 		//number of dvds in the dvds.txt
int nomerch = 0;	//number of merchandise in merchs.txt

int main(){

	//This is what caused the problem. In the data structure they have fixed size, while here they don't
	//char* name; char* cat; char* code;
	//so, they should be declared as the following
	char name[20], cat[20], code[20];
	int ans = 1, year, disc;

	printf("Welcome to the program\n");

	while(ans != 6){
		printf("1. Read from files\n");
		printf("2. Apply discount to merchandise\n");
		printf("3. Apply reduction\n");
		printf("4. Write to file\n");
		printf("5. Print to screen\n");
		printf("6. Exit\n");

		printf("Enter your choice: \n");
		scanf("%d", &ans);

		switch(ans){
			case 1:
				if(nodvd == 0){
					nodvd = read_dvd_file("dvds.txt", dvd);
					nomerch = read_merch_file("merchs.txt", merch);
					printf("nodvd = %d\n", nodvd);
					printf("nomerch = %d\n", nomerch);
				}
				else
					printf("Data has already been read from the files\n");  // warning if data has already been read
				break;

			case 2:
				printf("Enter the movie name: \n");
				scanf("%s", name);
				disc = get_discount(name,dvd,nodvd);
				apply_discount_to_merch(name,merch,nomerch);
				break;
			case 3:
				printf("Enter the category and year: \n");
				scanf("%s %d", cat, &year);
				apply_reduction(cat,year,dvd,nodvd);
				break;
			case 4:
				write_file();
				break;
			case 5:
				printf("Enter Category: \n");
				scanf("%s", cat);
				print_screen(cat);
				break;
		}
	}
	printf("Goodbye!\n");
	return (EXIT_SUCCESS);

}

int read_dvd_file(char* filename, dvd_type dvd[]){
	FILE *fp;
	int i=0;
	char ch;

	//open the file
	fp = fopen(filename, "r");

	//read line by line
	while(!feof(fp)){
	 	fscanf(fp, "%s%c%s%c%d%c%f%c%s%c%d%c",
		 dvd[i].cat, &ch,
		 dvd[i].name, &ch,
		 &dvd[i].year, &ch,
		 &dvd[i].price, &ch,
		 dvd[i].code, &ch,
		 &dvd[i].disc, &ch);


		 i++;
	}
	fclose(fp);

	return i;
}

int read_merch_file(char* filename, merch_type merch[]){
	FILE *fp;
	int i=0;
	char ch;

	//open the file
	fp = fopen(filename, "r");

	//read line by line
	while(!feof(fp)){
	 	fscanf(fp, "%s%c%s%c%f%c",
		 merch[i].code, &ch,
		 merch[i].name, &ch,
		 &merch[i].price, &ch);

		 i++;
	}
	fclose(fp);

	return i;
}

int get_discount(char* name, dvd_type dvd[], int size){
	int i;
	int disc = 0;
	for(i=0; i<size; i++){
		if(strcmp(dvd[i].name, name) == 0){
			disc = dvd[i].disc;
			break;
		}
	}
	return disc;

}

char* get_code(char* name, dvd_type dvd[], int size){
	char* code;
	int i;
	for(i=0;i<size;i++){
		if(strcmp(dvd[i].name, name) == 0){
			code = dvd[i].code;
			break;
		}
	}
	return code;
}

void apply_discount_to_merch(char* name, merch_type merch[], int size){
	int disc = get_discount(name,dvd,nodvd);
	//I removed the line below and add it to line 173 in the if statement
	//char* code = get_code(name,dvd,nodvd);

	int i;
	for(i=0; i<size; i++){
		if(strcmp(merch[i].code, get_code(name,dvd,nodvd)) == 0)
			merch[i].price = merch[i].price - ((merch[i].price*disc)/100);
	}
	printf("Discout applied to merchandise\n");
}

void apply_reduction(char* cat, int year, dvd_type dvd[], int size){
	int i;
	for(i=0;i<size;i++){
		if(strcmp(dvd[i].cat,cat)==0){
			if(dvd[i].year < year)
				dvd[i].disc += 50;
			else
				dvd[i].disc += 20;
			printf("Reduction has been applied to %s\n", dvd[i].name);
		}
		else if(dvd[i].year < year){
			dvd[i].disc += 30;
			printf("Reduction has been applied to %s\n", dvd[i].name);
		}
	}
}

void write_file(){
	FILE *fp;
	int i;
	char* filename;

	printf("Enter file name: \n");
	scanf("%s", filename);

	fp = fopen(filename, "w");

	for(i=0;i<nodvd;i++)
		fprintf(fp, "%s %s %d %.2f %.2f\n",
		dvd[i].name, dvd[i].cat, dvd[i].year, dvd[i].price, dvd[i].price - ((dvd[i].price*dvd[i].disc)/100));

		fflush(fp);
		fclose(fp);
}

void print_screen(char* cat){
	int i;
	printf("Name			Year			Price			Dist. Price\n");
	for(i=0;i<nodvd;i++){
		if(strcmp(dvd[i].cat,cat) == 0)
			printf("%s			%d			%.2f			%.2f\n",
		dvd[i].name, dvd[i].year, dvd[i].price, dvd[i].price - ((dvd[i].price*dvd[i].disc)/100));
	}
}
