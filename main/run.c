#include<stdio.h>
#include<stdlib.h>

/**
 * it compile and run main.c.
 * it's just for run the main file easly and when you once compiled the main.c file you dont need it until the next change on main.c .
 * you can delete it
 * @param 
 * @return 
 */
 
int main(){
	
	if(system("gcc -Wall main.c -o main.exe"))printf("++\n");
	else printf("--\n");
	system("main.exe");

	char c;
	printf("\n\nPress a key to close...");
	scanf("%c", &c);
	return 0;
}
