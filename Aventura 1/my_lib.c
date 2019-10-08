/*
* my_lib.c
*
* Implementation of a set of functions analogous to the respective ones of
* <string.h>. they are strlen, strcmp, strcpy, strncpy and strcat.
*
* Authors: Aguilar Ferrer, Felix Lluis
*          Bennassar Polzin, Adrian
*          Bueno Lopez, Alvaro
*
* Date:    01/10/2019.
*/

#include <stdio.h>

/*
* Function:  my_strlen
* --------------------
* Returns the length of the character string that finishes with "/0".
*
*  str: pointer of the character string that will return the length of it.
*
*  returns: length of the character string str.
*/

size_t my_strlen(const char * str){
    
    // It will contein the length of str.
    size_t length;
    
    // Counts the number of intercations until it finds the character "/0".
    for(length = 0; *(str + length) != '\0'; length++){}
    return length;
}

/*
* Function:  my_strcmp
* --------------------
* Looks character by character if they are the same. If not it returns the 
* subtraction of str1 with str2.
*
*  str1: pointer of the character string 1.
*  str2: pointer of the character string 2.
*
*  returns: 0 if its equal, negative if str1 is lower than str2 and positive if
*           str1 is higer than str2.
*/

int my_strcmp(const char *str1, const char *str2){

    // Obtain the size of both character strings.
    size_t sizeStr1 = my_strlen(str1);
    size_t sizeStr2 = my_strlen(str2);

    // Looks character by character.
    for(int index = 0; index < (sizeStr1 && sizeStr2) ; index++){
        
        // If they are not equal returns the subtraction.
        if((*(str1 + index)) != (*(str2 + index))){
            return *(str1 + index) - *(str2 + index);
        }
    }
    
    // If they are equal returns 0.
    return 0;
}

/*
* Function:  my_strcpy
* --------------------
* Copies the char string src into the char string dest.
*
*  dest: pointer of the character string where it will be copied the src.
*  str: pointer of the character string which will be copied in dest.
*
*  returns: pointer of the character string dest.
*/

char *my_strcpy(char *dest, const char *src){

    // Get the lenght of src.
    size_t sizeSrc = my_strlen(src);

    // Copies src into dest.
    for(int index=0; index < sizeSrc; index++){
        *(dest+index)= *(src+index);
    }

    // Add the final character '\0' into the end of the char string dest.
    *(dest+sizeSrc) = '\0';
    return dest;
}

/*
* Function:  my_strncpy
* ---------------------
* Copies the char string src until the position marked with n into the char string dest.
*
*  dest: pointer of the character string where it will be copied the src.
*  str: pointer of the character string which will be copied in dest.
*
*  returns: pointer of the character string dest.
*/

char *my_strncpy(char *dest, const char *src, size_t n){

    // Get the lenght of src.
    size_t sizeSrc = my_strlen(src);

    // Copies src into dest until reaching n.
    for(int index=0; (index < n)&&(index < sizeSrc); index++){
        *(dest+index)= *(src+index);
    }

    // Add the final character '\0' into the end of the char string dest.
    *(dest+n+1) = '\0';
    return dest;
}

/*
* Function:  my_strcat
* --------------------
* Add the character string src into the character string dest at the end of it.
* This overwrites the character "/0" at the end of dest and moves it after
* adding src beeing the new end of the character string.
*
*  dest: pointer of the character string where it will be added the src.
*  str: pointer of the character string which will be copied in dest.
*
*  returns: the pointer of the character string dest.
*/

char *my_strcat(char *dest, const char *src){
    
    // Obtain the size of both character strings.
    size_t sizeDest = my_strlen(dest);
    size_t sizeSrc = my_strlen(src);
    
    // Copies the src into the end of dest.
    for (int index = 0; index < sizeSrc; index++) {
        *(dest + sizeDest + index) = *(src + index);
    }
    
    // Adds the ending character into the character string.
    *(dest + sizeDest + sizeSrc) = '\0';
    return dest;
}
