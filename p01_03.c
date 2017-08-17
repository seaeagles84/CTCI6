#include <stdio.h>

/* 
   Second approach (more matched to the solution)
   without using of the replace function, 
   trying to going forward instead of backward seems quite tricky...
   so, going backward!
*/

void ConvertSpace(char *pstr, int true_length)
{
    int count_space = 0;
    int count = 0;
    
    for (int i = 0; i < true_length; i++)
        if (pstr[i] == ' ')
            count_space++;
            
    int index = true_length+2*count_space - 1; // the index right before the null character
    
    for (int i = true_length-1; i >=0; i--) {
        if (pstr[i] == ' ') {
            pstr[index - 0] = '0';
            pstr[index - 1] = '2';
            pstr[index - 2] = '%';
            index -= 3;
        } else {
            pstr[index] = pstr[i];
            index -= 1;
        }
    }
}

int main()
{
    //char input[] = "Mr Jaaaaohn Smith       ";
    //int true_length = 18;
    
    char input[] = "Mr Jaaaaohn Smith Halo     ";
    int true_length = 22;
    
    printf("Before: %s\n",input);
    ConvertSpace(input, true_length);
    printf("Aftere: %s\n",input);
    
    return (0);
}
