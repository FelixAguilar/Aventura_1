/*
* Part 1
* ------
* Implementation of a set of functions analogous to the respective ones of
* <string.h>. they are strlen, strcmp, strcpy, strncpy and strcat.
*
* Part 2
* ------
* Implementation of a set of functions to create and modify an stack of
* elements and access propertys of the stack or save and load it from a file.
*
* Authors: Aguilar Ferrer, Felix Lluis
*          Bennasar Polzin, Adrian
*          Bueno Lopez, Alvaro
*
* Date:    01/10/2019.
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_lib.h"

/*
* Part 1
* ------
*/

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
    
    // It will contain the length of str.
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
* Copies the char string src until the position marked with n into the char
* string dest.
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
* adding src being the new end of the character string.
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

/*
* Part 2
* ------
*/

/*
* Function:  my_stack_init
* ------------------------
* Reserve space for the pointer for the top node of the stack and the size of
* the data it will hold, and initialize those values with NULL as the pointer
* value to the top node of the stack and with the size of data passed to it as
* parameter.
*
*  size: size of the data that will be inside the stack.
*
*  returns: the pointer of the stack created.
*/
struct my_stack *my_stack_init (int size){
    
    // Initialize stack and allocates memory to it.
    struct my_stack *stack;
    stack = (struct my_stack *) malloc (sizeof(struct my_stack));
    
    // If there is no memory available, then error.
    if (stack == NULL){
        printf("Error");
    }
    
    // Adds the values for the header of the stack.
    else{
        stack->size = size;
        stack->first = NULL;
    }
    return stack;
}

/*
* Function:  my_stack_push
* ------------------------
* Insert a new node into the stack at the begining of it. Returns 0 if it went
* well, -1 if there was an error.
*
*  stack: The pointer to the stack.
*  data: The pointer to the data for the node.
*
*  returns: 0 or -1 depending of the result.
*/
int my_stack_push (struct my_stack *stack, void *data){
    
    // It will check for the stack and size of data (init).
    int result = -1;
    if (stack != NULL) {
        if (stack->size > 0){
            
            // Allocates memory to the node.
            struct my_stack_node *node;
            node = (struct my_stack_node *) malloc(sizeof(struct my_stack_node)
                   /*+ stack->size*/);
            
            // If there is no memory available, then error.
            if (node == NULL) {
                printf("Error.");
            }
            
            // Add the node into the begining of the stack by moving pointers.
            else{
                node->data = data;
                node->next = stack->first;
                stack->first = node;
                
                // If it is correct it will return 0.
                result = 0;
            }
        }
    }
    return result;
}

/*
* Function:  my_stack_pop (struct my_stack *stack)
* ------------------------------------------------
* Deletes ("pops out") the node pointed by the "first" pointer of the stack that
* the user provides via parameter.
*
*  topNode: node that will be deleted.
*
*  returns: the pointer to the data of the deleted node.
*/
void *my_stack_pop (struct my_stack *stack){
    
    // If the stack is empty, there is no node to delete.
    if(stack->first != NULL){
        struct my_stack_node *topNode;
        
        // It creates a pointer to the node that will be deleted.
        topNode = stack->first;
        stack->first = topNode->next;
        
        // Returns the pointer to the data of the deleted node.
        void *data = topNode->data;
        
        // Free allocated memory of the deleted node.
        free(topNode);
        return data;
    }
    else{
        return NULL;
    }
}

/*
* Function:  my_stack_len
* -----------------------
* Returns the number of nodes inside the stack (length of the stack).
*
*  stack: The pointer to the stack.
*
*  returns: the number of nodes inside the stack.
*/
int my_stack_len (struct my_stack *stack){
    
    // Inicialize the counter at 0 and checks if there is at least one node.
    int size = 0;
    if (stack->first != NULL){
        
        // Creates a node pointing to the first node.
        struct my_stack_node *pointer;
        pointer = stack->first;
        
        // Goes over the stack adding 1 to size until it reaches the NULL.
        while (pointer != NULL){
            size++;
            pointer = pointer->next;
        }
    }
    return size;
}

int my_stack_write (struct my_stack *stack, char *filename){
    return 0;
}

struct my_stack *my_stack_read (char *filename){
    struct my_stack *stack;
    while((read(open(filename),filename,size)) != 0){
       void *data = read(open(filename),filename,size);
       my_stack_push(stack,data);
    }
    return stack;
}

/*
* Function:  my_stack_purge
* -------------------------
* It frees all memory that has been allocated with malloc() at any moment.
*
*  n: number of nodes that have been freed
*  size: number of nodes contained in the given stack
*
*  returns: n
*/
int my_stack_purge (struct my_stack *stack){
    int numNodos = 0;
    int bytesLiberados = 0;
    int size = my_stack_len(stack);
    while(numNodos < size){
          numNodos++;
          bytesLiberados += (stack->data)+(sizeof((node -> data)+(node -> next))); // size of data plus size of the 2 pointers(data and next) = 80
          free(stack -> data);
          free(stack -> node);
    }
    bytesLiberados = bytesLiberados + sizeof(int) + sizeof(stack->first);
    free(stack);
    return bytesLiberados;
}

