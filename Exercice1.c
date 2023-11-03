#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfLastWord(char * s){
    
    int lenght=0, j = strlen(s);
    
    //enlever les espaces
    for(int i = strlen(s)-1 ; i>-1; i--)
    {
        if(s[i]>64)
        {
            break;
        }
         j--;
    }
    for(int i=j-1 ; i>-1; i--)
    {

        if(s[i]==' ')
        {
        return lenght; 
        }
        lenght++;
    }

    return lenght;
 
}
