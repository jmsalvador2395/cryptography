#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
	printf("char\txor'd\n");
	for(char a=97; a<123; a++)
		printf("%c\t%c\n",a,a^' ');
	for(char a=65; a<91; a++)
		printf("%c\t%c\n",a,a^' ');
	return 0;
}
