#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include"emalloc.h"
#include<unistd.h>

void fatal(char *message){
	char err_mess[100];

	strcpy(err_mess, "[!!] FATAL ERROR [!!]");
	strncat(err_mess,message, 83);
	perror(err_mess);
	exit(-1);
}

int main(int argc, char *argv[]){
		
	if(argc < 3){
		printf("Usage: %s <Information that you want inserted into the file> <file path - starting from root (/)>\n", argv[0]);
		exit(-1); 
	}
	int fd;
	char *buffer, *datafile;

	buffer = (char *)emalloc(100);
	datafile = (char *)emalloc(20);

	strcpy(datafile, argv[2]);

	strcpy(buffer, argv[1]);
	strncat(buffer,"\n",1);

	printf("[+] Adding your note: %s to %s\n", buffer,datafile);
	
	fd = open(datafile,O_APPEND|O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);
	if(fd == -1){
		fatal("[*] Error in main() with opening [*]");
	}

	printf("Your file descriptor: %d\n",fd);

	if(write(fd,buffer,strlen(buffer)) == -1){
		fatal("[*] Error in writing to the file in main() [*]");
	}

	printf("[+] Succeeded in writing to the file %s\n",datafile);

	if(close(fd) == -1){
		fatal("[*] Error in closing the file [*]\n");
	}

	printf("[+] Success!\n");
	printf("[-] Freeing HEAP SPACE\n");
	free(buffer);
	free(datafile);
		
}
