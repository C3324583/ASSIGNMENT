
#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialising variables
	char text[100], element=0;
	int i=0, rotation=0;
	
	printf("Enter message: ");//prompt the user to imput a message
	fgets(text,100,stdin);//store the text imputted by the user in the array 'text'
	printf("Enter rotation amount: ");
	scanf("%d", &rotation);
	
	//this for loop executes the rotation for all letters in the array 'text' until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i];//
		
		//Each lowercase letter of the string is rotated by the same amount
		if(element >= 'a' && element <= 'z'){
			element = element + rotation;
			//If the rotation causes the element to have a value > z (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'z'){
				element = element - 26;
			}
			
			text[i] = element;
		}
		
		//Each UPPERCASE letter is turned into lowercase by by adding 32 (according to the ASCII standard) and then rotated
		else if(element >= 'A' && element <= 'Z'){
			element = element + rotation + 32;
			//If the rotation causes the element to have a value > z (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'z'){
				element = element - 26;
			}
			
			text[i] = element;
		}
	}
	
	printf("Encrypted message: %s", text);
	
	return 0;
}