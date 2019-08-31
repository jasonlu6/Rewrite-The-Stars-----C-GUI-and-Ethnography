// C program to get the frequency of each word from the "Rewrite The Stars" 
// song lyrics text file. The corpus will be the entire song, and the program 
// will read in the text file as stdin, and stdout a frequency table for 
// further analysis to HCI ethnographic applications. 

// Author: Jason Lu (jasonlu968@gmail.com) 
// Date: 8/26/2019 - 9/02/2019 
// HCI Pre Lecture Assignment 3

# include <stdio.h>
# include <string.h>
# include <stdlib.h> 
# include <ctype.h>

# define MAXWORDS       5000
# define MAXSTRING       128

// struct to hold the word frequency in "Rewrite the Stars" song. 
typedef struct _word {
        char    s[MAXSTRING];
        int     count;
} word;

// Function to put the word into a list of words. 
void insert_word(word *words, int *n, char *s) {
     int i;
     for (i = 0; i < n; i++) if (strcmp(s, words[i].s) == 0) {
	   words[i].count++;
           return;
	}

   /* error handling. */
   
   if (strlen(s) >= MAXSTRING) {
	fprintf(stderr, "Word is too long!\n");
        exit(1);
   } 
   
   if (*n >= MAXWORDS) {
	fprintf(stderr, "Too many words in text corpus!\n");
	exit(1);
   }

   // copy word into first available index of struct.
   strcpy(words[*n].s, s);
   words[*n].count = 1;
   (*n)++;
 }

/* Function to compare the words, with quicksort algorithm. */
int wordcmp(word *a, word *b) {
    if (a->count > b->count) return -1;
    if (a->count < b->count) return +1;
    return 0;
}

int main(int argc, char * argv[]) { 

// To do: fill in the main body function (and any helper functions) to make a frequency
// analytical chart of each common word in the textfile.)
     word words[MAXWORDS];
     char s[1000];
     int i,n,m;

     n = 0;
     /* read all words in file. */
     while (!feof(stdin)) {
       scanf("%s", s);
     }

     /* sort the list of words by descending frequency. */
     qsort((void *) words, n, sizeof (word), (int (*) const void *, const void *)) wordcmp);


     /* first 100 words. */ 
     if (n < 100) m = n;
     else m = 100;
     /* print words with their frequencies. */
     for (i = 0; i < m;i++) {
	printf("%s\t%d\n", words[i].s, words[i].count);
     } 
}
