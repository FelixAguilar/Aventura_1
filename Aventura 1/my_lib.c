//  my_lib.c
//
//  Created by Felix Aguilar Ferrer
//             Adrian Bennassar Polzin
//             Alvaro ...
//
//  on 01/10/2019.

#include <stdio.h>

size_t my_strlen(const char * str){
    size_t i;
    for(i = 0; *(str + i) != '\0'; i++){}
    return i;
}

int my_strcmp(const char *str1, const char *str2){
    
    for(int i=0; i < (my_strlen(str1)&&(my_strlen(str2)));i++){
        if((*(str1+i)) != (*(str2+i))){
            int resta = *(str1+i) - *(str2+i);
            return resta;
        }
    }
    return 0;
    
}

char *my_strcpy(char *dest, const char *src){
    size_t longitudSrc = my_strlen(src);
    for(int i=0; i < longitudSrc; i++){
        *(dest+i)= *(src+i);
    }
    *(dest+longitudSrc) = '\0';
    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n){
    size_t longitudSrc = my_strlen(src);
    for(int i=0; (i < n)&&(i < longitudSrc); i++){
        *(dest+i)= *(src+i);
    }
    *(dest+n+1) = '\0';
    return dest;
}

char *my_strcat(char *dest, const char *src){
    
    size_t d = my_strlen(dest);
    size_t s = my_strlen(src);
    
    for (int i = 0; i < s; i++) {
        *(dest+d+i) = *(src+i);
    }
    *(dest+d+s) = '\0';
    
    return dest;
}
