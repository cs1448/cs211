#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <ctype.h>


//check if cachesize and blocksize are integers
//check if assoc direct assoc:n is correct input

typedef struct Node{
    unsigned long long int tag;
}Node;
int reads = 0;
int writes = 0;
int hits = 0;
int misses = 0;
int islru = 0;

struct Node** hashptr;
struct Node** hashbuilder(int rows, int blocks);
int datacounter(char a, unsigned long long int offset, int blocks, int rows, unsigned long long int tag);
void freethehash(int rows, int blocks);
void movememory(unsigned long long int offset, int logs, int blocks);
void addtag(int blocks, unsigned long long int offset, unsigned long long int tag);



int main(int argc, char**argv) {
    char a;
    unsigned long long int memory;
    int x,y;


    if(argc != 6){
        printf("error");
	exit(0);
    }

    char* associativity = argv[2];
    char* r_policy = argv[3];
    


    int cache_size = atoi(argv[1]);
        if (ceil(log(cache_size)/log(2)) != floor(log(cache_size)/log(2))){
            printf("error");
	    exit(0);
        }


    int block_size = atoi(argv[4]);
	 if (ceil(log(block_size)/log(2)) != floor(log(block_size)/log(2))){
            printf("error");
	    exit(0);
        }


    if (block_size > cache_size){
	printf("error");
	exit(0);
    }



    int blocks = 0; 
    int rows; 

    if (strcmp(r_policy, "fifo") != 0 && strcmp(r_policy, "lru") != 0){
	printf("error");
	exit(0);
    }

    if (strcmp(r_policy, "lru") == 0){
	islru = 1;
    }

    if (strcmp(associativity, "assoc") == 0){
        blocks = cache_size / block_size;
	//rows = 1;
    }
    else if (strcmp(associativity, "direct") == 0){
        blocks = 1;
	//rows = cache_size / (blocks * block_size);
    }
    else if (associativity[5] == ':'){
        blocks = atoi(&associativity[6]);
        if (ceil(log(blocks)/log(2)) != floor(log(blocks)/log(2))){
            printf("error");
        }
    }

    if (strcmp(associativity, "assoc") == 0){
        rows = 1;
    }
    else {
        rows = cache_size / (blocks * block_size);
    }

    hashptr = hashbuilder(rows, blocks);


    FILE* file = fopen(argv[5], "r");
    if (file == NULL){
        printf("error");
	exit(0);
    }
    fseek(file, 0, SEEK_END);
    if (ftell(file) == 0){
        printf("error");
	exit(0);
    }
    rewind(file);


    x = log(block_size) / log(2);
    y = log(rows) / log(2);
    while(fscanf(file, "%*s %c %llx", &a, &memory) == 2){ //try using EOF
        unsigned long long int offset = memory >> x;
        if (y == 0){
            offset = 0;
        }
        else {
            unsigned long long int powers = pow(2,y);
            offset = offset % powers;
        }
        unsigned long long int tag = memory >> (x + y);
        datacounter(a, offset, blocks, rows, tag);

    }

    freethehash(rows, blocks);
    printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n", reads, writes, hits, misses);
    fclose(file);
    return 0;
}




struct Node** hashbuilder (int rows, int blocks){
    struct Node** hash_table = (struct Node**) malloc(sizeof(struct Node*) * rows);
    for (int i = 0; i < rows; i++){
        hash_table[i] = (struct Node*) malloc(sizeof(struct Node) * blocks);
        for (int j = 0; j < blocks; j++){
            hash_table[i][j].tag = 0;
        }
    }
    return hash_table;

}
int datacounter(char a, unsigned long long int offset, int blocks, int rows, unsigned long long int tag){
    int manage = 0, counter = 0; int log;
    for (int k = 0; k < blocks; k++){
        if (hashptr[offset][k].tag == tag){
            log = k;
            manage = 1;
            break;
        }
    }

    if (manage == 1 && a == 'R'){
	if (islru == 1){
	    movememory(offset, log, blocks);
	}
    hits++;
    counter = 1;
    }
    
    if (manage == 0 && a == 'R'){
	misses++;
	reads++;
	addtag(blocks, offset, tag);
	counter = 2;
    }

    if (manage == 1 && a == 'W'){
	if (islru == 1){
	    movememory(offset, log, blocks);
	}
    hits++;
    writes++;
    counter = 3;
    }

    if (manage == 0 && a == 'W'){
	misses++;
	reads++;
	writes++;
	addtag(blocks, offset, tag);
	counter = 4; 
    }
    
    return counter;
}




void movememory(unsigned long long int offset, int log, int blocks){
    unsigned long long int temp = hashptr[offset][log].tag;
    for (int i = log - 1; i >= 0; i--){
        if (hashptr[offset][i].tag == 0){
            continue;
        }
        else {
            hashptr[offset][i+1].tag = hashptr[offset][i].tag;
        }
    }
    hashptr[offset][0].tag = temp;
}


void addtag(int blocks, unsigned long long int offset, unsigned long long int tag){
    if (hashptr[offset][0].tag == 0){
        hashptr[offset][0].tag = tag;
    }
    else {
        for (int i = blocks - 2; i >= 0; i--){
            if (hashptr[offset][0].tag == 0){
                continue;
            }
            else {
                hashptr[offset][i+1].tag = hashptr[offset][i].tag;
            }
        }
        hashptr[offset][0].tag = tag;
    }

}


void freethehash(int rows, int blocks){ //try taking blocks variable out
    for (int i = rows - 1; i >= 0; i--){
        free(hashptr[i]);
    }
    free(hashptr);
}

