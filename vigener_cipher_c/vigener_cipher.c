#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//p + t = j
//i want j-p=t getting Z


int mod(int input, int modulus){
	int x=input%modulus;
	if(x<0)
		return modulus+x;
	return x;
}
void decrypt(char *key, char *message){
	int msg_len=strlen(message);
	int key_len=strlen(key);
	int key_pos=0;

	for(int i=0; i<msg_len; i++)
		message[i]=mod(message[i]-key[i%key_len], 26)+96;
	return;

}

void encrypt(char *key, char *message){
	int msg_len=strlen(message);
	int key_len=strlen(key);
	int key_pos=0;

	for(int i=0; i<msg_len; i++)
		message[i]=mod(message[i]+key[i%key_len]-194, 26)+98;
	return;
}

int main(int argc, char **argv){
	if(argc!=4){
		printf("Run as: vigener_cipher -[e | d] [key] [message]\n\n");
		return 1;
	}


	if(argv[1][0]=='-'){
		if(argv[1][1]=='e'){
			encrypt(argv[2], argv[3]);
			printf("Encrypted Message:\n%s\n", argv[3]);
		}
		else if(argv[1][1]=='d'){
			decrypt(argv[2], argv[3]);
			printf("Decrypted Message:\n%s\n", argv[3]);
		}
		else{
			printf("Run as: vigener_cipher -[e | d] [key] [message]\n\n");
			return 1;
		}
	}
	else{
		printf("Run as: vigener_cipher -[e | d] [key] [message]\n\n");
		return 1;
	}
	return 0;
}
