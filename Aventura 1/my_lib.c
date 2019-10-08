/*
* my_lib.c
*
* Implementation of a set of functions analogous to the respective ones of
* <string.h>. they are strlen, strcmp, strcpy, strncpy and strcat.
*
* Authors: Aguilar Ferrer, Felix Lluis
*          Bennassar Polzin, Adrian
*          Bueno Lopez, Alvaro
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
    
    // it will contein the length of str.
    size_t length;
    
    // Counts the number of intercations until it finds the character "/0".
    for(length = 0; *(str + length) != '\0'; length++){}
    return length;
}

/*
* Function:  my_strcmp
* --------------------
* Computes the length of the character string that finishes with "/0".
*
*  str: pointer of the character string.
*
*  returns: length of the character string.
*/

int my_strcmp(const char *str1, const char *str2){
    for(int i = 0; i < (my_strlen(str1) && (my_strlen(str2))); i++){
        if((*(str1 + i)) != (*(str2 + i))){
            return *(str1 + i) - *(str2 + i);
        }
    }
    return 0;
}

/*
* Function:  my_strcpy
* --------------------
* Computes the length of the character string that finishes with "/0".
*
*  str: pointer of the character string.
*
*  returns: length of the character string.
*/

char *my_strcpy(char *dest, const char *src){
    size_t longitudSrc = my_strlen(src);
    for(int i=0; i < longitudSrc; i++){
        *(dest+i)= *(src+i);
    }
    *(dest+longitudSrc) = '\0';
    return dest;
}

/*
* Function:  my_strncpy
* ---------------------
* Computes the length of the character string that finishes with "/0".
*
*  str: pointer of the character string.
*
*  returns: length of the character string.
*/

char *my_strncpy(char *dest, const char *src, size_t n){
    size_t longitudSrc = my_strlen(src);
    for(int i=0; (i < n)&&(i < longitudSrc); i++){
        *(dest+i)= *(src+i);
    }
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
    
    // Obtein the size of both character strings.
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
