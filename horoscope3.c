# include<stdio.h>
# include<stdlib.h>

int main() {
	int day, month;
       
        printf("Enter date (day):- ");
        scanf("%d", &day);

        printf("Enter month:- ");
        scanf("%d", &month);

        if (((month ==12) &&  (day >= 22)) || ((month == 1) && (day <= 19))) {
	    printf("\nCapicorn\n");
            char* answer;
            scanf("What is your favorite activity in January?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 1) &&  (day >= 20)) || ((month == 2) && (day <= 17))) {
	    printf("\nAquarius\n");
            char* answer;
            scanf("What is your favorite activity in February?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 2) &&  (day >= 18)) || ((month == 3) && (day <= 19))) {
	    printf("\nPisces\n");
            char* answer;
            scanf("What is your favorite activity in March?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 3) &&  (day >= 20)) || ((month == 4) && (day <= 19))) {
	    printf("\nAries\n");
            char* answer;
            scanf("What is your favorite activity in April?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 4) &&  (day >= 20)) || ((month == 5) && (day <= 20))) {
	    printf("\nTaurus\n");
            char* answer;
            scanf("What is your favorite activity in May?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 5) &&  (day >= 21)) || ((month == 6) && (day <= 20))) {
	    printf("\nGemini\n");
            char* answer;
            scanf("What is your favorite activity in June?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 6) &&  (day >= 21)) || ((month == 7) && (day <= 20))) {
	    printf("\nCancer\n");
            char* answer;
            scanf("What is your favorite activity in July?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
	// my birth month! 
        else if (((month == 7) &&  (day >= 23)) || ((month == 8) && (day <= 22))) {
	    printf("\nLeo\n");
            char* answer;
            scanf("What is your favorite activity in August?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 8) &&  (day >= 23)) || ((month == 9) && (day <= 22))) {
	    printf("\nVirgo\n");
            char* answer;
            scanf("What is your favorite activity in September?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 9) &&  (day >= 23)) || ((month == 10) && (day <= 22))) {
	    printf("\nLibra\n");
            char* answer;
            scanf("What is your favorite activity in October?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 10) &&  (day >= 23)) || ((month == 11) && (day <= 21))) {
	    printf("\nScorpio\n");
            char* answer;
            scanf("What is your favorite activity in November?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        }
        else if (((month == 11) &&  (day >= 20)) || ((month == 12) && (day <= 17))) {
	    printf("\nSagittarius\n");
            char* answer;
            scanf("What is your favorite activity in December?\n");
            printf("Your activity was: %s\n", answer);
	    exit(0);
        } else {
	    printf("\nInvalid Input");
	}
        return 0;
}
