#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//read   yes
//print  yes
//add    yes
//mul    yes 
//sub    yes
//div    yes
//mov    yes
//jmp    yes
//je     yes
//jne    yes
//jg     yes
//jge    yes
//jl     yes
//jle    yes


char big[100][100];
short int ax = 0;
short int bx = 0;
short int cx = 0;
short int dx = 0;


int main(int argc, char* argv[]) {

    FILE *file = fopen(argv[1], "r");

    for (int i = 0; i < 99; i++) {
       
        fgets(big[i], 100, file);
	//printf("%s", big[i]);
       
    }
    fclose(file);
	
        

    for (int i = 0; i < 99; i++) {
        if (strcmp(big[i], "") == 0){
	    continue;
        }
	//printf("%s", big[i]);


	char line[4][20];
    	int a = 0;
	char copy[100] = "";
	strcpy(copy, big[i]);

        char *token = strtok(copy, " ");

    	while (token != NULL){
	    strcpy(line[a], token);
	    //printf("%s\n", line[a]);
            token = strtok(NULL, " \n");
	    a++;
	}
        
 	if (strcmp(line[0], "read") == 0){
	    short int val;
	    scanf("%hi", &val);
	    	if (strcmp(line[1], "ax") == 0) {
                    ax = val;
		    //printf("%hi", ax);
		                      
                } else if (strcmp(line[1], "bx") == 0) {
                    bx = val;
                    
                } else if (strcmp(line[1], "cx") == 0) {
                    cx = val;
                    
                } else if (strcmp(line[1], "dx") == 0) {
                    dx = val;
                    
                }
          }
       if (strcmp(line[0], "print") == 0){
            	    if (strcmp(line[1], "ax") == 0) {
            	        printf("%hi", ax);
			
		    }

            	    else if (strcmp(line[1], "bx") == 0) {
                        printf("%hi", bx);
			
		    }

                    else if (strcmp(line[1], "cx") == 0) {
                        printf("%hi", cx);
			
		    }

                    else if (strcmp(line[1], "dx") == 0) {
                        printf("%d", dx);
			
                    }
		    else {
			short int printelement = 0;
			printelement = atoi(line[1]);
			printf("%hi", printelement);

		   }
    	}
	
	if (strcmp(line[0], "add") == 0){ //start of add
	     if (strcmp(line[1], "ax") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax + ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + ax;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx + ax;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx + ax;
		}
	    }
	   else if (strcmp(line[1], "bx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax + bx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx + bx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx + bx;
		}
	    }
	   else if (strcmp(line[1], "cx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax + cx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + cx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx + cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx + cx;
		}
	    }
	   else if (strcmp(line[1], "dx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax + dx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + dx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx + dx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx + dx;
		}
	    }
	    else {
		short int addelement;
		addelement = atoi(line[1]);
		if (strcmp(line[2], "ax") == 0){
		    ax = ax + addelement;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + addelement;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx + addelement;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx + addelement;
		}
	    }
	}
	


	if (strcmp(line[0], "mul") == 0){ //start of mul
	     if (strcmp(line[1], "ax") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax * ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx * ax;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx * ax;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx * ax;
		}
	    }
	   else if (strcmp(line[1], "bx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax * bx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx * bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx * bx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx * bx;
		}
	    }
	   else if (strcmp(line[1], "cx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax * cx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx * cx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx * cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx * cx;
		}
	    }
	   else if (strcmp(line[1], "dx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax * dx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx * dx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx * dx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx * dx;
		}
	    }
	    else {
		short int mulelement;
		mulelement = atoi(line[1]);
		if (strcmp(line[2], "ax") == 0){
		    ax = ax * mulelement;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx + mulelement;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx * mulelement;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx * mulelement;
		}
	    }
	}




	if (strcmp(line[0], "mov") == 0){ //start of mov
	     if (strcmp(line[1], "ax") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = ax;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = ax;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = ax;
		}
	    }
	   else if (strcmp(line[1], "bx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = bx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = bx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = bx;
		}
	    }
	   else if (strcmp(line[1], "cx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = cx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = cx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = cx;
		}
	    }
	   else if (strcmp(line[1], "dx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = dx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = dx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = dx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx;
		}
	    }
	    else {
		short int movelement;
		movelement = atoi(line[1]);
		if (strcmp(line[2], "ax") == 0){
		    ax = movelement;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = movelement;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = movelement;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = movelement;
		}
	    }
	}


	if (strcmp(line[0], "sub") == 0){ //start of sub (y - x)
	     if (strcmp(line[1], "ax") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax - ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx - ax;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx - ax;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx - ax;
		}
	    }
	   else if (strcmp(line[1], "bx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax - bx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx - bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx - bx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx - bx;
		}
	    }
	   else if (strcmp(line[1], "cx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax - cx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx - cx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx - cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx - cx;
		}
	    }
	   else if (strcmp(line[1], "dx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax - dx;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx - dx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx - dx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx - dx;
		}
	    }
	    else {
		short int subelement;
		subelement = atoi(line[1]);
		if (strcmp(line[2], "ax") == 0){
		    ax = ax - subelement;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx - subelement;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx - subelement;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = cx - subelement;
		}
	    }
	}

	if (strcmp(line[0], "div") == 0){ //start of div x/y
	     if (strcmp(line[1], "ax") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = ax/ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = ax/bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = ax/cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = ax/dx;
		}
	    }
	   else if (strcmp(line[1], "bx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = bx/ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = bx/bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = bx/cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = bx/dx;
		}
	    }
	   else if (strcmp(line[1], "cx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = cx/ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = cx/bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = cx/cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = cx/dx;
		}
	    }
	   else if (strcmp(line[1], "dx") == 0){
		if (strcmp(line[2], "ax") == 0){
		    ax = dx/ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = dx/bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = dx/cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = dx/dx;
		}
	    }
	    else {
		short int divelement;
		divelement = atoi(line[1]);
		if (strcmp(line[2], "ax") == 0){
		    ax = divelement/ax;
		}
		
		if (strcmp(line[2], "bx") == 0){
		    bx = divelement/bx;
		}

		if (strcmp(line[2], "cx") == 0){
		    cx = divelement/cx;
		}

		if (strcmp(line[2], "dx") == 0){
		    dx = divelement/dx;
		}
	    }
	}
	
	if (strcmp(line[0], "jmp") == 0){ //start of jmp
	
	    int jmp;
	    jmp = atoi(line[1]);
	    i = jmp - 1; 
	    continue;
	    
	}
	if (strcmp(line[0], "jle") == 0){ //start of jle
	    int jle = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    i = jle - 1;
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax <= bx){
			i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax <= cx){
			i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax <= dx){
			i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jleele = atoi(line[3]);
		    if (ax <= jleele){
		        i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx <= ax){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		     i = jle - 1;
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx <= cx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx <= dx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jleele = atoi(line[3]);
		    if (bx <= jleele){
		       i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx <= ax){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx <= bx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    i = jle - 1;
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx <= dx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jleele = atoi(line[3]);
		    if (cx <= jleele){
		         i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx <= ax){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx <= bx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx <= cx){
			 i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    i = jle - 1;
			continue;
		}
		else {
		    int jleele = atoi(line[3]);
		    if (dx <= jleele){
		         i = jle - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jlenum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jlenum <= ax){
		     i = jle - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jlenum <= bx){
		     i = jle - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jlenum <= cx){
		     i = jle - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jlenum <= dx){
		     i = jle - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jlenum2;
		jlenum2 = atoi(line[3]);
		if (jlenum <= jlenum2){
		     i = jle - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
	
		
    }//end of jle

	

	if (strcmp(line[0], "jl") == 0){ //start of jl
	    int jl = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		   
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax < bx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax < cx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax < dx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jlele = atoi(line[3]);
		    if (ax < jlele){
		        i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx < ax){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx < cx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx < dx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jlele = atoi(line[3]);
		    if (bx < jlele){
		        i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx < ax){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx < bx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		   
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx < dx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jlele = atoi(line[3]);
		    if (cx < jlele){
		        i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx < ax){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx < bx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx < cx){
			i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		   
			continue;
		}
		else {
		    int jlele = atoi(line[3]);
		    if (dx < jlele){
		        i = jl - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jlnum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jlnum < ax){
		    i = jl - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jlnum < bx){
		    i = jl - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jlnum < cx){
		   i = jl - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jlnum < dx){
		    i = jl - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jlnum2;
		jlnum2 = atoi(line[3]);
		if (jlnum < jlnum2){
		   i = jl - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
      }

	

	if (strcmp(line[0], "jge") == 0){ //start of jge
	    int jge = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    i = jge - 1;
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax >= bx){
			i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax >= cx){
			i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax >= dx){
			i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgeele = atoi(line[3]);
		    if (ax >= jgeele){
		        i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx >= ax){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		     i = jge - 1;
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx >= cx){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx >= dx){
			i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgeele = atoi(line[3]);
		    if (bx >= jgeele){
		       i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx >= ax){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx >= bx){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    i = jge - 1;
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx >= dx){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgeele = atoi(line[3]);
		    if (cx >= jgeele){
		         i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx >= ax){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx >= bx){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx >= cx){
			 i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    i = jge - 1;
			continue;
		}
		else {
		    int jgeele = atoi(line[3]);
		    if (dx >= jgeele){
		         i = jge - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jgenum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jgenum >= ax){
		     i = jge - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jgenum >= bx){
		     i = jge - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jgenum >= cx){
		     i = jge - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jgenum >= dx){
		     i = jge - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jgenum2;
		jgenum2 = atoi(line[3]);
		if (jgenum >= jgenum2){
		     i = jge - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
	
		
    }//end of jge

	if (strcmp(line[0], "jg") == 0){ //start of jg
	    int jg = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		   
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax > bx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax > cx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax > dx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgele = atoi(line[3]);
		    if (ax > jgele){
		        i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx > ax){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx > cx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx > dx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgele = atoi(line[3]);
		    if (bx > jgele){
		        i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx > ax){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx > bx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		   
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx > dx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jgele = atoi(line[3]);
		    if (cx > jgele){
		        i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx > ax){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx > bx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx > cx){
			i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		   
			continue;
		}
		else {
		    int jgele = atoi(line[3]);
		    if (dx > jgele){
		        i = jg - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jgnum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jgnum > ax){
		    i = jg - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jgnum > bx){
		   i = jg - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jgnum > cx){
		   i = jg - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jgnum > dx){
		    i = jg - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jgnum2;
		jgnum2 = atoi(line[3]);
		if (jgnum > jgnum2){
		   i = jg - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
      }// end of jg


	if (strcmp(line[0], "je") == 0){ //start of je
	    int je = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    i = je - 1;
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax == bx){
			i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax == cx){
			i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax == dx){
			i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jeele = atoi(line[3]);
		    if (ax == jeele){
		        i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx == ax){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		     i = je - 1;
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx == cx){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx == dx){
			i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jeele = atoi(line[3]);
		    if (bx == jeele){
		       i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx == ax){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx == bx){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    i = je - 1;
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx == dx){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jeele = atoi(line[3]);
		    if (cx == jeele){
		         i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx == ax){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx == bx){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx == cx){
			 i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    i = je - 1;
			continue;
		}
		else {
		    int jeele = atoi(line[3]);
		    if (dx == jeele){
		         i = je - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jenum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jenum == ax){
		    i = je - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jenum == bx){
		    i = je - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jenum == cx){
		     i = je - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jenum == dx){
		     i = je - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jenum2;
		jenum2 = atoi(line[3]);
		if (jenum == jenum2){
		     i = je - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
	
		
    }//end of jge



	if (strcmp(line[0], "jne") == 0){ //start of jne
	    int jne = atoi(line[1]);
	    if (strcmp(line[2], "ax") == 0){
	        if (strcmp(line[3], "ax") == 0){
		   
		        continue;
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (ax != bx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (ax != cx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (ax != dx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jneele = atoi(line[3]);
		    if (ax != jneele){
		        i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "bx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (bx != ax){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    
		        continue;
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (bx != cx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (bx != dx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jneele = atoi(line[3]);
		    if (bx != jneele){
		        i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "cx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (cx != ax){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (cx != bx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		   
			continue;
		}
	        if (strcmp(line[3], "dx") == 0){
		    if (cx != dx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
		else {
		    int jneele = atoi(line[3]);
		    if (cx != jneele){
		        i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	 else if (strcmp(line[2], "dx") == 0){
	        if (strcmp(line[3], "ax") == 0){
		    if (dx != ax){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "bx") == 0){
		    if (dx != bx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "cx") == 0){
		    if (dx != cx){
			i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	        if (strcmp(line[3], "dx") == 0){
		   
			continue;
		}
		else {
		    int jneele = atoi(line[3]);
		    if (dx != jneele){
		        i = jne - 1;
			continue;
		    }
		    else {
			continue;
		    }
		}
	    }
	else {
	    int jnenum = atoi(line[2]);
	    
 	    if (strcmp(line[3], "ax") == 0){
		if (jnenum != ax){
		    i = jne - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "bx") == 0){
		if (jnenum != bx){
		   i = jne - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "cx") == 0){
		if (jnenum != cx){
		   i = jne - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    if (strcmp(line[3], "dx") == 0){
		if (jnenum != dx){
		    i = jne - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	    else {
		int jnenum2;
		jnenum2 = atoi(line[3]);
		if (jnenum != jnenum2){
		   i = jne - 1;
		    continue;
		}
		else{
		    continue;
		}
	    }
	
	}
      }// end of jne







    }//end of for loop

}//end main






