//Henry Jones//
//Jordan Perone//
//Final Project//
#include <stdio.h>
#define MAX 150
void connectFile(char filename[],int* rows, int* cols);
int arrayFile(char filename[],int rows, int cols, char arrayF[][MAX]);
void rotateImage(int rows, int cols, char arrayF[][MAX], char filename[]);
void displayImage(int rows, int cols, char arrayF[][MAX]);
void brightenImage(int rows, int cols, char arrayF[][MAX], char filename[]);
void dimImage(int rows, int cols, char arrayF[][MAX], char filename[]);
void cropImage(int rows, int cols, char arrayF[][MAX], char filename[]);
void saveImage(int rows, int cols, char arrayF[][MAX], char filename[]);

int menuChoice();
int editOptions();

int main(){
	char choice1, editChoice, uChoice;
	char filename[30];
	int rows, cols;
	uChoice = 1;
	char arrayF[MAX][MAX];
	int quit = 0;
	int trueConnect = 0;
	while( uChoice != '4'){
	uChoice = menuChoice();
	if(uChoice == '1'){
		connectFile(filename, &cols, &rows);
		arrayFile(filename, rows, cols, arrayF);
		trueConnect = 1;
	}else if(uChoice == '2'){
	char editChoice;
	editChoice = editOptions();
		while (editChoice != 0){
		if (trueConnect == 0){
			printf("No file connected\n");
			editChoice = 0;
		}
		else if(editChoice == 1){
			dimImage(rows,cols, arrayF, filename);
			editChoice = 0;
		}
		else if (editChoice == 2){
			brightenImage(rows, cols, arrayF, filename);
			editChoice = 0;
		}
		else if (editChoice == 3){
			cropImage(rows, cols, arrayF, filename);
			editChoice = 0;
		}
		else if (editChoice == 4){
		rotateImage(rows, cols, arrayF, filename);
		editChoice = 0;
		
		}
		if (editChoice == 0){
		editChoice = 0;
		}
	
	}
	}else if(uChoice == '3'){
		if (trueConnect == 1){
			displayImage(rows,cols,arrayF);
		}
		else if(trueConnect == 0){
			printf("No image connected\n");
		}
	}
	else if(uChoice != '1' && uChoice != '2' && uChoice != '3' && uChoice != '4') {
		printf("INVALID CHOICE\n");
		uChoice = 1;
	}
	}
printf("Goodbye");
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
	col++;
	*cols = col;
	(*rows)++;
	i = *cols;
	j = *rows;
	*cols = j;
	*rows = i;
	
	fclose(fp);
}
int arrayFile(char filename[],int rows, int cols, char arrayF[][MAX]){
	FILE* fp = fopen(filename, "r");
	char temp[MAX][MAX];
	int i =0;
	int j =0;
	
	
	if( fp == NULL){
		printf("\nCan't open file\n");
	}
	while(fscanf(fp, "%c", &temp[i][j]) == 1){
		if(temp[i][j] == '\n'){
			arrayF[i][j] = '\n';
			i++;
			j = 0;
		}
		else if(temp[i][j] != ' '){
			arrayF[i][j] = temp[i][j];
			j++;
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
void brightenImage(int rows, int cols, char arrayF[][MAX], char filename[]){
	char brightArray[MAX][MAX];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(arrayF[i][j] >= 48 && arrayF[i][j] < 52 ){
				brightArray[i][j] = arrayF[i][j];
				arrayF[i][j]++;
			}
		}
	}
	displayImage(rows,cols,arrayF);
	char choice3;
	printf("Would you like to save the image?(enter y for yes)\n");
	scanf(" %c", &choice3);
	if(choice3 == 'y' || choice3 == 'Y'){
		saveImage(rows, cols, arrayF, filename);
	}else{
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				arrayF[i][j] = brightArray[i][j];
			}
		}
	}
}
void dimImage(int rows, int cols, char arrayF[][MAX], char filename[]){
	char choice3;
	char dimArray[MAX][MAX];
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(arrayF[i][j] >= 49 && arrayF[i][j] <= 52) {
				dimArray[i][j] = arrayF[i][j];
				arrayF[i][j]--;
			}
		}
	}
	displayImage(rows,cols,arrayF);
	printf("Would you like to save the image?(enter y for yes)\n");
	scanf(" %c", &choice3);
	if(choice3 == 'y' || choice3 == 'Y'){
		saveImage(rows, cols, arrayF, filename);
	}else{
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
					arrayF[i][j] = dimArray[i][j];
			}
		}
	}
}
void cropImage(int rows, int cols, char arrayF[][MAX], char filename[]){
	char choice1;
	while (choice1 != 0){
		char choice;
		int top, bottom, left, right;
		char topAxis[cols + 1];	
		printf(" ");
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
			if( i % 4 == 0){
				printf("%d", i);
			}
			else{
				printf(" ");
			}
			for(int j = 0; j < cols + 1; j++){
				switch (arrayF[i][j-1]){
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
		printf("where would you like your top left corner to be(enter 2 numbers seperated by a space, enter the height first then how far left )\n");
		scanf("%d %d", &top, &left);
		printf("where would you like your bottom right corner to be(enter 2 numbers seperated by a space, enter the height first then how far right )\n");
		scanf("%d %d", &bottom, &right);
		for(int i = top; i <= bottom; i++){
			for(int j = left; j <= right; j++){
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
				}
			}
		printf("\n");
		}
		printf("keep changes (Y)es or (N)o?\n");
		scanf(" %c", &choice);
		if (choice == 'y' || choice == 'Y'){
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols - 1; j++){
				if(i < top || i > bottom || j < left || j > right + 1){
					arrayF[i][j] = '0';
				}
			}
		}
		saveImage(rows, cols, arrayF, filename);
		choice1 = 0;	
		}
		else{
			choice1 = 0;
		}
	}		
}

void saveImage(int rows, int cols, char arrayF[][MAX], char filename[]){
	FILE * fp = fopen(filename, "w");
	int exitCond = 1;
	while(exitCond != 0){
		for(int i = 0; i < rows - 1; i++){
			for(int j = 0; j < cols - 1; j++){
				fprintf(fp, "%c", arrayF[i][j]);
			}
		fprintf(fp, "\n");
		}
	exitCond = 0;
	}
	
fclose(fp);
}
int menuChoice(){
	char choice1;
	printf("Welcome to photo editor, what would you like to do\n");
	printf("[1] Load image\n");
	printf("[2] Edit image\n");
	printf("[3] Display image\n");	
	printf("[4] Exit\n");	
	printf("Please enter your choice: \n");
	scanf(" %c", &choice1);
	while(getchar() != '\n');
	return choice1;
}
int editOptions(){
	int editChoice;
	
	printf("How would you like to edit the image\n");
	printf("[1] Dim image\n");
	printf("[2] Brighten image\n");
	printf("[3] Crop image\n");	
	printf("[4] Rotate image\n");
	printf("[0] Exit\n");	
	printf("Please enter your choice: \n");
	scanf("%d", &editChoice);
	return editChoice;
}
void rotateImage(int rows, int cols, char arrayF[][MAX], char filename[]){
	FILE * fp = fopen(filename, "w");
	int quitCond = 1;
	while(quitCond != 0){
		char rotateArray[MAX][MAX];
		int choice;
		char choice9;
		printf("how would you like to rotate the image?\n[1]90 degrees\n[2]180 degrees\n[3]270 degrees\n");
		scanf("%d", &choice);
		if (choice == 1){
			for(int i = 0; i < cols; i++){
				for (int j = rows - 1; j >= 0; j--){
					switch (arrayF[j][i]){
						case '0':
							printf(" ");
							rotateArray[i][j] = '0';
						break;
						case '1':
							printf(".");
							rotateArray[i][j] = '1';
							break;
						case '2':
							printf("o");
							rotateArray[i][j] = '2';
							break;
						case '3':
							printf("O");
							rotateArray[i][j] = '3';
							break;
						case '4':
							printf("0");
							rotateArray[i][j] = '4';
							break;
					}
					
				}
				printf("\n");
			}
			printf("Would you like to save the image?\n");
			scanf(" %c", &choice9);
			if(choice9 == 'y' || choice9 == 'Y'){
				for(int i = 0; i < rows; i++){
					for(int j = 0; j < cols; j++){
						fprintf(fp, " ");
					}
				}
				rewind(fp);
				for(int i = 0; i < cols - 1; i++){
					for (int j = 0; j < rows - 1; j++){
						fprintf(fp, "%c", rotateArray[i][j]);
					}
				fprintf(fp, "\n");
				}
			}else{
				fclose(fp);
			}
		}
		else if(choice == 2){
		int a = 0, b = 0;
			for(int i = rows; i > -1; i--){
				for (int j = cols - 1; j > -1; j--){
					switch (arrayF[i][j]){
						case '0':
							printf(" ");
							rotateArray[a][b] = '0';
						break;
						case '1':
							printf(".");
							rotateArray[a][b] = '1';
							break;
						case '2':
							printf("o");
							rotateArray[a][b] = '2';
							break;
						case '3':
							printf("O");
							rotateArray[a][b] = '3';
							break;
						case '4':
							printf("0");
							rotateArray[a][b] = '4';
							break;
					}
					b++;
				}
				printf("\n");
				a++;
				b = 0;
			}
			printf("Would you like to save the image?\n");
			scanf(" %c", &choice9);
			if(choice9 == 'y' || choice9 == 'Y'){
				for(int i = 0; i < rows; i++){
					for(int j = 0; j < cols; j++){
						fprintf(fp, " ");
					}
				}
				for(int i = 0; i < rows - 1; i++){
					for (int j = 0; j < cols; j++){
						fprintf(fp, "%c", rotateArray[i][j]);
					}
				fprintf(fp, "\n");
				}
			}else{
				fclose(fp);
			}
		}
		else if(choice == 3){
			for(int i = cols - 1; i > -1; i--){
				for (int j = 0; j < rows; j++){
					switch (arrayF[j][i]){
						case '0':
							printf(" ");
							rotateArray[i][j] = '0';
						break;
						case '1':
							printf(".");
							rotateArray[i][j] = '1';
							break;
						case '2':
							printf("o");
							rotateArray[i][j] = '2';
							break;
						case '3':
							printf("O");
							rotateArray[i][j] = '3';
							break;
						case '4':
							printf("0");
							rotateArray[i][j] = '4';
							break;
					}
					
				}
				printf("\n");
			}
			printf("Would you like to save the image?\n");
			scanf(" %c", &choice9);
			if(choice9 == 'y' || choice9 == 'Y'){
				for(int i = 0; i < rows; i++){
					for(int j = 0; j < cols; j++){
						fprintf(fp, " ");
					}
				}
				for(int i = 0; i < cols; i++){
					for (int j = 0; j < rows; j++){
						fprintf(fp, "%c", rotateArray[i][j]);
					}
				fprintf(fp, "\n");
				}
			}else{
				fclose(fp);
			}
		}
	quitCond = 0;
	}
fclose(fp);
}	

