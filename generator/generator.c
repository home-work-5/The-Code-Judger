#include "generator.h"

#define MAX_STR_SIZE 1000
#define MAX_NUM_STR_SIZE 10

/** 
 * This function using for generating he outputs of a c file.
 * 
 * @param projectName   is the name of directory that the C file exists in .
 * @param fileName      is the name of the C file that we want to generate outputs from it .
 * @param outFolderName is the name of the folder that the outputs should place in .
 */	
void generate(char projectName[], char fileName[], char outFolderName[]){
	
	///// making 'outFolderName' directory /////
	char toMakeOutDir[MAX_STR_SIZE];
	
	sprintf(toMakeOutDir, "mkdir ..\\%s\\%s", projectName, outFolderName);
	
	system(toMakeOutDir); //=>  system( "mkdir ..\\projectName\\outFolderName" )
	
	
	///// Compiling fileName.c /////
	char toCompileProject[MAX_STR_SIZE];
	
	sprintf(toCompileProject, "gcc -Wall ..\\%s\\%s.c -o ..\\%s\\%s", projectName, fileName, projectName, fileName);
	
	system(toCompileProject); //=> gcc -Wall ..\\projectName\\fileName.c -o ..\\projectName\\fileName
	
	
	GettinAllDirectories(projectName, fileName, outFolderName);
	
	printf("\nOutputs Generated!\n\n");
	
}


/** 
 * This function using for getting the inpt from input.txt and place the output to output.txt
 * 
 * @param number        the intiger order of a input/output file name for example: input1.txt .
 * @param projectName   is the name of directory that the C file exists in .
 * @param fileName      is the name of the C file that we want to generate outputs from it .
 * @param outFolderName is the name of the folder that the outputs should place in .
 */
void MakeOutputFromInput(int number, char projectName[], char fileName[], char outFolderName[] ){
	
	char stringNumber[MAX_NUM_STR_SIZE];
	itoa(number, stringNumber, 10);// Convert Number To String
	
	
	char command[MAX_STR_SIZE];
	
	sprintf(command, "..\\%s\\%s.exe <..\\%s\\in\\input%s.txt >..\\%s\\%s\\output%s.txt",projectName,fileName,projectName,stringNumber,projectName,outFolderName,stringNumber);
	
	system(command);  //=> system("..\projectName\fileName.exe <..\projectName\in\input1.txt>..\projectName\outFolderName\output1.txt")

}


/** 
 * This function using for getting all the directories
 * 
 * @param projectName   is the name of directory that the C file exists in .
 * @param fileName      is the name of the C file that we want to generate outputs from it .
 * @param outFolderName is the name of the folder that the outputs should place in .
 */

void GettinAllDirectories(char projectName[], char fileName[], char outFolderName[]){
	
	struct dirent *de; 
	char string[MAX_STR_SIZE];
	
	sprintf(string, "..\\%s\\in",projectName);
	
	DIR *dr = opendir(string); 

	if (dr == NULL){ 
		printf("Could not open current directory" ); 
	} 
	
	int number = 1;
	while ((de = readdir(dr)) != NULL) {
		if ( strcmp(de->d_name, ".")==0 || strcmp(de->d_name, "..")==0 )continue;
		MakeOutputFromInput(number, projectName, fileName, outFolderName);
		number++;
	}	
		
	closedir(dr);	 
} 
