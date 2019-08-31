/* 
 This program is the main program for the HCI Pre-Lecture Assignment 3: Rewrite the Stars. The functions 
consist of a Levensthein Edit Distance algorithm to determine compatability of horoscopes, an insert_word 
to count the frequency values of the song "Rewrite The Stars", from the Greatest Showman, to make an 
ethnological study of human compatability between two entities.

Author: Jason Lu (jasonlu968@gmail.com) 
Dates: 8/16/2019 - 9/02/2019 
*/ 


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#define MAXWORDS	10000
#define MAXSTRING	100

/* structure holding word frequency information */

typedef struct _word {
	char	s[MAXSTRING];	/* the Rewrite The Stars word count */
	int	count;		/* Frequency of each word.  */
} word;

/* 
 * This function inserts words into the word corpus, for edit distance compatability check. */
void insert_word (word *words, int *n, char *s) {
	int	i;

	/* linear search for the word */
	for (i=0; i<*n; i++) if (strcmp (s, words[i].s) == 0) {

		/* increment and return. */

		words[i].count++;
		return;
	}

	/* error conditions... */

	if (strlen (s) >= MAXSTRING) {
		fprintf (stderr, "word too long!\n");
		exit (1);
	}
	if (*n >= MAXWORDS) {	
		fprintf (stderr, "too many words!\n");
		exit (1);
	}

	/* copy the word into the structure at the first available slot,
	 * i.e., *n
	 */

	strcpy (words[*n].s, s);

	/* this word has occured once up to now, so count = 1 */

	words[*n].count = 1;

	/* one more word */

	(*n)++;
}

/* word comparsion function. */
int wordcmp (word *a, word *b) {
	if (a->count < b->count) return +1;
	if (a->count > b->count) return -1;
	return 0;
}

/* Map-reduce function to determine compatability in the horoscopes. */

struct horoscopes {
     char *a, *b, *c, *d, *e, *f, *g, *h, *i, *j, *k, *l;
};


/* distance function to calculate the Levenshtein edit-distance. */

int map_compatability(const char *word1, int len1, const char *word2, int len2) {
	int mat[len1 + 1][len2 + 1];
        int i;
        for (i = 0; i <= len1; i++) {
	    mat[i][0] = i;
	}
       
        for (i = 1; i <= len2; i++) {
            mat[0][i] = i;
        }

        for (i = 1; i <= len1; i++) {
	    int j;
            char c1;
         
        	c1 = word1[i-1];
                for (j = 1; j <= len2; j++) {
                    char c2;

  		    c2 = word2[j-1];
		    // match found!
                    if (c1 == c2) {
			mat[i][j] = mat[i-1][j-1];
                    } else {
			int d; // delete
			int ins; // insert
			int sub; // substiute
			int min; // DP part: minimum of delete, insert, substitute
				
			d = mat[i-1][j];
                        ins = mat[i][j-1]+1;
                        sub = mat[i-1][j-1] + 1;
			min = d;
       
			// Case 1: the edit distance is less than min, find smallest distance.
			if (ins < min) min = ins;
			if (sub < min) min = sub;
    			// set matrix to min 
			mat[i][j] = min;
			}
		}
	}
        // return the matrix
        return mat[len1][len2];
}

/* main program */
int main () {


	 // Read in the files and print out word frequencies. 

	 word       words[MAXWORDS];
	 // char	    s[128];
	 int i = 0;
         int n = 0;
         int m = 0;


	 // while (!feof(stdin)) {
	    // scanf("%s", s); 
	 // }

	 qsort((void *) words, n, sizeof(word), (int (*) (const void *, const void *)) wordcmp);

	 // if fewer than 100 words total, print first n words. 

	 if (n < 100) m = n;
	 else m = 100;

         // print words and their frequencies. 

         for (i = 0; i < m; i++) {
		printf("%s\t%d\n", words[i].s, words[i].count);
 	 }

         /* calculate the edit distance. */
	 const char* h1;
	 const char* h2;
         int dist;
         
         // hard-code for now.  
         h1 = "Leo: likes Fortnite, plays basketball, good at computer science.";
	 h2 = "Virgo: likes Blackpink, hates politics, likes Pokemon Go.";
	 int compatability = map_compatability(h1, strlen(h1), h2, strlen(h2));
         dist = compatability;
         
         // print out edit distance and compatability. 

         printf("The edit distance between %s and %s is %d.\n", h1, h2, dist);

         // determine compatability. 
         if (dist > 3) {
		printf("The two horoscopes are compatible. #RewriteTheStars!\n");
		compatability = 1;
	 } else {
		printf("The two horoscopes are not compatible. Cannot rewrite the stars.\n");
		compatability = 0;
         }
         return 0;
}
