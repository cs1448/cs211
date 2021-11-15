#include <stdio.h>

int main(int argc, char**argv) {

    FILE *file = fopen(argv[1], "r");
    unsigned short x;
    char word[5];
    int n, v;

	

    fscanf(file, "%hu", &x);
    while (fscanf(file, "%s %d %d", word, &n, &v) != EOF){
	//printf("%s", "here");

        if (word[0] ==  'g'){
	
            unsigned short temp;
            int value;

            temp = x & (1 << n);
            if (temp == 0){
                value = 0;
                printf("%d\n", value);
            }
            else {
                value = 1;
                printf("%d\n", value);
            }

        }
        else if (word[0] == 'c'){
            x = x ^ (1 << n);
            printf("%hu\n", x);
        }

        else if (word[0] == 's'){
            if (v == 0){
                x = x & (~ (1 << n));
            }

            else{
                x = x | (1 << n);
            }

            printf("%hu\n", x);
        }
    }


    fclose(file);
    return 0;
}
