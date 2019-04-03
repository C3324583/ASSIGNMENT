#include <stdio.h>
#include <stdlib.h>

//Consider putting the encryption in a function such as int ROTATION(char *text);

int main(){
    //initialising variables
	char text[126], element=0;
	int n=0, i=0, rotationkey=0;
	
	printf("Enter message: ");//prompt the user to imput a message
	fgets(text,126,stdin);//store the text imputted by the user in the array 'text'
	printf("Enter rotation amount: ");//prompt the user to imput a rotation key
	scanf("%d", &rotationkey);//store the rotation value in the variable 'rotation'
	
	//accounting for rotation keys that are not between 0 and 25 and translating them into their corresponding key within the range
	if(rotationkey>25){
	    n = rotationkey / 26;
	    rotationkey = rotationkey - (26 * n);
	}
	else if(rotationkey<0){
	    n = 1 + (-rotationkey) / 26;
	    rotationkey = rotationkey + (26 * n);
	}
	
	//this for loop executes the rotation for all letters in the array 'text' until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i];//
		
		//Each lowercase letter of the string is rotated by the same amount
		if(element >= 'a' && element <= 'z'){
			element = element + rotationkey;
			//If the rotation causes the element to have a value > z (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'z'){
				element = element - 26;
			}
			
			text[i] = element;
		}
		
		//Each UPPERCASE letter is turned into lowercase by by adding 32 (according to the ASCII standard) and then rotated
		else if(element >= 'A' && element <= 'Z'){
			element = element + rotationkey + 32;
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