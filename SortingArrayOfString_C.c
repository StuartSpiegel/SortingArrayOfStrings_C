/**
To sort a given array of strings into lexicographically
increasing order or into an order in which the string with the lowest length
appears first, a sorting function with a flag indicating the type of comparison strategy can be written.
The disadvantage with doing so is having to rewrite the function for every new comparison strategy.
A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.
---------------------------------------------------------------------------------
--> Given an array of strings, you need to implement a function which sorts the strings according to a comparison function,
--> i.e, you need to implement the function :
void string_sort(const char **arr,const int cnt, int (*cmp_func)(const char* a, const char* b)){
    <Code>
}
[args]:
an array of strings : arr
length of string array: count
pointer to the string comparison function: cmp_func
-------------------------------------------------------------------------------
You also need to implement the following four string comparison functions:

 --> to sort the strings in lexicographically non-decreasing order.

 --> to sort the strings in lexicographically non-increasing order.

 --> to sort the strings in non-decreasing order of the number of distinct characters present in them. If two strings have the same number of distinct characters present in them, then the lexicographically smaller string should appear first.

 --> to sort the strings in non-decreasing order of their lengths. If two strings have the same length, then the lexicographically smaller string should appear first.

Input Format

You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints

 No. of Strings : (1 <= n <= 50)
 Total Length of all the strings: (1 <= n <= 2500)
You have to write your own sorting function and you cannot use the inbuilt  function
The strings consists of lower-case English Alphabets only.

Author: Stuart Spiegel
HackerRank Challenege- Sorting Array Of String's
Date: 12/23/2019
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lexicographic_sort(const char* a, const char* b) {
  return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
  return strcmp(b, a);
}

//Utility function for counting number of chars in current comparison.
int countCurrentChars(const char *s){
  int start_count = 0;
  int count[128] = {0};
  if(NULL == s){
    return -1;
  }
  else{
    while(*s != '\0'){
      if(!count[*s]){
        count[*s]++;
        start_count++;
      }
      s++;
    } //end while

    return start_count;
  }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
  int comp = countCurrentChars(a) - countCurrentChars(b);
  return (comp ? comp : lexicographic_sort(a, b));
}

int sort_by_length(const char* a, const char* b) {
  int length = strlen(a) - strlen(b);
  return (length ? length : lexicographic_sort(a, b));
}
//Main function
void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int mid = len / 2;
    int curr = 0;
    while(!curr){
        curr = 1;
        for(int i = 0; i < len - 1; i++){
            if(cmp_func(arr[i], arr[i + 1]) > 0) {
                char *temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                curr = 0;
            }
        }
    }
}
//Driver code
int main(void){
    int n;
    scanf("%d", &n);

    char** arr; //pointer to the array of String's to be Sorted
	  arr = (char**)malloc(n * sizeof(char*)); //store the pointer on the stack,
    //dynamic memory on heap


    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char)); //compare current pointer with next index
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1); //update the memory
    }

    //Call String Sort Method in Order and Format COUT printf
    string_sort(arr, n, lexicographic_sort);
      for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
        printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
      for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
        printf("\n");

    string_sort(arr, n, sort_by_length);
      for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
        printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
      for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
        printf("\n");

}
