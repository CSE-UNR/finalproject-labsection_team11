//Henry Jones//
//Final Project//
#include <stdio.h>
void connectFile(char* filename,int* length, int* width);
char getArray(char *filename, int length, int width, char array[][width]);
int getWidth(FILE * fp);
int getLength(FILE * fp);
void displayImage(int length, int width, char array[][width]);
void brightenImage(int length, int width, char array[][width]);
void dimImage(int length, int width, char array[][width]);
void cropImage(int length, int width, char array[][width]);
void saveImage(int length, int width, char array[][width], char* filename);
char menuChoice(char choice1);
char editOptions(char editChoice);

int main(){
	char choice1, editChoice;
	char filename[30];
	int length;
	int width;
	char array[length][width];
	connectFile(filename, &length, &width);
	
	printf("width: %d, length:%d\n",width, length);
	getArray(filename,length,width,array);
	displayImage(length,width,array);

return 0;
}
void connectFile(char* filename,int* length, int* width){
	printf("Enter the file name\n");
	scanf("%s", filename);
	FILE * fp = fopen(filename, "r");
	if( fp == NULL){
		printf("Can't open file\n");
	}
	else{
		printf("Image found\n");
	*width = getWidth(fp);
	*length = getLength(fp);
	fclose(fp);
}
}
int getLength(FILE * fp) {
	int length = 0;
	char a;
	while (fscanf(fp, "%c", &a) == 1) {
		if (a == '\n') { 
			length++;
		}
	}
	rewind(fp);
	return length + 1;
}
int getWidth(FILE * fp){
	int width = 0;
	char c;
	while(fscanf(fp, "%c", &c) == 1){
		if(c == '\n'){
			break;
		}
		else{ 
			width++;
		}
	}
		rewind(fp);
	return width + 1;
}
char getArray(char* filename, int length, int width, char array[][width]){
	FILE * fp = fopen(filename, "r");
	if( fp == NULL){
		printf("Can't open file\n");
	}
	else{
		printf("connected\n");
		for(int i = 0; i < length; i++){
			for(int j = 0; j < width; j++){
				fscanf(fp, "%c", &array[i][j]);
			}
			
		}
	}
	fclose(fp);
	printf("\n");
	return array[length][width];
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
char menuChoice(char choice1){
	printf("Welcome to photo editor, what would you like to do\n");
	printf("[O]pen image\n");
	printf("[E]dit image\n");
	printf("[V]iew image\n");	
	printf("[Q]uit\n");	
	printf("Please enter your choice: \n");
	scanf(" %c", &choice1);
	if (choice1 == 'Q'){
		choice1 = 'q';
	}
	return choice1;
}
char editOptions(char editChoice){
	printf("How would you like to edit the image\n");
	printf("[D]im image\n");
	printf("[B]righten image\n");
	printf("[C]rop image\n");	
	printf("[Q]uit\n");	
	printf("Please enter your choice: \n");
	scanf(" %c", &editChoice);
	return editChoice;
}
