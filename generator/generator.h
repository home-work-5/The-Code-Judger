#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h> 


/** 
 * This function using for getting the inpt from input.txt and place the output to output.txt
 * 
 * @param number        the intiger order of a input/output file name for example: input1.txt .
 * @param projectName   is the name of directory that the C file exists in .
 * @param fileName      is the name of the C file that we want to generate outputs from it .
 * @param outFolderName is the name of the folder that the outputs should place in .
 */
void MakeOutputFromInput(int number, char projectName[], char fileName[], char outFolderName[] );


/** 
 * This function using for getting all the directories
 * 
 * @param projectName   is the name of directory that the C file exists in .
 * @param fileName      is the name of the C file that we want to generate outputs from it .
 * @param outFolderName is the name of the folder that the outputs should place in .
 */

void GettinAllDirectories(char projectName[], char fileName[], char outFolderName[]);