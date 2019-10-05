/* función equivalente a strncpy */
#include <stdio.h>

size_t my_strlen(const char * str);

int main(){
    return 0;
}

char *my_strncpy(char *dest, const char *src, size_t n){
 size_t longitudSrc = my_strlen(src);
 char stringCopiar[n];
 for(int i=0; (i < n)&&(i < longitudSrc); i++){
     stringCopiar[i] = *(src+i);
 }
    stringCopiar[n+1] = '\0';
    dest = stringCopiar;
    return dest;

}


size_t my_strlen(const char * str){
    size_t i;
    for(i = 0; *(str + i) != '\0'; i++){}
    return i;
}