#include "judge.h"

#define MAX_COUNTER_SIZE 1000*100
#define MAX_OUTPUT_SIZE 100


/**
 * This is a main judge function.
 * @param projectName : name of the c file.
 * @return 
 */
int judge(char projectName[]){
	
    char inputDirection[MAX_OUTPUT_SIZE];
	sprintf(inputDirection, "..\\%s\\in", projectName); // ..\\projectName\\in
	
    char outputDirection[MAX_OUTPUT_SIZE];
	sprintf(outputDirection, "..\\%s\\out", projectName); // ..\\projectName\\judgeOut
	
	int inNum = directoryNumbers(inputDirection);
    int outNum = directoryNumbers(outputDirection);
    int testCaseCheck =  testCaseFinalCheck(inNum,outNum);
	
    if(testCaseCheck != 1){
        return 0;
    }
	
	int wasError = 0;
	int corrects = 0;
	int wrongs = 0;
	
    for (int counter=1 ;counter<inNum-1 ; counter++) {
		
        char *outputname = outPutNameGenaration(counter);

        char file1[MAX_OUTPUT_SIZE];
		sprintf(file1, "..\\%s\\out\\%s", projectName, outputname); // ..\\projectName\\out\\output1.txt
        
		
        FILE *fp1 = fopen(file1, "r");
		
        char file2[MAX_OUTPUT_SIZE];
		sprintf(file2, "..\\%s\\judgeOut\\%s", projectName, outputname); // ..\\file\\judgeOut\\output1.txt
		
        FILE *fp2 = fopen(file2, "r");
		
        if (fp1 == NULL || fp2 == NULL) {
            printf("Error : Files not open.");
			wasError = 1;
			break;
        }
        
        int error = compareFiles(fp1, fp2);
     
		if (error != 0) {
            printf("%s is\t\t WRONG.\n", outputname);
			wrongs++;
        }
        else if(error == 0){
            printf("%s is\t\t OK.\n",outputname);
			
			corrects++;
        }
    }
	
	if (!wasError){
		printf("\nOK answears:\t%d\n",corrects);
		printf("Wrong answears:\t%d\n",wrongs);
		printf("You answeared %d of %d test.\n",corrects, corrects+wrongs);

		float score=(float)corrects/(wrongs+corrects);
		
		printf("\n              \t %.1f\n", score*100);
		printf("Your score is:\t------\n");
		printf("              \t 100.0\n");
	}
	
    return 0;
}



/**
 * This is a function that help us to check testcases.
 * This  function calculate number of input and output files in input and output folder.
 * @param directoryDirection : direction of folder.
 * @return directoryCounter  : number of files.
 */
int directoryNumbers(char directoryDirection[]) {
    int directoryCounter = 0;
    
    // Pointer for directory entry
    struct dirent *de;

    // open dir() returns a pointer of DIR type.
    DIR *dr = opendir(directoryDirection);

    // open dir returns NULL if couldn't open directory
    if (dr == NULL){
		printf("\n%s\n",directoryDirection);//////////////////////////////////////delete
        printf("Could not open current directory.\n");
        printf("Please fix this and try again.");
        return 0;
    }

    //++ directoryCounter , for each file
    while ((de = readdir(dr)) != NULL){
        directoryCounter++;
    }

    closedir(dr);

    return directoryCounter;

}


/**
 * This function check that is there output for every input with calculating their number,
 * @param inNum  : number of input files.
 * @param outNum : number of output files.
 * @return "1" or "-1" : if test cases are ok --> 1 , in other case --> -1
 */
int testCaseFinalCheck(int inNum, int outNum) {
    // first if mean that number  of our files are equal(input and output files).
    // second if --> number of input files is greater than output files
    // third if --> number of input files is lesser than output files
    // for second and third situation , we have a problem with testcases
    // so we return -1 to end code in "main"

    if (inNum == 0 || outNum == 0){
        printf("you dont have any correct test case with our requested method,\n");
        printf("which is there is a output for every each of input.\n");
        return(-1);
    }

    if(inNum == outNum){
        printf("your test cases are OK!.\n\n");
        return 1;
    }

    else if (inNum > outNum){
        printf("we think you lost some of your output files.\nplease check them.\n");
        return (-1) ;
    }

    else if (inNum < outNum){
        printf("we think you lost some of your input files.\nplease check them.\n");
        return (-1) ;
    }

}


/**
 * This function compare our output with correct output which we gained them by generate right code.
 * if there is any unmacthable content in two file we got an error that means our output is not right.
 * so we return it to "main".
 * @param *firstFile:  It's the first  file to compare
 * @param *secondFile: It's the second file to compare
 * @return error:      If the content are the same error=0 and if thay were different error!=0
 */
int compareFiles(FILE *firstFile, FILE *secondFile){
    // fetching character of two file
    // in two variable ch1 and ch2
    char ch1 = getc(firstFile);
    char ch2 = getc(secondFile);

    // error keeps track of number of errors
    int error = 0;

    // iterate loop till end of file
    while (ch1 != EOF && ch2 != EOF){
        if (ch1 != ch2){
            error++;
        }

        // fetching character until end of file
        ch1 = getc(firstFile);
        ch2 = getc(secondFile);

        // this if is kind of break
        // if we have an error , we return it and this function stop working.
        if (error>0){
            return error;
        }
    }

    return error;
}


/**
 * this function generate us name of output files like:
 * output1.txt output2.txt ...
 * these name will help us in the addrese function to giv judge testcases.
 * @param counter : for --> output1.txt output2.txt output3.txt ...
 * @return finalOutPutName : return above name as a string.
 */
const char* outPutNameGenaration(int counter){
    char stringCounter[MAX_COUNTER_SIZE];
    //we convert integer "counter" to string "counter".
    //because strcat function , concatenate two string.
    itoa(counter, stringCounter, 10);

    // we want to make names like:
    //                            output1.txt
    //                            output2.txt
    //                            output3.txt
    //these works is all for passing name to "compareFiles" function
    //to compare them.
    char outPutName[MAX_OUTPUT_SIZE]= "output";
    strcat(outPutName , stringCounter);
    strcat(outPutName , ".txt");

    // we pass outPutName to char pointer finalOutPutName
    // its easy to return it :)
    char *finalOutPutName = outPutName;

    return finalOutPutName;
}