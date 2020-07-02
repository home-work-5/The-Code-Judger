#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * This is a function that help us to check testcases.
 * This  function calculate number of input and output files in input and output folder.
 * @param directoryDirection : direction of folder.
 * @return directoryCounter  : number of files.
 */
int directoryNumbers(char directoryDirection[]);



/**
 * This function check that is there output for every input with calculating their number,
 * @param inNum  : number of input files.
 * @param outNum : number of output files.
 * @return "1" or "-1" : if test cases are ok --> 1 , in other case --> -1
 */
int testCaseFinalCheck(int inNum, int outNum);



/**
 * This function compare our output with correct output which we gained them by generate right code.
 * if there is any unmacthable content in two file we got an error that means our output is not right.
 * so we return it to "main".
 * @param *firstFile:  It's the first  file to compare
 * @param *secondFile: It's the second file to compare
 * @return error:      If the content are the same error=0 and if thay were different error!=0
 */
int compareFiles(FILE *firstFile, FILE *secondFile);




/**
 * this function generate us name of output files like:
 * output1.txt output2.txt ...
 * these name will help us in the addrese function to giv judge testcases.
 * @param counter : for --> output1.txt output2.txt output3.txt ...
 * @return finalOutPutName : return above name as a string.
 */
const char* outPutNameGenaration(int counter);

