#include <stdio.h>
#include <stdlib.h>

//function prototypes for the 6 tasks
void RotationEncrypter(void);
void RotationDecrypterWithKey(void);
void RotationDecrypterNoKey(void);
void SubstitutionEncrypter(void);
void SubstitutionDecrypterWithAlphabet(void);
void SubstitutionDecrypterNoAlphabet(void);

int main(){
    int n;
    printf("Select one of the following options and press enter:\n");
    printf("Type 1 to encrypt a message with a rotation cipher.\n");
    printf("Type 2 to decrypt a message encrypted with a rotation cipher, if the rotation key is known.\n");
    printf("Type 3 to decrypt a message encrypted with a rotation cipher, if the rotation key is NOT known.\n");
    printf("Type 4 to encrypt a message with a substitution cipher.\n");
    printf("Type 5 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is known.\n");
    printf("Type 6 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is NOT known.\n");
    scanf("%d", &n);
    switch(n){
        case 1: RotationEncrypter(); break;
        case 2: RotationDecrypterWithKey(); break;
        case 3: RotationDecrypterNoKey(); break;
        case 4: SubstitutionEncrypter(); break;
        case 5: SubstitutionDecrypterWithAlphabet(); break;
        case 6: SubstitutionDecrypterNoAlphabet(); break;
        default: printf("Please run again and select one of the listed options");
    }
    return 0;
}


/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER ENCRYPTION
____________________________________________________________________________________________________________________*/

void RotationEncrypter(void){
    
    //initialising variables
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array "text"
	printf("Enter rotation key: ");//prompt the user to imput a rotation key
	scanf("%d", &rotationkey);//store the rotation value in the variable "rotationkey"
	
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
	
	//this for loop executes the rotation for all letters in the array "text" until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigning the value of "text" at index "i" to the variable element
		
		//Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element + rotationkey - 32;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element - 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is rotated by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element + rotationkey;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element - 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
	}
	
	printf("Encrypted message: %s", text); //prints the rotated message to the screen
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTION WITH GIVEN ROTATION KEY
____________________________________________________________________________________________________________________*/


void RotationDecrypterWithKey(void){
        //initialising variables
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message to decrypt: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array "text"
	printf("Enter rotation key: ");//prompt the user to imput a rotation key
	scanf("%d", &rotationkey);//store the rotation value in the variable "rotationkey"
	
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
	
	//this for loop executes the rotation for all letters in the array "text" until the element occupying index i is empty
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigning the value of "text" at index "i" to the variable element
		
		//Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated backwards by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element - rotationkey - 32;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is rotated backwards by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element - rotationkey;
			//If the rotation causes the element to have a value outside 'a'....'z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
	}
	
	printf("The decrypted message is: %s", text); //prints the rotated message to the screen 
}




/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTION WITHOUT A GIVEN ROTATION KEY
____________________________________________________________________________________________________________________*/


void RotationDecrypterNoKey(void){
}


/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER ENCRYPTION
____________________________________________________________________________________________________________________*/


void SubstitutionEncrypter(void){
}

/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER DECRYPTION WITH GIVEN ALPHABET SUBSTITUTION
____________________________________________________________________________________________________________________*/



void SubstitutionDecrypterWithAlphabet(void){
    
}


/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER DECRYPTION WITHOUT A GIVEN ALPHABET SUBSTITUTION
____________________________________________________________________________________________________________________*/


void SubstitutionDecrypterNoAlphabet(void){
    
}