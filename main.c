#include <stdio.h>    

void RotationEncrypt(char *Message, int Shift);
void RotationDecrypt(char *Message, int Shift);
void SubstitutionEncryption(char *Message);
void SubstitutionDecryption(char *Message);

int main(){
    
    int Option;
    char Message[50]; //Array to store the message entered in.
    int Shift; //Amount of shifts inputed by the user.
    
    printf("Please choose an option printed below.\n");
    printf("-Enter 1 to encript a rotation cypher.\n");
    printf("-Enter 2 to decript a rotation cypher.\n");
    printf("-Enter 3 to encript a substitution cypher.\n");
    printf("-Enter 4 to decript a substitution cypher.\n");
    scanf("%d", & Option);
    
    printf("Thankyou.\n"); //Manners 
    
    switch(Option){
    case 1: RotationEncrypt(Message, Shift); break;
    case 2: RotationDecrypt(Message, Shift); break;
    case 3: SubstitutionEncryption(Message); break;
    case 4: SubstitutionDecryption(Message); break;
    default: printf("Please enter an option listed above");

    }

    return 0;
}

void RotationEncrypt(char *Message, int Shift){
    
    char Character;
    int d; //Counter for each letter of the alphabet.
    
    printf("Please enter message to encrypt: ");
    scanf("%s", Message); //This stores the message entered in a string named message.
    printf("Please enter amount of shifts: ");
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

void RotationDecrypt(char *Message, int Shift){
    
    char Character;
    int d; //Counter for each letter of the alphabet.
    
    printf("Enter message to dectrypt: ");
    scanf("%s", Message); //This stores the message entered in a string named message.
    printf("Enter amount of shifts: ");
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

