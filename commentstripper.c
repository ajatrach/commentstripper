#include <stdio.h>

#define READ_CHARACTER 0
#define FIRST_SLASH 1
#define SECOND_SLASH 2

int main(int argc, char *argv[]){

	unsigned int state = READ_CHARACTER;
 	int input = 0;

	while(1){
		input = getchar();
		if(input == EOF){
			break;
		} 
		switch(state){
			case READ_CHARACTER:
				if (input == '/'){
					state= FIRST_SLASH;
				}else{
					putchar(input);       //prints char
				}
				break;
			case FIRST_SLASH:
				if(input == '/'){
					state = SECOND_SLASH;
				}else{
					putchar('/');         //prints / skipped earlier
					putchar(input);
					state = READ_CHARACTER;
				}
				break;
			case SECOND_SLASH:
				if(input == '\n'){
					putchar(input);
					state = READ_CHARACTER;
				}
				break;
			default:
				state = READ_CHARACTER;   //catch-all instance in case you aren't in valid spot
		}
	}

}

