#include <stdio.h>
/**
 * this function add two inigers that given and it's working! 
 * @param 
 * @return 
 */
int main(){
	int n=0;
	int number1=0,number2=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		//printf("n1, n2: ");
		scanf("%d %d",&number1, &number2);
		printf("%d\n",number1+number2);
	}
	return 0;
}