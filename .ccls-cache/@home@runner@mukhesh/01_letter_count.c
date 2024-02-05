# include <stdio.h>
# include <string.h>
#include <time.h>

int main(void) {
  clock_t start_time, end_time;
  double cpu_time_used;

  start_time = clock();

  char sentence[20];
  int number_of_letters = 0;
  printf("Enter a sentence: ");
  //scanf("%s", sentence);
  fgets(sentence, sizeof(sentence), stdin);
  for (int i=0; i<strlen(sentence); i++)
    if (sentence[i] !=  ' ')
      number_of_letters++;
  printf("\nThe number of letters in the given sentence are : %d\n", number_of_letters);

  end_time = clock();

  cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;


   printf("The execution time of your code is: %f seconds\n", cpu_time_used);

  return 0;
}

/* Obervations:
01. How to work with sentences having a space in between?

Output:
Case - 01
Enter a sentence: suraj
The number of letters in the given sentence are : 5

Case - 02  
Enter a sentence: suraj aravind
The number of letters in the given sentence are : 5

*/  


  

