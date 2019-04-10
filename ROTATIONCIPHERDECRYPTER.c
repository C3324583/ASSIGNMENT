#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialising variables
	char text[126], element;
	int n, i, rotationkey;
	
	printf("Enter message to be decrypted: ");//prompt the user to imput a message
	scanf(" %[^\n]s", text);//store the text imputted by the user in the array 'text'
	
	
	
	printf("Decrypted message: %s", text); //prints the rotated message to the screen
	
	return 0;
}

