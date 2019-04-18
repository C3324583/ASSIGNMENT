/* This program prints 6 messages to the screen, prompting the user to select one of the 6 tasks for the program to 
complete by typing an integer between 1 and 6. This integer is stored in the variable n, which decides which of the 
six distinct functions is called. Once the function is called, the program will interact with the user and allow
them to either encrypt or decrypt any message with either rotation or substitution cipher. */

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
    
    //initialisation of variables and arrays
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("Enter rotation key: ");//prompts the user to imput a rotation key
	scanf("%d", &rotationkey);//stores the rotation value in the variable "rotationkey"
	
	//This pair of "if" statements corrects rotation keys that are not between 0 and 25 and translates them into their corresponding key within the range
	if(rotationkey>25){
	    n = rotationkey / 26;
	    rotationkey = rotationkey - (26 * n);
	}
	else if(rotationkey<0){
	    n = -rotationkey / 26;
	    rotationkey = -rotationkey - (26 * n);
	    rotationkey = 26 - rotationkey;
	}
	
	//This for loop executes for all characters in the array "text" until the chracter occupying index i is a "NULL" character
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigns the value of "text" at index "i" to the variable element
		
		//Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element + rotationkey - 32;
			//If the rotation causes the element to have a value outside 'A'....'Z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element - 26;
			}
			text[i] = element; //storing the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is rotated by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element + rotationkey;
			//If the rotation causes the element to have a value outside 'A'....'Z' (according to the ASCII standard), 26 is subtracted to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element - 26;
			}
			text[i] = element; //stores the rotated letter back in the array "text"
		}
	}
	
	printf("Encrypted message: %s", text); //prints the rotated message to the screen
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTION WITH GIVEN ROTATION KEY
____________________________________________________________________________________________________________________*/


void RotationDecrypterWithKey(void){
    //initialisation of variables and arrays
	char text[1000], element;
	int n, i, rotationkey;
	
	printf("Enter message to decrypt: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("Enter rotation key: ");//prompts the user to imput a rotation key
	scanf("%d", &rotationkey);//stores the rotation value in the variable "rotationkey"
	
	//This pair or "if" statements corrects rotation keys that are not between 0 and 25 and translates them into their corresponding key within the range
	if(rotationkey>25){
	    n = rotationkey / 26;
	    rotationkey = rotationkey - (26 * n);
	}
	else if(rotationkey<0){
	    n = -rotationkey / 26;
	    rotationkey = -rotationkey - (26 * n);
	    rotationkey = 26 - rotationkey;
	}
	
	//This for loop executes for all characters in the array "text" until the chracter occupying index i is a "NULL" character
	for(i = 0; text[i] != '\0'; ++i){
		element = text[i]; //assigning the value of "text" at index "i" to the variable element
		
		//Each lowercase letter of the string is turned into UPPERCASE by subtracting 32 (according to the ASCII standard) and then rotated backwards by the "rotationkey"
		if(element >= 'a' && element <= 'z'){
			element = element - rotationkey - 32;
			//If the rotation causes the element to have a value outside 'A'....'Z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //stores the rotated letter back in the array "text"
		}
		
		//Each UPPERCASE letter is rotated backwards by the "rotationkey"
		else if(element >= 'A' && element <= 'Z'){
			element = element - rotationkey;
			//If the rotation causes the element to have a value outside 'A'....'Z' (according to the ASCII standard), 26 is added to give the rotated letter
			if(element > 'Z' || element < 'A'){
				element = element + 26;
			}
			text[i] = element; //stores the rotated letter back in the array "text"
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
        //initialisation of variables and arrays
	char text[1000], substitution[100];
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i;
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("Enter an alphabet substitution by typing 26 consecutive letters, where the first will replace A, the second will replace B and so on: ");//prompts the user to imput an alphabet substitution
	scanf("%s", substitution);//stores the alphabet substitution in the array "substitution"
    
    /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
     
        //prints the character at index "n" to the screen if it is not a letter
        if(text[n] < 'A' || text[n] > 'Z'){
                printf("%c", text[n]);
        }
        
        /* This loop tests if the character at index "n" is equal to any of the letters in the array "ALPHABET" 
        (index 0 to index 25), and if true, the character is substituted with the corresponding chracter in the 
        array "substitution" */
        for(i=0; i<26; i++){
            
            /* This "if" statement turns lowercase letters in the array "substitution" into UPPERCASE by subtracting
            32 before the substitution is done */
            if(substitution[i] >= 'a' && substitution[i] <= 'z'){
		        substitution[i] = substitution[i] - 32;
	        }
             
            /* This "if" statement tests if the charater in "text" at index "n" is equal to any character in 
            "ALPHABET" by running through all possible indices "i". If true, the character at the same index "i" of 
            "substitution" is printed to the screen */
            if (text[n] == ALPHABET[i]){
                printf("%c", substitution[i]);
            }
        }
    }
}






/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER DECRYPTION WITH GIVEN ALPHABET SUBSTITUTION
____________________________________________________________________________________________________________________*/


void SubstitutionDecrypterWithAlphabet(void){
    //initialisation of variables and arrays
	char text[1000], substitution[100];
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i;
	
	printf("Enter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("Enter an alphabet substitution by typing 26 consecutive letters, where the first will replace A, the second will replace B and so on: ");//prompts the user to imput an alphabet substitution
	scanf("%s", substitution);//stores the alphabet substitution in the array "substitution"
    
    /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
     
        //prints the character at index "n" to the screen if it is not a letter
        if(text[n] < 'A' || text[n] > 'Z'){
                printf("%c", text[n]);
        }
        
        /* This loop tests if the character at index "n" is equal to any of the letters in the array "substitution" 
        (index 0 to index 25), and if true, the character is substituted with the corresponding chracter in the 
        array "ALPHABET" */
        for(i=0; i<26; i++){
            
            /* This "if" statement turns lowercase letters in the array "substitution" into UPPERCASE by subtracting
            32 before the substitution is done */
            if(substitution[i] >= 'a' && substitution[i] <= 'z'){
		        substitution[i] = substitution[i] - 32;
	        }
             
            /* This "if" statement tests if the charater in "text" at index "n" is equal to any character in 
            "substitution" by running through all possible indices "i". If true, the character at the same index "i" of 
            "ALPHABET" is printed to the screen */
            if (text[n] == substitution[i]){
                printf("%c", ALPHABET[i]);
            }
        }
    }
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER DECRYPTION WITHOUT A GIVEN ALPHABET SUBSTITUTION
____________________________________________________________________________________________________________________*/


void SubstitutionDecrypterNoAlphabet(void){
    
}
