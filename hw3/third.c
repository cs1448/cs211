#include <stdio.h>

char *toString(unsigned short number){
    char binary[17];

    for (int i = 0; i < 16; i++){
        binary[i] = number & 0x8000 ? '1' : '0';
        number <<=  1;
	//printf("%c", binary[i]);
    }
	//printf("\t");
    binary[16] = '\0';

    int check = 0;
    int a, b;
   for (a = 0, b = 15; a <= 7, b >= 8; a++, b--){
       if (binary[a] != binary[b]){
           check = 1;
           break;
       }
   }
   if (check == 1){
       printf("%s", "Not-Palindrome");
   }
   else {
       printf("%s", "Is-Palindrome");
   }
}
int main(int argc, char* argv[]) {
	
    unsigned short x = atoi(argv[1]);

    toString(x);


}

