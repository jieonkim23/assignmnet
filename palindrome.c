#include <stdio.h> 
/**
* @brief : Check if the given str is a palindrome
* @return: 1 if the given str is a palindrome, zero otherwise
* @param : str - pointers to the null-terminated byte string to check
*/
int ispalindrome(char *str)
{
    char *i=str;
    int len,j;
    for (len=0; *i; ++i,++len);

    for (j=0; j<len/2; ++j) 
    	if(*(str+len-j-1)!=*(str+j))
    		return 0;
    return 1;
}

int main(void)
{
    char buffer[1024];

    gets(buffer);
    printf("[%s] is ", buffer);
    if (ispalindrome(buffer))
        puts("a palindrome");
    else
        puts("not a palindrome");
    return 0;
}
