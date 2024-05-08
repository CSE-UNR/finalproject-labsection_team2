// Benny Padilla and Connor Lindloff
// final group project
// 04/29/24
#include<stdio.h>
#define COL 500
#define ROW 500
#define SIZE 50
void menu();
void load_image(FILE*stream, int row, int cols, char data[][COL]);
void display(int row, int col, char imageLetter[][COL]);
void brightdim(int row, int col, char modfiyImage[][COL]);
void editmenu();
void crop(int row, int col, char ogImage[][COL]);
int main(){
	int choice, choiceedit;
	char FILENAME[SIZE], temp;
	int rowQty = 0, col_i = 0, colCounter = 0, rowSize = 0;
	char image[ROW][COL];
	FILE* fptr;
	do{
	
		menu();
		printf("choose from one of the options above:");
		scanf("%d", &choice);
		switch(choice){
			case 1:
			// Go to load image---------------------------------------------------------------
				printf("what is the name of the image file? ");
				scanf("%s", FILENAME);
				fptr = fopen(FILENAME,"r");
				if (fptr == NULL){
					printf("File Open Failed");
					return 0;
				}
				while(fscanf(fptr, "%c", &temp) == 1){
					image[rowQty][col_i] = temp;
					if(temp == '\n'){
						rowQty++;
						colCounter = col_i;
						col_i = 0;
					}
					else{
						col_i++;
					}
				}	
				fclose(fptr);
				//--------------------------------------------------------------------
				// our rowSize is numbers of colmuns we have
				//rowSize = colCounter/ rowQty; 
				printf("row size %d\n", rowQty);
				printf("col size %d\n", colCounter);
				//fptr = fopen(FILENAME,"r");
				//load_image(fptr,rowQty, rowSize, image);
					
				//fclose(fptr);
				printf("Image successfully loaded!\n");
				
				break;
			case 2:
				display(rowQty,colCounter, image);
				break;
			case 3:
				editmenu();
				printf("choose from one of the options above:");
				scanf("%d", &choiceedit);
				
					switch (choiceedit){
						case 1:
							brightdim(rowQty, colCounter, image);
							break;
						case 2:
							crop(rowQty,colCounter, image);
							break;
						case 3:
							break;
						
					}
				break;
			case 0:
				break;
		
		
		}
	} while (choice != 0);
	
	
		
	
	return 0;
}
//main menu
void menu(){
printf("1: Load image\n");
printf("2: Display image\n");
printf("3: Edit image\n");
printf("0: Exit\n");

}
//edit menu
void editmenu(){
printf("1: Brigten or Dim\n");
printf("2: Crop\n");
printf("3: Exit\n");

}
//load image
void load_image(FILE*stream, int row, int cols, char data[][COL]){
char temp;
for(int i = 0; i < row; i++){
            for(int j = 0; j < cols; j++){
                if(fscanf(stream, "%c", &temp) == 1){
                    data[i][j] = temp;
                    }
                    else{ // Handles the end of file value
                    data[i][j] = '\n';
                    }
                    }

}
}
//display image 
void display(int row, int col, char imageNumber[][COL]){

//char imageLetter[row][col];

//printf("\n");

//for(int i = 0; i <= row; i++){
//	for(int j = 0; j <= col; j++){
  //                printf("%c", imageNumber[i][j]);
    //	}
        	
//}
 //printf("\n");

for(int i = 0; i <= row; i++){
	for(int j = 0; j <= col; j++){
		//imageLetter[i][j] = imageNumber[i][j];
		switch( imageNumber[i][j]){
			case '0':
                    		imageNumber[i][j] = ' ';
                    		break;
                    	case '1': 
                    		imageNumber[i][j] = '.';
                    		break;
                    	case '2':
                    		imageNumber[i][j] = 'o';
                    		break;
                    	case '3':
                    		imageNumber[i][j] = 'O';
                    		break;
                    	case '4':
                    		imageNumber[i][j] = '0';
                    		break;
                    }
                    printf("%c", imageNumber[i][j]);
        	}
        	
}
printf("\n");
}
//brighten and dim
void brightdim(int row, int col, char modfiyImage[][col]){
	char userinput;
	printf("push [b] for brigten and [d] for dim");
	scanf("%c", &userinput);
	if(userinput = 'b'){
		for(int i = 0; i <= row; i++){
			for(int j = 0; j <= col; j++){
			switch(modfiyImage[i][j]){
				case' ':
					'.'==' ';
					break;
				case'.':
					'o'== '.';
					break;
				case'o':
					'O' == 'o';
					break;
				case'O':
					'0'=='O';
					break;
				case'0':
					'0'=='0';
					break;
			
			
			}
			printf("%c", modfiyImage[i][j]);
			}
			}
			}
		else{
		for(int i = 0; i <= row; i++){
			for(int j = 0; j <= col; j++){
			switch(modfiyImage[i][j]){
				case' ':
					' '==' ';
					break;
				case'.':
					' '== '.';
					break;
				case'o':
					'.' == 'o';
					break;
				case'O':
					'o'=='O';
					break;
				case'0':
					'O'=='0';
					break;
		}
		printf("%c", modfiyImage[i][j]);
		}
		}		
	
	
	
	
	}
}
void crop(int row, int col, char ogImage[][COL]){
	char array[row];
	int newR, newC;
	int start = 1;
	int row1, row2, col1, col2;
	printf("%d", start);
	for(int i= 0; i < row; i++){
		array[i] = ' ';
		printf("%c", array[i]);
	}
	printf("%d", row);
	printf("\n");
	for(int i = 0; i <= row; i++){
	for(int j = 0; j <= col; j++){
                  printf("%c",  ogImage[i][j]);
    	}
        	
}

printf("\n");
	
	
	printf("the current size is %d x %d\n", row, col);
	printf("which column do you want to be the new left side?");		
	scanf("%d",&col1);
	printf("which column do you want to be the new right side?");
	scanf("%d",&col2);
	printf("which row do you want to be the new top?");
	scanf("%d", &row1);
	printf("which row do you want to be the new bottom?");
	scanf("%d", &row2);
	for(int i = row1; i < row2; i++){
		for(int j = col1; j < col2; j++){
			printf("%c", ogImage[i][j]);

		}
	}
	printf("\n");
}


