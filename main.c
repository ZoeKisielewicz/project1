#include <stdio.h>    
//TODO add comments 
//TODO  sub cypher encrypt and decrypt  

char RotationEncrypt(char character, int shift);
char RotationDecrypt(char character, int shift);

int main(){
    int option;
    char character;
    int shift;
    printf("Enter 1 to encript a rotation cypher.\n");
    printf("Enter 2 to decript a rotation cypher.\n");
    scanf("%d", &option);
    
    switch(option){
    case 1: RotationEncrypt(character, shift); break;
    case 2: RotationDecrypt(character, shift); break;
    default: printf("Please only enter an option listed above");
    }

    return 0;
}

char RotationEncrypt(char character, int shift){
    char message[50];
    int i;
    
    printf("Enter message to encrypt: ");
    scanf("%s", message);
    printf("Enter amount of shifts: ");
    scanf("%d", &shift);
    for(i=0; message[i]!='\0';i++){
        character = message[i];
        if(character>='A'&&character<='Z'){
            character=character+shift;
        } if(character>'Z'){
            character=character-'Z'+'A'-1; 
        }
        message[i]=character;
    }
    printf("Encrypted message is: %s", message);
    return;
}

char RotationDecrypt(char character, int shift){
    char message[50];
    int i;
    
    printf("Enter message to dectrypt: ");
    scanf("%s", message);
    printf("Enter amount of shifts: ");
    scanf("%d", &shift);
    for(i=0; message[i]!='\0';i++){
        character = message[i];
        if(character>='A'&&character<='Z'){
            character=character-shift;
        } if(character<'A'){
            character=character+'Z'-'A'+1;
        }
        message[i]=character;
    }
    printf("Decrypted message is: %s", message);
    return;
}
