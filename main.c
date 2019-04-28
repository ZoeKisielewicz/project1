#include <stdio.h>    

/*This code allows the user to select between four tasks. Each task is printed on the screen in a list format. Based on their choice,
the switch statements corresponding with their choice will call upon the appropriate function. This code requires user input in 
choosing the message to encrypt/ decrypt, the key for the substitution cypher, and the amounf of shifts required for the rotation 
cypher. */

void RotationEncrypt(char *Message, int Shift);
void RotationDecrypt(char *Message, int Shift);
void SubstitutionEncryption(char *Message);
void SubstitutionDecryption(char *Message);

int main(){
    
    int Option; //To hold the option the user wishes to complete.
    char Message[50]; //Array to store the message entered in.
    int Shift; //Amount of shifts inputed by the user.
    
    printf("Please choose an option printed below.\n"); //Printed menu for the user to choose which task they would like the code to complete.
    printf("-Enter 1 to encrypt a rotation cypher.\n");
    printf("-Enter 2 to decrypt a rotation cypher.\n");
    printf("-Enter 3 to encrypt a substitution cypher.\n");
    printf("-Enter 4 to decrypt a substitution cypher.\n");
    scanf("%d", & Option);
    
    printf("Thankyou.\n"); //Manners.
    
    switch(Option){ //Switch statement to call upon the appropriate functions that correspond with the users choice.
    case 1: RotationEncrypt(Message, Shift); break;
    case 2: RotationDecrypt(Message, Shift); break;
    case 3: SubstitutionEncryption(Message); break;
    case 4: SubstitutionDecryption(Message); break;
    default: printf("Please enter an option listed above");

    }

    return 0;
}

/*This function takes a message entered by the user and shifts each letter in the alphabet forward by the amount of shifts the user inputed.
This function is limited to a message 50 characters or under, in capital letters only. This function also does not read whitespace. */
void RotationEncrypt(char *Message, int Shift){
    
    char Character;
    int d; //Counter for each letter of the alphabet.
    
    printf("Please enter message to encrypt in capital letters, with no spaces: ");
    scanf("%s", Message); //This stores the message entered in a string named message.
    printf("Please enter amount of shifts (0-25): ");
    scanf("%d", &Shift); //This stores the amount of shifts the user wants each character of the alphabet to shift by.
    
    for(d=0; Message[d]!='\0'; d++){ //This loop runs untill the character of the array is 0.
        Character = Message[d]; //Stores each individual character of the message array in char character.
        if(Character >= 'A' && Character <= 'Z'){ //Loop works if the message entered contains the ASCII value of A-Z.
            Character = Character + Shift; //Adds 1 ASCII value to each individual character. 
        } if(Character > 'Z'){ //If the ASCII value of a character exceeds Z, this statement will get the character to start back at A.
            Character = Character - 'Z' + 'A' - 1; 
        }
        Message[d] = Character; //Returns the character to the array in order to encrypt/ decrypt the next character. 
    }
    
    printf("Encrypted message is: %s", Message); //Prints the encrypted message.
    
    return;
    
}

/*This function takes a message entered by the user and shifts each letter in the alphabet backwards by the amount of shifts the user inputed.
This function is limited to a message 50 characters or under, in capital letters only. This function also does not read whitespace. */
void RotationDecrypt(char *Message, int Shift){
    
    char Character;
    int d; //Counter for each letter of the alphabet.
    
    printf("Enter message to dectrypt in capital letters, with no spaces: ");
    scanf("%s", Message); //This stores the message entered in a string named message.
    printf("Enter amount of shifts (0-25): ");
    scanf("%d", &Shift); //This stores the amount of shifts the user wants each character of the alphabet to shift by.
    
    for(d=0; Message[d]!='\0'; d++){ //This loop runs untill the character of the array is 0.
        Character = Message[d]; //Stores each individual character of the message array in char character.
        if(Character >= 'A' && Character <= 'Z'){ //Loop works if the message entered contains the ASCII value of A-Z.
            Character = Character - Shift; //Subtracts 1 ASCII value to each individual character. 
        } if(Character < 'A'){ //If the ASCII value of a character exceeds befor A, this statement will get the character to wrap around to Z.
            Character = Character + 'Z' - 'A' + 1;
        }
        Message[d] = Character; //Returns the character to the array in order to encrypt/ decrypt the next character.
    }
    
    printf("Decrypted message is: %s", Message); //Prints the decrypted message.
    
    return;
    
}

/*This function takes a message entered by the user and compares each letter in the alphabet to the substitution key the user inputed.
It then replaces each letter of the message with the letter that corresponds it in the substitution key. This function is limited to 
a message 50 characters or under, in capital letters only. This function also does not read whitespace. */
void SubstitutionEncryption(char *Message){ 
    
    char OrigionalAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //This array will store the initial alphabet.
    char SubstitutionKey[26]; //This array will store the substitution key alphabet which has a limit of 26 characters e.g. QWERTYUIOPASDFGHJKLZXCVBNM. 
    int a; //This integer is used as a counter for the Alphabet. 
    int b; //This integer is used as a counter for the Substitution key.
    
    printf("Please enter a 26 letter substitution key in capital letters, with no repeating letters: ");
    scanf("%s", SubstitutionKey); //This stores the substitution key entered by the user in a string named SubstitutionKey.
    printf("Please enter a message to encrypt: ");
    scanf("%s", Message); //This stores the message entered by the user in a string named Message.
    
    for (a = 0; a < Message[a]; a++) { //This loop tests each letter at increment a for its position in the alphabet in relation to the message entered.
        for (b = 0; b < 26; b++) { //This loop tests each letter in the substitution alphabet at increment b.
            if (Message[a] == OrigionalAlphabet[b]) { //If characters in the message correspond with the letters in the origional alphabet. 
                Message[a] = SubstitutionKey[b]; //Replace each letter from the origional alphabet in the message with its corresponding character in the substitution key. 
                break;
            }          
        }
    } 
    
    printf("Encrypted substitution message is: %s", Message); //Prints the encrypted message.
    
    return;
    
}

/*This function takes a message entered by the user and compares each letter in the alphabet to the substitution key the user inputed.
It then replaces each letter of the message with the letter that corresponds it in the alphabet. This function is limited to 
a message 50 characters or under, in capital letters only. This function also does not read whitespace. */
void SubstitutionDecryption(char *Message){
    
    char OrigionalAlphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //This array will store the initial alphabet.
    char SubstitutionKey[26]; //This array will store the substitution key alphabet which has a limit of 26 characters e.g. QWERTYUIOPASDFGHJKLZXCVBNM. 
    int a; //This integer is used as a counter for the Alphabet. 
    int b; //This integer is used as a counter for the Substitution key.
   
    printf("Please enter a 26 letter substitution key in capital letters, with no repeating letters: ");
    scanf("%s", SubstitutionKey); //This stores the substitution key entered by the user in a string named SubstitutionKey.
    printf("Please enter a message to decrypt: ");
    scanf("%s", Message); //This stores the message entered by the user in a string named Message.
    
    for (a = 0; a < Message[a]; a++) { //This loop tests each letter at increment a for its position in the alphabet in relation to the message entered.
        for (b = 0; b < 26; b++) { //This loop tests each letter in the substitution alphabet at increment b.
            if (Message[a] == SubstitutionKey[b]) { //If characters in the message correspond with the letters in the origional substition key. 
                Message[a] = OrigionalAlphabet[b]; //Replace each letter from the substitution key in the message with its corresponding character in the alphabet. 
                break;
            }          
        }
    } 
   
    printf("Decrypted substitution message is: %s", Message); //Prints the decrypted message.
   
    return;
    
}

