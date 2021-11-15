/* 
 * 
 * This code calculates the house price of a house by learing from
 * training data. It uses pseudo inverse of a given matrix to find the 
 * weight of different features.
 * 
 * Predicted Price : Y = W0 + W1*x1 + W2*X2 + W3*X3 + W4*X4
 * Weight Matrix : W = pseudoInv(X)*Y
 * pseudoInv(X) = inverse(transpose(X)*X) * transpose(X)  
 * 
 * weight(w) = pseudoInv(X) * Y
 * 			where	X = Input data matrix
 * 					Y = Target vector
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

// all methods declarations
double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2);
double** transposeMatrix(double** mat, int row, int col);
double** inverseMatrix(double **matA, int dimension);

// main method starts here
int main(int argc, char** argv){


      FILE *open = fopen(argv[1], "r"); //scans file name and reads
      FILE *file = fopen(argv[2], "r"); //scans second file name and reads


      if (file == NULL || open == NULL){
	printf("%s", "error");
      }


    int n, k;
    int i, j;
    int testing;

    fscanf(open, "%d", &k); //scans first number for number of cols
    fscanf(open, "%d", &n); //scans second number for number of rows + 1 because of
   			    //first column needing to be all 1s
    k++;
    
    fscanf(file, "%d", &testing);


    double testFile[testing][k];
    double testTemp = 0;

    for (int i = 0; i < testing; i++){
       for (int j = 0; j < k; j++){
          
          if (j == 0){
             testFile[i][j] = 1;
             continue;
          }
    
          testTemp = 0;
          fscanf(file, "%lf", &testTemp);
          char testChar;
          fscanf(file, "%c", &testChar);
          
          testFile[i][j] = testTemp;
       }
    }



    double Y[n][1];  //building array of cost values "Y"
    double X[n][k]; //building base array "X"

    double trainTemp = 0;

    for (i = 0; i < n; i++) { //i is rows (n)
        for (j = 0; j < k + 1; j++) { // j is cols (k + 1)
            if (j == 0){  //sets first column to all 1
		X[i][j] = 1;
		continue;
	    }
	    trainTemp = 0;
            fscanf(open, "%lf", &trainTemp); //sacns values in the text file locating it in temp
	    char trainChar;
	    fscanf(open, "%c", &trainChar);

	    if (j < k){
		X[i][j] = trainTemp;
	    }
	    
	    else{
	    	Y[i][0] = trainTemp;

            }

        }
	 
    }
	
    int l, m;
    double transposeX [k][n];

        for (l = 0; l < k; l++) { //iterates through rows of original matrix
    	    for (m = 0; m < n; m++) { //iterates through cols of original matrix
        	transposeX[l][m] = X[m][l]; //switches positions from original to transposed matrix
		//printf("%lf\t", transposeX[l][m]);
    	    }
	    //printf("\n");
        }
 



    int a,b,c;
    double multiXT[k][k];

	
	for (a = 0; a < k; a++){//iterates through first matrix rows
	    for (b = 0; b < k; b++){ //iterates through second matrix cols

        	multiXT[a][b] = 0;//sets initial value to 0;

        	for (c = 0; c < n; c++){//iterates through first matrix cols

            	    multiXT[a][b] += (transposeX[a][c] * X[c][b]); //multiplies and adds into new matrix
		    
        	}
    	    }
	}
 
    int columns;
    columns = k;

    double build[columns][2*columns]; // building base array to invert 	
														 							
	   for (int i = 0; i < columns; i++){ //fills the rows							 	
	      for (int j = 0; j < columns; j++){// allocating 2x size of original for the identity matrix	
		 build[i][j] = multiXT[i][j];// transfers X^t*X to the build matrix 
	      }
	   }



   double identity[columns][columns]; //creating an identity matrix	
														
	   for (int i = 0; i < columns; i++){ //rows for identity matrix 					
	      for (int j = 0; j < columns; j++){ //columns for identity matrix					
		  if (i == j){ //checking if its at the [0,0], [1,1], [2,2]... position
		     identity[i][j] = 1; //sets value at those equal to 1;
		  }
		  else {
		     identity[i][j] = 0; //sets everything else to 0;
	  
		  }
	      }
	   }


 
	   

   int rightside;

	   for (int i = 0; i < columns; i++){ //iterates through build's rows							
	      rightside = 0; /*sets indicator of the identity matrix to the front						1 2 3  | 1 0 0
																1 5 4  | 0 1 0    */
	      for (int j = columns; j < 2 * columns; j++){ //iterates through the right half columns of the build matrix	1 6 9  | 0 0 1
																
		 build[i][j] = identity[i][rightside]; //sets the first value of the right side of build to the first value of identiy 	
		 rightside = rightside + 1; //increase for the next position 		
	      }
	   }

   double scalar;
   double point;	
   
	   for (int i = 0; i < columns; i++){ //iterates through rows
	      for (int j = 0; j < columns; j++){ //iterates through columns

		 if (i == j){  //if equal, it means it must be a pivot

		    for (int a = 0; a < columns; a++){  //second pointer to get to next row

		       if (a != i){  // keep going until it gets to a new row thats not where i is
			  point = build[a][j]; //variable to keep track of what number were going to divide
			  scalar = -1*(point/build[i][j]); //multilpy scalar by -1 make it negative and divide into point

			  for (int b = 0; b < 2 * columns; b++){ //iterates a second pointer for columns to do this for every value in the row
	 		     build[a][b] = (build[i][b]*scalar) + build[a][b]; //Gauss-Jordan elimination 
		          }
		       }

		       else {
			  continue;
		       }
		        
		    }
		 }

		 else {
		   continue;
		 }
	      }
	   }	   



   double divideby;   
	
	   for (int i = 0; i < columns; i++){
	      for (int j = 0; j < 2 * columns; j++){
		 
		 if (j == i){ //if its a pivot
		    divideby = build[i][j]; //set variable equal to the number we need to divide the row by 
		 }

	      build[i][j] = (build[i][j]/divideby); //divide entire row 

	      }
	   }


   //gets rid of the identity matrix now on the left side of build
   int getrid = 0;  
   int tempCols = columns;
   double postinverse[columns][columns];
   
	   for (int i = 0; i < columns; i++){	  
	      for (int j = 0; j < columns; j++){
		 postinverse[i][j] = build[getrid][tempCols]; 
		 tempCols++;
	      }
	      tempCols = columns;
	      getrid++;


	   }


   //multiply inverse by transpose
   double invtrans[columns][n];
	for (a = 0; a < columns; a++){//iterates through first matrix rows
	    for (b = 0; b < n; b++){ //iterates through second matrix cols

        	invtrans[a][b] = 0;//sets initial value to 0;

        	for (c = 0; c < columns; c++){//iterates through first matrix cols

            	    invtrans[a][b] += (postinverse[a][c] * transposeX[c][b]); //multiplies and adds into new matrix
		    
        	}
    	    }
	}

	

  //multiply matrix by Y to get W
   double W[columns][1];
	for (a = 0; a < columns; a++){//iterates through first matrix rows
	    for (b = 0; b < 1; b++){ //iterates through second matrix cols

        	W[a][b] = 0;//sets initial value to 0;

        	for (c = 0; c < n; c++){//iterates through first matrix cols

            	    W[a][b] += (invtrans[a][c] * Y[c][b]); //multiplies and adds into new matrix
		    
        	}
    	    }
	}	




   //multiply W by test file 

   double final[testing][1];
      for (a = 0; a < testing; a++){//iterates through first matrix rows
         for (b = 0; b < 1; b++){ //iterates through second matrix cols
 
            final[a][b] = 0;//sets initial value to 0;
  
               for (c = 0; c < columns; c++){//iterates through first matrix cols

                  final[a][b] += (testFile[a][c] * W[c][b]); //multiplies and adds into new matrix
			    
               }
         }
      }



      int ii, jj;
	
      for (ii = 0; ii < testing; ii++){
         for (jj = 0; jj < 1; jj++){
	    printf("%0.0lf\t", final[ii][jj]);
	 }
	printf("\n"); 
    }






   fclose(file);
   fclose(open);
   return 0;
		
}


/*double** multiplyMatrix(double **matA, double **matB, int r1, int c1, int r2, int c2)
{
    double** result=malloc(r1*sizeof(double*)); 
    
    // your code goes here
    
    return result;
}

*/
/*double** transposeMatrix(double** mat, int row, int col){
  
    double** matTran=malloc(col*sizeof(double*)); 
   
    
    int l, m;
    for (l = 0; l < row; l++) { //iterates through rows of original matrix
    	for (m = 0; m < col; m++) { //iterates through cols of original matrix
        	matTran[l][m] = mat[m][l]; //switches positions from original to transposed matrix
    	}
    }

    return matTran;      
}

*/

/*
double** inverseMatrix(double **matA, int dimension)
{

    double** matI=malloc(dimension*sizeof(double*)); 

    // your code goes here
    
	return matI;
}

*/
