#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include "..\generator\generator.c"
#include "..\judge\judge.c"


/**
 * this is the main function and prints the structure of the project and you can chose what to do.
 * @param 
 * @return 
 */
int main(){
	system("cls");
		
	while (1){
	
		system("cls");
			
		//Printing Help
		printf("\n\t\t\t<< STRUCTURE >>");
		printf("\n\n\tD: Directory\tc: c file\ttxt: text file\n");
		printf("\n> ..\n|\n|");
		printf("__> D project\n| |\n| |");
		printf("__> D in\n| | |\n| | |");
		printf("__> txt input1.txt ...\n| |\n| |\n| |\n| |");
		printf("__> D judgeOut\n| | |\n| | |");
		printf("__> txt output1.txt ...\n| |\n| |\n| |\n| |");
		printf("__> D out\n| | |\n| | |");
		printf("__> txt output1.txt ...\n| |\n| |\n| |\n| |");
		printf("__> c judge.c\n| |\n| |");
		printf("__> c right.c\n|\n|\n|");
		
		printf("__> YOU'RE HERE (main)\n| |\n| |");
		printf("__> c main.c\n|\n|\n|\n|");
		
		printf("__> D generator\n| |\n| |");
		printf("__> c generator.c\n|\n|\n|\n|");
		
		printf("__> D judge\n  |\n  |");
		printf("__> c judge.c\n");
		//end help
		
		char projectName[100];
		char rightfile[100];
		char toJudgefile[100];
		
		printf("\n\n\nEnter The Project Folder Name: ");
		scanf("%s",projectName);
		
		printf("\n\t\t\t<< OPTIONS >>");
		printf("\nWhat do you want to do?\n\n\t0. Generate output of 'ToJudge' Code.\n\t1. Generate 'RIGHT' output and 'JUDGE'.\n\t2. Just judge with the output you 'PLACED'.\n\t3.EXIT.\n: ");
		
		int whatToDo=3;
		scanf("%d", &whatToDo);
		
		if (whatToDo==0){//generate the toJudge file output
			printf("\nEnter the C file name that you want to generate its output(toJudge): ");
			scanf("%s",toJudgefile);
			generate(projectName, toJudgefile, "judgeOut");
		}
		
		if(whatToDo==1){//generate the right output and judge
			printf("\nEnter the 'RIGHT' C file name: ");
			scanf("%s",rightfile);
			generate(projectName, rightfile, "out");
			judge(projectName);
		}
		
		if(whatToDo==2){//judge with existed output
			printf("\nEnter the 'toJudge' File: ");
			scanf("%s",toJudgefile);
			generate(projectName, toJudgefile, "judgeOut");
			judge(projectName);
		}
		
		if(whatToDo==3){//judge with existed output
			break;
		}
		
		printf("\n");
		system("pause");
		
	}
	
    return 0;
}
