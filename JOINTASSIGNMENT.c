/* This program prints 6 messages to the screen, prompting the user to select one of the 6 tasks for the program to 
complete by typing an integer between 1 and 6. This integer is stored in the variable n, which decides which of the 
six major functions is called. Once a function is called, the program will interact with the user and allow
them to either encrypt or decrypt any message with a rotation or substitution cipher. */

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
    printf("\nSelect one of the following options and then press <enter>:\n");
    printf("Type 1 to encrypt a message with a rotation cipher.\n");
    printf("Type 2 to decrypt a message encrypted with a rotation cipher, if the rotation key is known.\n");
    printf("Type 3 to decrypt a message encrypted with a rotation cipher, if the rotation key is NOT known.\n");
    printf("Type 4 to encrypt a message with a substitution cipher.\n");
    printf("Type 5 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is known.\n");
    printf("Type 6 to decrypt a message encrypted with a substitution cipher, if the alphabet substitution is NOT known.\n");
    scanf("%d", &n);//stores the integer inputted by the user in the variable n
    switch(n){  //this menu system runs one of 6 functions, depending on the value of n and then exits
        case 1: RotationEncrypter(); break;
        case 2: RotationDecrypterWithKey(); break;
        case 3: RotationDecrypterNoKey(); break;
        case 4: SubstitutionEncrypter(); break;
        case 5: SubstitutionDecrypterWithAlphabet(); break;
        case 6: SubstitutionDecrypterNoAlphabet(); break;
        default: printf("Please run again and select one of the listed options"); //if the user inputs anything that is not listed, the text is printed to the screen
    }
    printf("\n\n");
    return 0;
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER ENCRYPTION
____________________________________________________________________________________________________________________*/
//This function 
void RotationEncrypter(void){
    
    //initialisation of variables and arrays
	char text[10000], element;
	int n, i, rotationkey;
	
	printf("\nEnter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("\nEnter rotation key: ");//prompts the user to imput a rotation key
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
	
	printf("\nEncrypted message: %s", text); //prints the rotated message to the screen
}





/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTION WITH GIVEN ROTATION KEY
____________________________________________________________________________________________________________________*/


void RotationDecrypterWithKey(void){
    //initialisation of variables and arrays
	char text[10000], element;
	int n, i, rotationkey;
	
	printf("\nEnter message to decrypt: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("\nEnter rotation key (used to encrypt the message): ");//prompts the user to imput a rotation key
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
	
	printf("\nDecrypted message: %s", text); //prints the rotated message to the screen 
}






/*____________________________________________________________________________________________________________________
    FUNCTION FOR ROTATION CIPHER DECRYPTION WITHOUT A GIVEN ROTATION KEY
____________________________________________________________________________________________________________________*/


void rotation(int x, char text[]);
void rotationdefault(char text[]);


void RotationDecrypterNoKey(void){
 
    //initialisation of variables and arrays
	char text[100000];
	int number_of_letter[127] = {0};
	int n, i, x, ascii, first=0, second=0, third=0, fourth=0, fifth=0;
	
	printf("\nEnter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
   
   /*This for loop executes for all characters in the array "text" until the chracter occupying index i is a
    "NULL" character*/
    for(n=0; text[n]!='\0'; n++){
  
	    //turns lowercase letters in the array "text" into UPPERCASE by subtracting 32
     	if(text[n] >= 'a' && text[n] <= 'z'){
		    text[n] = text[n] - 32;
     	}
    }
    
	for(ascii='A'; ascii<='Z'; ascii++){
	    for(i=0; text[i] != '\0'; i++){
	        if(ascii==text[i]){
	            number_of_letter[ascii]++;
	        }
        } 
	}
	
	for (x=0; x<126; ++x){
	    if(number_of_letter[x] > number_of_letter[first]){
	        first = x;
	    }
	}
	
	for (x=0; x<126; ++x){
	    if(x != first && number_of_letter[x] <= number_of_letter[first] && number_of_letter[x] > number_of_letter[second]){
	        second = x;
	    }
	}
	
    for (x=0; x<126; ++x){
	    if(x != first && x != second && number_of_letter[x] <= number_of_letter[second] && number_of_letter[x] > number_of_letter[third]){
	        third = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && number_of_letter[x] <= number_of_letter[third] && number_of_letter[x] > number_of_letter[fourth]){
	        fourth = x;
	    }
	}	
	
	for (x=0; x<126; ++x){
	    if(x != first && x != second && x != third && x != fourth && number_of_letter[x] <= number_of_letter[fourth] && number_of_letter[x] > number_of_letter[fifth]){
	        fifth = x;
	    }
	}


    rotation(first, text);
    rotation(second, text);
    rotation(third, text);
    rotation(fourth, text);
    rotation(fifth, text);
    printf("\nMy code is crap but one of these will be correct:\n");rotationdefault(text);
}


void rotation(int x, char text[]){
    char txt[100000];
    for(int y=0;text[y] != '\0'; y++){
        txt[y]=text[y];
    }
    int rotationkey = x - 'E';
	int success;
    for(int i=0; txt[i] != '\0'; i++){
        if(txt[i] >= 'A' && txt[i] <= 'Z'){
    		txt[i] = txt[i] - rotationkey;
    		if(txt[i]>'Z'){
		        txt[i] = txt[i] - 26;
		    }
		    if(txt[i]<'A'){
		        txt[i] = txt[i] + 26;
		    }    
		}
    }

	printf("\nIs this the correct message?\n%s\n", txt); //prints the rotated message to the screen
	printf("\nYes - Press 1 and then <enter> \nNo - Press 0 and then <enter> \n");
	scanf("%d", &success);
	if(success == 1){
	    exit(0);
    }
}



//this function prints all possible rotation keys to the screen if the first function fails to find the correct rotation key
void rotationdefault(char text[]){
    char txt[100000];
    for(int y=0;text[y] != '\0'; y++){
        txt[y]=text[y];
    }

    for(int x=0; x<=25; x++){
        for(int i=0; txt[i] != '\0'; i++){
            if(txt[i] >= 'A' && txt[i] <= 'Z'){
        		txt[i] = txt[i] + 1;
    	    	if(txt[i]>'Z'){
    		        txt[i] = txt[i] - 26;
    		    }
    		}
	    }
	    printf("\n%s\n", txt);
    }
} 







/*____________________________________________________________________________________________________________________
    FUNCTION FOR SUBSTITUTION CIPHER ENCRYPTION
____________________________________________________________________________________________________________________*/


void SubstitutionEncrypter(void){
        //initialisation of variables and arrays
	char text[10000], substitution[100];
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i;
	
	printf("\nEnter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("\nEnter an alphabet substitution by typing 26 consecutive letters,\n");
	printf("where the first will replace A, the second will replace B and so on: \n");//prompts the user to imput an alphabet substitution
	scanf("%s", substitution);//stores the alphabet substitution in the array "substitution"
    printf("\nEncrypted message: ");
    
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
	char text[10000], substitution[100];
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i;
	
	printf("\nEnter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
	printf("\nEnter the alphabet substitution that was used to encrypby he message by typing 26 consecutive letters,\n");
	printf("where the first replaced A, the second replaced B and so on: \n");//prompts the user to imput an alphabet substitution
	scanf("%s", substitution);//stores the alphabet substitution in the array "substitution"
    printf("\nDecrypted message: ");
    
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
    //initialisation of variables and arrays
	char text[10000], substitution[100] = "NWLRBMQHCDAZOKYIUXJFEGPTVS";
	const char ALPHABET[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int n, i;
	
	printf("\nEnter message: ");//prompts the user to imput a message
	scanf(" %[^\n]s", text);//stores the text imputted by the user in the array "text"
    printf("\nDecrypted message: ");
    
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