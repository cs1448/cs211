#include <stdio.h>
#include <stdlib.h>

char *toString(unsigned short number){
    char binary[17];

    for (int i = 0; i < 16; i++){
        binary[i] = number & 0x8000 ? '1' : '0';
        number <<=  1;
	//printf("%c", binary[i]);
    }
	//printf("\t");
    binary[16] = '\0';

    int pairs = 0;
    int parity = 0;
    int traverse = 0;

    while (traverse < 16){
	if (binary[traverse] == '0'){
	    traverse++;
	    continue;
	}
	
	else {
	parity++;
	    if (binary[traverse + 1] == '1'){
		pairs++;
		parity++;
		traverse = traverse + 2;
		continue;
	    }

	    else{
		traverse++;
	    	continue;
	    }
	}
    }


    if (parity % 2 == 0){

        printf("%s\t", "Even-Parity");
        printf("%d\t", pairs);
	
    }

    else {

        printf("%s\t", "Odd-Parity");
        printf("%d\t", pairs);
    }
}

int main(int argc, char *argv[]){
		
    unsigned short x = atoi(argv[1]);

    toString(x);

}
