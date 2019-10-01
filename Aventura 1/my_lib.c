//
//  my_lib.c
//  
//
//  Created by Felix on 01/10/2019.
//

#include <stdio.h>

size_t my_strlen(const char * str){
    size_t i;
    for(i = 0; *(str + i) != '\0'; i++){}
    return i;
}

char my_strcat(char *dest, const char *src){
    
}


