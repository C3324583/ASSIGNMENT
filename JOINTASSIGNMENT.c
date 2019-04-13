#include <stdio.h>
#include <stdlib.h>

void RotationEncrypter(void);
void RotationDecrypterWithKey(void);
int main(){
    int n;
    printf("Select one of the following options and press enter:\n");
    printf("Type 1 to encrypt a message with a rotation cipher.\n");
    printf("Type 2 to decrypt a message encrypted with a rotation cipher, if the rotation key is known.\n");
    printf("Type 2 to decrypt a message encrypted with a rotation cipher, if the rotation key is NOT known.\n");
    printf("Type 3 to encrypt a message with a substitution cipher.\n");
    printf("Type 4 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is known.\n");
    printf("Type 4 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is NOT known.\n");
    scanf("%d", &n);
    switch(n){
        case 1: RotationEncrypter(); break;
        case 2: RotationDecrypterWithKey(); break;
        case 3: break;
        case 4: break;
        case 5: break;
        case 6: break;
        default: printf("Please run again and select one of the listed options");
    }
    return 0;
}


/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER ENCRYPTER
____________________________________________________________________________________________________________________*/

void RotationEncrypter(void){
    //initialising variables
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	printf("Enter rotation key: ");//prompt the user to imput a rotation key
	scanf("%d", &rotationkey);//store the rotation value in the variable 'rotation'
	
	//accounting for rotation keys that are not between 0 and 25 and translating them into their corresponding key within the range
	if(rotationkey>25){
	    n = rotationkey / 26;
	    rotationkey = rotationkey - (26 * n);
	}
	else if(rotationkey<0){
	    n = -rotationkey / 26;
	    rotationkey = -rotationkey - (26 * n);
	    rotationkey = 26 - rotationkey;
	}
	
	//this for loop executes the rotation for all letters in the array 'text' until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigning the value at index "i" of "text" to the variable element
		
		//Each lowercase letter of the string is rotated by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element + rotationkey;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'z' || element < 'a'){
				element = element - 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is turned into lowercase by by adding 32 (according to the ASCII standard) and then rotated by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element + rotationkey + 32;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'z' || element < 'a'){
				element = element - 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
	}
	
	printf("Encrypted message: %s", text); //prints the rotated message to the screen
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTER
____________________________________________________________________________________________________________________*/


void RotationDecrypterWithKey(void){
    
}




/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER ENCRYPTER
____________________________________________________________________________________________________________________*/





/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER ENCRYPTER
____________________________________________________________________________________________________________________*/