#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void *emalloc(unsigned int size){
	void * ptr;
	ptr = malloc(size);
	if(ptr == NULL){
		fprintf(stderr,"[*]Failure to allocate HEAP SPACE\n");
		printf("[*]Goodbye");
		exit(-1);
	}
}
int main(int argc, char *argv[]){
	char * char_ptr;
	int * int_ptr;
	int mem_size;

	if(argc < 2){
		mem_size = 50;
	}
	else{
		mem_size = atoi(argv[1]);
	}

	printf("[+]Allocating HEAP SPACE for char_ptr\n");
	printf("[+]Allocating %d bytes\n",mem_size);
	char_ptr = (char *)emalloc(mem_size);
	printf("[+] DONE\n");
	
		
	strcpy(char_ptr, "This memory is on the HEAP");
	printf("%p --> --> --> --> %s\n", char_ptr, char_ptr);

	printf("[-]Freeing up HEAP SPACE from char_ptr\n");
	free(char_ptr);
}
