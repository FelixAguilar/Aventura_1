/* función equivalente a strcomp() */
#include <stdio.h>

size_t my_strlen(const char * str);
int my_strcmp(const char *str1, const char *str2);

int main(){
    return 0;
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


size_t my_strlen(const char * str){
    size_t i;
    for(i = 0; *(str + i) != '\0'; i++){}
    return i;
}

