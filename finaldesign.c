//Henry Jones//
//Jordan Perone//
//Final Project//
#include <stdio.h>
#define MAX 150
void connectFile(char filename[],int* rows, int* cols);
int arrayFile(char filename[],int rows, int cols, char arrayF[][MAX]);

void displayImage(int rows, int cols, char arrayF[][MAX]);
void brightenImage(int rows, int cols, char arrayF[][MAX]);
void dimImage(int rows, int cols, char arrayF[][MAX]);
void cropImage(int rows, int cols, char arrayF[][MAX]);
void saveImage(int rows, int cols, char arrayF[][MAX], char* filename);

int menuChoice();
int editOptions();

int main(){
	char choice1, editChoice;
	char filename[30];
	int rows, uChoice, cols;
	uChoice = 1;
	char arrayF[MAX][MAX];

	while( uChoice != 0){
	uChoice = menuChoice();
	
	if(uChoice == 1){
	
		connectFile(filename, &cols, &rows);
		arrayFile(filename, rows, cols, arrayF);
		for (int idxR = 0; idxR < rows; idxR++) {
			for (int idxC = 0; idxC < cols; idxC++) {
				printf("%c", arrayF[idxR][idxC]);
			}
		}
	}else if(uChoice == 2){
	char editChoice;
	editChoice = editOptions();
		while (editChoice != 0){
		if(editChoice == 1){
			dimImage(cols,rows, arrayF);
			displayImage(rows,cols,arrayF);
			editChoice = 0;
		}
		else if (editChoice == 2){
		brightenImage(rows, cols, arrayF);
		displayImage(rows,cols,arrayF);
		editChoice = 0;
		}
		else if (editChoice == 3){
		cropImage(rows, cols, arrayF);
		displayImage(rows,cols,arrayF);
		}
		else if (editChoice == 4){
		
		}
		if (editChoice == 0){
		
		}
	
	}
	}else if(uChoice == 3){
		displayImage(rows,cols,arrayF);
	
	
	
	}else{
	
	printf("\nGoodbye!");
	return 0;
	
	}
	}
	
	

return 0;
}
void connectFile(char filename[], int* rows, int* cols){
	char tempC [500], tempU;
	int col = 0;
	int index = 0;
	int count = 0;
	int i = 0, j = 0;
	
	
	printf("What is the name of the image file? ");
	scanf("%s", filename);
	FILE* fp = fopen(filename, "r");
	
	
	if( fp == NULL){
		printf("\nCan't open file\n");
	}
	else{
		printf("\nImage successfully loaded!\n");
	
	}
	while(fscanf(fp, "%c", &tempC[index]) == 1){
		if(tempC[index] == '\n'){
			(*rows)++;
			count = 0;
		}
		if (col < count){
				col = count;
			}
	count++;
	index++;
	}
	*cols = col;
	(*rows)++;
	i = *cols;
	j = *rows;
	*cols = j;
	*rows = i;
	
	fclose(fp);
}
int arrayFile(char filename[],int rows, int cols, char arrayF[][MAX]){
	printf("%d, %d", rows, cols);
	FILE* fp = fopen(filename, "r");
	
	
	if( fp == NULL){
		printf("\nCan't open file\n");
	}
	else{
		printf("\nImage successfully loaded!\n");
	
	}
		for (int idxR = 0; idxR < rows; idxR++) {
			for (int idxC = 0; idxC < cols; idxC++) {
				fscanf(fp, "%c", &arrayF[idxR][idxC]);
				
            		}	
		}
	for (int idxR = 0; idxR < rows; idxR++) {
		for (int idxC = 0; idxC < cols; idxC++) {
			printf("%c", arrayF[idxR][idxC]);
		}
	}
	fclose(fp);
}
void displayImage(int rows, int cols, char arrayF[][MAX]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			switch (arrayF[i][j]){
				case '0':
					printf(" ");
					break;
				case '1':
					printf(".");
					break;
				case '2':
					printf("o");
					break;
				case '3':
					printf("O");
					break;
				case '4':
					printf("0");
					break;
				case '\n':
					printf("\n");
					break;
			}
		}
	}
}
void brightenImage(int rows, int cols, char arrayF[][MAX]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(arrayF[i][j] == 48 || arrayF[i][j] == 49 || arrayF[i][j] == 50 || arrayF[i][j] == 51 ){
				arrayF[i][j] + 1;
			}
		}
	}
}
void dimImage(int rows, int cols, char arrayF[][MAX]){
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(arrayF[i][j] > '0' && arrayF[i][j] < '5') {
				arrayF[i][j]--;
			}
		}
	}
}
void cropImage(int rows, int cols, char arrayF[][MAX]){
	int top, bottom, left, right;
	char choice;
	char topAxis[cols + 1];	
	for(int h = 0; h <= cols + 1; h++){
		if( 0 == h % 4){
			printf("%d", h);
		}
		else if(h % 15 ==0 || h % 19 == 0){
		}
		else{
			printf(" ");
		}
	}
	printf("\n");
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			switch (arrayF[i][j]){
				case '0':
					printf(" ");
					break;
				case '1':
					printf(".");
					break;
				case '2':
					printf("o");
					break;
				case '3':
					printf("O");
					break;
				case '4':
					printf("0");
					break;
				case '\n':
					if(i % 4 == 0){
					printf("\n%d", i);
					}
					else{
						printf("\n");
					}
					break;
			}	
		}
	}
	printf("where would you like your top left corner to be(enter 2 numbers seperated by a space, enter the height first then how far left )\n");
	scanf("%d %d", &top, &left);
	printf("where would you like your bottom right corner to be(enter 2 numbers seperated by a space, enter the height first then how far right )\n");
	scanf("%d %d", &bottom, &right);
	int iCount = 0;
	int t;
	for(int i = top; i <+ bottom; i++){
			for(int j = left; j <= right; j++){
					t = j - iCount;
					switch (arrayF[i][t]){
						case '0':
							printf(" ");
							break;
						case '1':
							printf(".");
							break;
						case '2':
							printf("o");
							break;
						case '3':
							printf("O");
							break;
						case '4':
							printf("0");
							break;
						case '\n':
							printf("\n");
						break;
					}
				}
			iCount++;
			printf("\n");
			}
			
			
				
					
			
	
	printf("keep changes?\n");
	scanf(" %c", &choice);
	if (choice == 'y' || choice == 'Y'){
	for(int i = 0; i < rows; i++){
		if(i < top || i > bottom){
			for(int j = 0; j < cols; j++){
				if(j < left || j > right){
					arrayF[i][j] == '0';
					}
				}
			}
		}
	}
}

void saveImage(int rows, int cols, char arrayF[][MAX], char* filename){
	FILE * fp = fopen(filename, "w");
	char choice;
	printf("Would you like to save the image?\n");
	scanf(" %c", &choice);
	if(choice == 'y' || choice == 'Y'){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				fprintf(fp, " %c", arrayF[i][j]);
			}
		}
	}
}
int menuChoice(){
	int choice1 = 0;
	printf("Welcome to photo editor, what would you like to do\n");
	printf("[1] Load image\n");
	printf("[2] Edit image\n");
	printf("[3] Display image\n");	
	printf("[0] Exit\n");	
	printf("Please enter your choice: \n");
	scanf("%d", &choice1);
	return choice1;
}
int editOptions(){
	int editChoice;
	
	printf("How would you like to edit the image\n");
	printf("[1] Dim image\n");
	printf("[2] Brighten image\n");
	printf("[3] Crop image\n");	
	printf("[0] Exit\n");	
	printf("Please enter your choice: \n");
	scanf("%d", &editChoice);
	return editChoice;
}
