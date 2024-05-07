//Henry Jones//
//Jordan Perone//
//Final Project//
#include <stdio.h>
void connectFile(char filename[],int* length, int* width, int arrayF[][length]);
int arrayFile(char filename[],int rows, int column, int arrayF[][column]);

void displayImage(int length, int width, char array[][width]);
void brightenImage(int length, int width, char array[][width]);
void dimImage(int length, int width, char array[][width]);
void cropImage(int length, int width, char array[][width]);
void saveImage(int length, int width, char array[][width], char* filename);

int menuChoice();
int editOptions();

int main(){
	char choice1, editChoice;
	char filename[30];
	int rows, uChoice, cols;\
	int arrayIn
	
	
	
	uChoice = menuChoice();
	
	if(uChoice == 1){
	
		connectFile(filename, &cols, &rows);
	
	
		printf("%d", rows);
		printf("%d", cols);
	
		

	}else if(uChoice == 2){
	
	
	
	
	}else if(uChoice == 3){
	
	
	editOptions();
	
	}else{
	
	printf("\nGoodbye!");
	return 0;
	
	}
	
	
	

return 0;
}
void connectFile(char filename[], int* length, int* width, int arrayF[][length]){
	char tempC [500], tempU;
	int col = 0, row = 0;
	int index = 0;
	int count = 0;
	
	
	printf("What is the name of the image file? ");
	scanf("%s", filename);
	FILE* fp;
	fp = fopen(filename, "r");
	
	
	if( fp == NULL){
		printf("\nCan't open file\n");
	}
	else{
		printf("\nImage successfully loaded!\n");
	
	}
	while(fscanf(fp, "%c", &tempC[index]) == 1){
		tempU = tempC[index];
		
		printf(" %c", tempU);
		if(tempU == '\n'){
			count++;
			row++;
		}else if(count < 1){
			
		col++;
			
		}
		index++;
	}
	fclose(fp);
	col--;
	
	*length = col;
	*width = row;
	
	col+2;
	row++;
	FILE* fpt;
	fpt = fopen(filename, "r");
	char tempA[row][col];
	
	if(fpt == NULL){
		printf("\nCan't open file\n");
	}
	
	
	for(int idxR = 0; idxR < row; idxR++){
		for(int idxC = 0; idxC < col; idxC++){
			fscanf(fp, "%c", &tempA[idxR][idxC]);
		
		}
	
	} 
	fscanf(fp, "%c", &tempA[row - 1][col]);
	
	for(int idxR = 0; idxR < row; idxR++){
	
		for(int idxC = 0; idxC < col; idxC++){
			printf("%c", tempA[idxR][idxC]);
		
		}
	
	} 
	
	printf("%c", tempA[row -1][col]);
	fclose(fpt);
	
	FILE* fptr;
	fptr = fopen("testing.txt", "w");
	
	if(fptr == NULL){
		printf("\nCan't open file\n");
	}
	
	
	for(int idxR = 0; idxR < row; idxR++){
		for(int idxC = 0; idxC < col; idxC++){
			fprintf(fptr, "%c ", tempA[idxR][idxC]);
		
		}
	
	} 
	
	fprintf(fptr, "%c", tempA[row-1][col]);
	
	fclose(fptr);
	
}
int arrayFile(char filename[],int rows, int column, int arrayF[][column]){
	
	int temp=0;
	
	FILE* fp = fopen(filename, "r");
	
	
	if( fp == NULL){
		printf("\nCan't open file\n");
	}
	else{
		printf("\nImage successfully loaded!\n");
	
	}

	for(int idxR = 0; idxR < rows; idxR++){
		for(int idxC = 0; idxC < column; idxC++){
			while(fscanf(fp,"%d", &arrayF[idxR][idxC]) == 1){
				printf(" %d", arrayF[idxR][idxC]);
			}
		}
	}

	fclose(fp);


}
void displayImage(int length, int width, char array[][width]){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			switch (array[i][j]){
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
void brightenImage(int length, int width, char array[][width]){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			if(array[i][j] == 48 || array[i][j] == 49 || array[i][j] == 50 || array[i][j] == 51 ){
				array[i][j] + 1;
			}
		}
	}
}
void dimImage(int length, int width, char array[][width]){
	for(int i = 0; i < length; i++){
		for(int j = 0; j < width; j++){
			if(array[i][j] == 52 || array[i][j] == 49 || array[i][j] == 50 || array[i][j] == 51 ){
				array[i][j] - 1;
			}
		}
	}
}
void cropImage(int length, int width, char array[][width]){
	int top, bottom, left, right;
	char choice;
	char topAxis[width + 1];
	printf(" ");
	for(int h = 0; h < width + 1; h++){
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
	for(int i = 0; i < length; i++){
		if(i % 4 == 0){
			printf("%d", i);
		} else{
			printf(" ");
		}
		for(int j = 0; j < width; j++){
			switch (array[i][j-1]){
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
			}
		}
		printf("\n");
	}
	printf("where would you like your top left corner to be(enter 2 numbers seperated by a space, enter the height first then how far left )\n");
	scanf("%d %d", &top, &left);
	printf("where would you like your bottom right corner to be(enter 2 numbers seperated by a space, enter the height first then how far right )\n");
	scanf("%d %d", &bottom, &right);
	for(int i = 0; i < length; i++){
		if(i >= top && i <= bottom){
			for(int j = 0; j < width; j++){
				if(j >= left && j <= right){
					switch (array[i][j]){
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
					}
				}
			}
			printf("\n");
		}
		
	}
	printf("keep changes?\n");
	scanf("%c", &choice);
	if (choice == 'y' || choice == 'Y'){
	for(int i = 0; i < length; i++){
		if(i < top || i > bottom){
			for(int j = 0; j < width; j++){
				if(j < left || j > right){
					array[i][j] == '0';
					}
				}
			}
		}
	}
}

void saveImage(int length, int width, char array[][width], char* filename){
	FILE * fp = fopen(filename, "w");
	char choice;
	printf("Would you like to save the image?\n");
	scanf(" %c", &choice);
	if(choice == 'y' || choice == 'Y'){
		for(int i = 0; i < length; i++){
			for(int j = 0; j < width; j++){
				fprintf(fp, " %c", array[i][j]);
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
