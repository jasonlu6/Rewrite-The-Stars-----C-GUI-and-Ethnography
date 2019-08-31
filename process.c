/* 
This is a program that uses basic machine learning (cosine similarity) to determine 
if the horoscopes are compatiable with each other with another metric. In addition, 
this program also writes out to a text file called "compatability.txt", whose 
information will be the basis for the GUI part of the Rewrite The Stars Ethnographic 
assignment. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>


// Function to read in adjective input for each person. 

void read_adjective(const char* person) {
     char adj[200];
	for (int i = 0; i < 10; i++) { 
     		scanf("Adjectives: " );
        }
     printf("Your adjectives were: %s\n", adj);
}


// Function to read in the persons.txt. 

int read_textfile() {
     char ch, file[100];
     FILE *fp;

     printf("Enter the name of file for compatability:\n");
     gets(file); 

     fp  = fopen(file, "r"); // read the file. 

     if (fp == NULL) {
	perror("File not found.\n");
        exit(EXIT_FAILURE);
     }

     printf("File contents of file %s:\n", file);

     while((ch = fgetc(fp)) != EOF) {
	printf("%c", ch);
     }    

     // close file pointer.
     fclose(fp);
     return 0;
}


// Function to calculate cosine similarity & compatability. 
// Computed after GUI is completed.
int compatible_cos_sim() {
    return 0;

}

int main(int argc, char** argv) {
    // read_adjective("jason");
    read_textfile();
}
