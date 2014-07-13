#include <stdio.h>
#include <string.h>

#define MAX 20

int is_palindrome_iter(const char *);
int is_palindrome_rec(const char *);

int main(void){
  char str[] = "regninger";


  printf("Checking if %s is a palindrome..\n", str);

  if(is_palindrome_iter(str))
    printf("Iterative function: TRUE\n");
  else
    printf("Iterative function: FALSE\n");

  if(is_palindrome_rec(str))
    printf("Recursive function: TRUE\n");
  else
    printf("Recursive function: FALSE\n");


  return 0;
}

int is_palindrome_iter(const char *input){
  int j, i;
  char str[MAX];

  strcpy(str, input);

  for(i = 0, j = strlen(str); j - i > 0; i++, j--){
    if(str[i] != str[j - 1])
      return 0;
  }
  return 1;
}

int is_palindrome_rec(const char *input){
  char str[MAX];
  int x = strlen(input),
      isPalindrome = 1;

  strcpy(str, input);

  if(x <= 1)
    return 1;
  if(str[0] != str[x - 1])
    return 0;
  
  strncpy(str, input + 1, x - 2);
  str[x - 2] = '\0';

  return is_palindrome_rec(str);
}
