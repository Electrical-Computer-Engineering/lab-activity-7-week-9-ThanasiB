#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define rows 5
#define cols 5
//NAME : Athanasios Bubulinis
//ID: 114801485
//Lab 7 Part 1 Exersize 1

//INPUT FILE MUST BE NAMED "InputFile1.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile1.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile1.txt" TO FUNCTION
void arrayReader(float thisarray[rows][cols], FILE *thisfile){	//arrayReader needs array and file to run
	printf("\nThe 2d array read from the file(up to 4 decimal places):\n\n");	//text
	for(int r = 0; r < rows; r++){	for(int c = 0; c < cols; c++){			//loops rows and cols
			fscanf(thisfile, "%f", &thisarray[r][c]);			//scans from file and saves in rows and cols of array
			printf("%.4f   ", thisarray[r][c]);				//prints 4 digits of 2d array (change number in %.3f to change dec place output)
		}printf("\n\n");	}	}								//spacing

float threeRowSum(int r1, int r2, int r3, float thisTotal, float thisArray[rows][cols]){		//Task 2 of program
	for(int c = 0; c < cols; c++){	thisTotal += thisArray[r1][c];	}	//for every col in row, adds value to total
	for(int c = 0; c < cols; c++){	thisTotal += thisArray[r2][c];	}	//for every col in row, adds value to total
	for(int c = 0; c < cols; c++){	thisTotal += thisArray[r3][c];	}	//for every col in row, adds value to total
	return thisTotal;	//returns total
}

float upperTriangleReader(float thisarray[rows][cols], FILE *thisfile, float thisTotal){	//arrayReader needs array and file to run
	printf("\nThe 2d array read from the file(up to 4 decimal places):\n\n");	//text
	for(int r = 0; r < rows; r++){	for(int c = 0; c < cols; c++){			//loops rows and cols
			fscanf(thisfile, "%f", &thisarray[r][c]);			//scans from file and saves in rows and cols of array
			if(c < r ){ thisarray[r][c] = 0.00;	printf("         ");}	//if lower half, set to 0 and print ("			")
			else{printf("%.4f   ", thisarray[r][c]);	thisTotal+=thisarray[r][c];}					//prints 4 digits of 2d array when upper half (change number in %.3f to change dec place output)
		}printf("\n\n");	}	return thisTotal;	}								//spacing

void mnSwitch(float thisarray[rows][cols], int m, int n){
	float am[cols];
	for(int c = 0; c < cols; c++){	//swaps all row positions
		am[c] = thisarray[m][c];
		thisarray[m][c]	=	thisarray[n][c];
		thisarray[n][c]	=	am[c];
	}	printf("\nSwapped Rows:\n");
	for(int r = 0; r < rows; r++){	//swaps all row positions
		for(int c = 0; c < cols; c++){	//swaps all row positions
			printf("%.4f   ", thisarray[r][c]);
		}printf("\n\n");
	}
}

int main(){
	float array[rows][cols], total;	//defines all needed floats
	char ch;	int in, isNeg = 1, row1, row2, row3, input = 0;					//creates an empty char	and an empty int
	FILE *input_file = fopen("InputFile1.txt","r");			//creates FILE for input
	if(input_file==NULL){							//if a file failed to open 
		printf("NULL/FAILED");						//prints FAILED
		exit(1);		}							//program ends
		arrayReader(array, input_file);		//reads and prints array
	while(input != 6){	//program will end if 6 is inputted
		printf("\n\nWhich task would you like to perform(0 reads array): "); scanf("%d", &input);
		if(input == 0){	arrayReader(array, input_file);	}
		else if(input == 1){		//options for input
			row1 = 0; row2 = 0; row3 = 0;	total = 0.0000;
			printf("Input the 3 rows you would like to sum (first row = 0): "); 
			scanf("%d %d %d", &row1, &row2, &row3);		total = threeRowSum(row1, row2, row3, total, array);
			printf("The total of the three rows is %.4f ", total);
		}
		else if(input == 2){		//options for input
			printf("Upper part of traingle :");	total = 0.0000;
			total = upperTriangleReader(array, input_file, total);
			printf("The total of the upper half of the triange is %.6f ", total);
		}
		else if(input == 3){		//options for input
			printf("Input the 2 rows you would like to swap (first row = 0): "); 
			scanf("%d %d", &row1, &row2);
			mnSwitch(array, row1, row2);
		}
		else{exit(1);}
	}
	
	fclose(input_file);								//done with input so closes input file
}
