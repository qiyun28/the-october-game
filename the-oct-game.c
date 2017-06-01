#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64

#define DIS_RED(X) printf("%s%s%s", "\x1b[31m", X, "\x1b[0m");
#define DIS_GREEN(X) printf("%s%s%s", "\x1b[32m", X, "\x1b[0m");
#define DIS_BROWN(X) printf("%s%s%s", "\x1b[33m", X, "\x1b[0m");
#define DIS_BLUE(X) printf("%s%s%s", "\x1b[34m", X, "\x1b[0m");
#define DIS_MAGENTA(X) printf("%s%s%s", "\x1b[35m", X, "\x1b[0m");
#define DIS_CYAN(X) printf("%s%s%s", "\x1b[36m", X, "\x1b[0m");
#define PROMPT() printf(">");
#define PROMPT_CONT() printf("......");

int readProgress();
void saveProgress(int);
void puzzle1(void);
void puzzle2(void);
void puzzle3(void);
int puzzle4(void);
void puzzle5(void);
void puzzle6(void);
int puzzle7(int);
int puzzle8(void);
void puzzle9(void);

int main(void) {
	// select stage from profile
	int stage = readProgress();

	// play game
	int result = 0;
	switch(stage) {
		case 0 : 
		case 'A': puzzle1();
		case 'B': puzzle2();
		case 'C': puzzle3();
		case 'D': {
			saveProgress('D');
			result = puzzle4();
		}
		case 'E': puzzle5(); 
		case 'F': puzzle6();
		case 'G': {
			if (puzzle7(result) == 0) {
				result = 0;
				break;
			}
		}
		case 'H': {
			saveProgress('H');
			result = puzzle8();
			if (result == 0) {
				break;
			}
		}
		case 'I': puzzle9();
		default: // game passed
			DIS_RED("\n============  CONGRATULATIONS  ============\n");
			DIS_RED("You have won the game.\n");
			DIS_RED("You have found a clue to find the treasure.\n");
			DIS_RED("\x1b[1m117417\n\n");
			saveProgress('A');
	}
	
	// game failed
	if (result == 0) {
		DIS_RED("\n===============  GAME OVER  ===============\n");
		DIS_RED("Mama once said, life takes unexpected turns.\n\n");
	}
	
	return 0;
}

int readProgress() {
	FILE *in_file;
	in_file = fopen("profile.txt", "r");
	if (in_file == NULL) {
		return 0;
	} else {
		int file_status = fgetc(in_file);
		fclose(in_file);
		if(file_status == EOF)
			return 0;
		else
			return file_status;
	}
}

void saveProgress(int curr_stage) {
	FILE *out_file;
	out_file = fopen("profile.txt", "w");
	int file_status = fprintf(out_file, "%c\n", curr_stage);
	if(file_status == EOF){
		printf("save profile error.\n");
	}
	fclose(out_file);
}

void puzzle1(void) {
	DIS_MAGENTA("\n=========== NOTE: ===========\n"); 
	DIS_MAGENTA("Press ENTER to continue when you see ");
	printf("\"......\"\n");
	DIS_MAGENTA("Answer is required when you see ");
	printf("\">\"\n");
	DIS_MAGENTA("Enter all the answers in lower case.\n");
	PROMPT_CONT(); getchar();
	DIS_MAGENTA("\n    ======= STAGE 1 =======\n"); 
	char temp_asw[MAX_LEN];
	do {
		DIS_GREEN("Enter the password\n");
		PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
	} while (strcmp(temp_asw, "the password\n"));
}

void puzzle2(void) {
	DIS_MAGENTA("\n    ======= STAGE 2 =======\n"); 
	char temp_asw[MAX_LEN];
	do {
		DIS_GREEN("For every Y there are 12 M.\nThere are 168 H in every W.\nThere are 3600 S in each H.\n");
		PROMPT_CONT(); getchar();
		DIS_GREEN("If 1 W is equal to 7 D,\nand there are 365 D in a Y,\nhow many S are there in a D?\n");
		PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
	} while (strcmp(temp_asw, "86400\n"));
}

void puzzle3(void) {
	DIS_MAGENTA("\n    ======= STAGE 3 =======\n");
	char temp_asw[MAX_LEN];
	int count = 0;
	do {
		DIS_GREEN("Decrypt the following line: [HINT: caesar]\n");
		DIS_GREEN("\x1b[1m eua gxk znk gvvrk ot lxutz ul se lgik\n");
		PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
		count++;
		if(count == 5) {
			DIS_RED("[HINT: 6]\n");
			count = 0;
		}
	} while (strcmp(temp_asw, "you are the apple in front of my face\n"));
}

int puzzle4(void) {
	DIS_MAGENTA("\n    ======= STAGE 4 =======\n");
	char temp_asw;
	do {
		DIS_GREEN("There happens to be a few art exhibitions showcasing in the city,\n");
		DIS_GREEN("You decide to go for one of them.\n");
		PROMPT_CONT(); getchar();
		DIS_GREEN("Which one would you like to choose?\n");
		DIS_GREEN("a. Primary Structures: Younger American and British Sculptors\n");
		DIS_GREEN("b. Magritte and Contemporary Art: The Treachery of Images\n");
		DIS_GREEN("c. Gauguin to Picasso: Masterworks from Switzerland\n");
		DIS_GREEN("d. Bojack and Mr.Peanutbutter: Friend or Enemy?\n");
		PROMPT(); temp_asw = getchar(); getchar();
	} while (temp_asw != 'a' && temp_asw != 'b' && temp_asw != 'c' && temp_asw != 'd');
	switch (temp_asw){
		case 'a':
			DIS_MAGENTA("After watching the show, you feel satisfied and went home to sleep.\n");
			PROMPT_CONT(); getchar();
			return 1; break;
		case 'b': 
			DIS_MAGENTA("During the show, you found your favourite piece,\n");
			DIS_MAGENTA("and stared at it for quite a while.\n");
			PROMPT_CONT(); getchar();
			DIS_MAGENTA("It's \"The Son of Man\".\n");
			PROMPT_CONT(); getchar();
			return 0; break;
		case 'c':
			DIS_MAGENTA("After watching the show, ");
			DIS_MAGENTA("you were very impressed by the painting:\n");
			PROMPT_CONT(); getchar();
			DIS_MAGENTA("\"The Absinthe Drinker\".\n");
			PROMPT_CONT(); getchar();
			return 2; break;
		case 'd':
			DIS_MAGENTA("After watching the show, you feel like joking.\n");
			PROMPT_CONT(); getchar();
			DIS_MAGENTA("So you told yourself a joke and laughed.\n");
			PROMPT_CONT(); getchar();
			return 3; break;
		default: 
			printf("Apparently we ran in to some bug, or you are doing something malicious.\n");
			printf("Ask your girlfriend to fix the problem.\n");
			return 0;
	}
}

void puzzle5(void) {
    DIS_MAGENTA("\n    ======= STAGE 5 =======\n");
    DIS_GREEN("Erm there is actually no stage 5.\n");
    PROMPT_CONT(); getchar();
    DIS_GREEN("Congrats, you are going to stage 6.\n");
    PROMPT_CONT(); getchar();
}

void puzzle6(void) {
	DIS_MAGENTA("\n    ======= STAGE 6 =======\n");
    char temp_asw[MAX_LEN];
    int count = 0;
	do {
		DIS_GREEN("Decrypt the following line:\n");
		DIS_GREEN("\x1b[1m **** * / ** *** / -* *- -- * -** / *** *- -* --* * *-*\n");
		PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
		count++;
		if(count == 5) {
			DIS_RED("[HINT: morse]\n");
			count = 0;
		}
	} while (strcmp(temp_asw, "he is named sanger\n"));
}

int puzzle7(int prev_result) {
    DIS_MAGENTA("\n    ======= STAGE 7 =======\n");
    char temp_asw;
	do {
		DIS_GREEN("You decide to have a drink.\n");
		PROMPT_CONT(); getchar();
		DIS_GREEN("Which one would you like to choose?\n");
		DIS_GREEN("a. Guten Bourbon\n");
		DIS_GREEN("b. Choya Umeshu\n");
		DIS_GREEN("c. Soju\n");
		DIS_GREEN("d. Absinthe\n");
		PROMPT(); temp_asw = getchar(); getchar();
	} while (temp_asw != 'a' && temp_asw != 'b' && temp_asw != 'c' && temp_asw != 'd');
	switch (temp_asw){
		case 'a':
			prev_result *= 2; break;
		case 'b': 
			prev_result *= 1; break;
		case 'c':
			prev_result *= 1; break;
		case 'd':
			prev_result *= 3; break;
		default: 
			printf("Apparently we ran in to some bug, or you are doing something malicious.\n");
			printf("Ask your girlfriend to fix the problem.\n");
	}
	
	if (prev_result == 6) {
		DIS_RED("\n============  CONGRATULATIONS  ============\n");
		DIS_RED("There are 2 clues to find the treasure, you have found the hidden one.\n");
		DIS_RED("\x1b[1mF2206\n\n");
		PROMPT_CONT(); getchar();
	}
	if (prev_result == 0) {
		DIS_GREEN("You had your drink, you feel satisfied and went to sleep.\n");
		return 1;
	} else {
		DIS_GREEN("You had your drink, you feel that you made a wrong decision but could not remember why.\n");
		return 0;
	}
}

int puzzle8(void) {
	char temp_asw1;
    DIS_MAGENTA("\n    ======= STAGE 8 =======\n");
    DIS_GREEN("You are walking down the street, then you heard a familiar melody.\n");
    PROMPT_CONT(); getchar();
    do {
		DIS_GREEN("Would you like to find out who is singing?  [y/n]\n");
        PROMPT(); temp_asw1 = getchar(); getchar();
	} while (temp_asw1 != 'y' && temp_asw1 != 'n');
    if (temp_asw1 == 'y') {
    	DIS_MAGENTA("You spent too much time on finding it, and missed an important lecture.\n");
    	PROMPT_CONT(); getchar(); return 0;
    }
    do {
		DIS_GREEN("Would you like to find out what the song is?  [y/n]\n");
        PROMPT(); temp_asw1 = getchar(); getchar();
	} while (temp_asw1 != 'y' && temp_asw1 != 'n');
    if (temp_asw1 == 'n') {
    	DIS_MAGENTA("You have given up your passion for music.\n");
    	DIS_MAGENTA("Mama is so disappointed\n");
    	PROMPT_CONT(); getchar(); return 0;
    }
    
    char temp_asw2[MAX_LEN];
    int count = 0;
	DIS_GREEN("\n\x1b[1m ... ... ... .    .. . . .   ... ... ... ... . .  .. ... .   .  \n");
    DIS_GREEN("\x1b[1m 555 543 431 1-- 611 1-2 2-- 234 555 543 431 1-5 611 431 1-- 1--\n");
    
    do {
		DIS_GREEN("\nSo... What's the song?\n");
		PROMPT(); fgets(temp_asw2, MAX_LEN-1, stdin);
		count++;
		if(count == 5) {
			DIS_RED("[HINT: numbered musical notation]\n");
			count = 0;
		}
	} while (strcmp(temp_asw2, "piano man\n"));
	
	return 1;
}

void puzzle9(void) {
    DIS_MAGENTA("\n    ======= STAGE 9 =======\n");
    DIS_GREEN("You proceed to attend the lecture while humming the song.\n");
    PROMPT_CONT(); getchar();
    DIS_GREEN("You sit down with Qianqian and Melvin.\n");
    PROMPT_CONT(); getchar();
    DIS_GREEN("It seems like your lecturer decides to give you a puzzle to test your knowledge.\n");
    PROMPT_CONT(); getchar();
    DIS_GREEN("\x1b[1m\n B H C N A P O G R T\n");
    DIS_GREEN("\x1b[1m 0 0 1 0 0 0 1 0 1 0\n");
    DIS_GREEN("\x1b[1m 0 1 0 0 0 0 1 1 0 0\n");
    DIS_GREEN("\x1b[1m 1 0 0 1 0 1 0 1 0 0\n");
    DIS_GREEN("\x1b[1m 0 1 0 1 0 0 1 1 0 0\n");
    DIS_GREEN("\x1b[1m 1 0 0 0 0 0 0 0 1 1\n");
    DIS_GREEN("\x1b[1m 1 0 0 0 0 1 1 0 0 1\n");
    DIS_GREEN("\x1b[1m 1 1 0 1 1 0 0 0 0 0\n");
    DIS_GREEN("\x1b[1m 0 0 0 0 0 1 1 1 1 0\n");
    DIS_GREEN("\x1b[1m 0 0 0 0 1 1 1 0 1 0\n");
    
    char temp_asw[MAX_LEN];
    int count = 0;
    do {
		DIS_GREEN("\nSo... What's the answer?\n");
		PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
		count++;
		if (count == 5) {
			DIS_RED("[HINT: stage 6]\n");
			count = 0; 
		}
	} while (strcmp(temp_asw, "gcccaatct\n"));
}