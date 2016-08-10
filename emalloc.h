#include<stdio.h>
#include<stdlib.h>

void * emalloc(unsigned int size){
        void * ptr;
        ptr = malloc(size);
        if(ptr == NULL){
                fprintf(stderr,"[*]Failure to allocate HEAP SPACE\n");
                printf("[*]Goodbye");
                exit(-1);
        }
}

