#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 64
#define INFO_NUM 3	//number of vars in profile_t

#define DIS_RED(X) printf("%s%s%s", "\x1b[31m", X, "\x1b[0m");
#define DIS_GREEN(X) printf("%s%s%s", "\x1b[32m", X, "\x1b[0m");
#define DIS_BROWN(X) printf("%s%s%s", "\x1b[33m", X, "\x1b[0m");
#define DIS_BLUE(X) printf("%s%s%s", "\x1b[34m", X, "\x1b[0m");
#define DIS_MAGENTA(X) printf("%s%s%s", "\x1b[35m", X, "\x1b[0m");
#define DIS_CYAN(X) printf("%s%s%s", "\x1b[36m", X, "\x1b[0m");
#define PROMPT() printf(">");
#define PROMPT_CONT() printf("......");

typedef struct {
	int stage;
	int infoA;
	int infoB;
} profile_t;

profile_t readProgress(void);
void saveProgress(profile_t);
int puzzle1(void);
int puzzle2(void);

int main(void) {
	// load user info from file
	profile_t user = readProgress();
	// print statement for debug
	printf("stage = %d, infoA = %d, infoB = %d.\n", user.stage, user.infoA, user.infoB);

	// play game
	int result = 0;
	switch(user.stage) {
		case 0 :
			DIS_MAGENTA("\n    ======= GAME START =======\n"); 
		case 1 : {
			user.stage = 1;
			saveProgress(user);
			if ((result = puzzle1()) == 0) break;
		}
		case 2 : {
			user.stage = 2;
			saveProgress(user);
			if ((result = puzzle2()) == 0 ) break;
		}
		default: {	// game passed
			// reset stage
			user.stage = 0;
			saveProgress(user);
			DIS_RED("\n============  CONGRATULATIONS  ============\n");
			DIS_RED("You have won the game.\n\n");
		}
	}

	// game failed
	if (result == 0) {
		DIS_RED("\n===============  GAME OVER  ===============\n");
		DIS_RED("Mama once said, life takes unexpected turns.\n\n");
	}

	return 0;
}

int puzzle1(void) {
	DIS_MAGENTA("\n    ======= STAGE 1 =======\n"); 
	char temp_asw[MAX_LEN];
	DIS_GREEN("Enter the password\n");
	PROMPT(); fgets(temp_asw, MAX_LEN-1, stdin);
	
	if(strcmp(temp_asw, "the password\n"))
		return 0;
	else
		return 1;
}

int puzzle2(void) {
	DIS_MAGENTA("\n    ======= STAGE 2 =======\n"); 
	DIS_GREEN("Enter the lucky number\n");
	PROMPT(); 
	int temp_asw;
	scanf("%d", &temp_asw);
	
	if(temp_asw == 0)
		return 1;
	else
		return 0;
}

profile_t readProgress(void) {
	FILE *infile;
	int temp[INFO_NUM];
	profile_t user;
	int i = 0;

	infile = fopen("profile.txt", "r");

	if (infile == NULL) {
		printf("File \"profile.txt\" doesn't exist, create a new one.\n");
		user.stage = 0;
		user.infoA = 0;
		user.infoB = 0;
	} else {
		while ((fscanf(infile, "%d", &temp[i]) != EOF) && (i < INFO_NUM)) {
			printf("Value read: %d\n", temp[i]);
			i++;
		}
		user.stage = temp[0];
		user.infoA = temp[1];
		user.infoB = temp[2];
	}

	fclose(infile);
	return user;
}

void saveProgress(profile_t user) {
	int file_status, i;
	FILE *out_file;
	out_file = fopen("profile.txt", "w");
	int temp[INFO_NUM] = {user.stage,user.infoA,user.infoA};

	for (i = 0; i < INFO_NUM; i++) {
		file_status = fprintf(out_file, "%d\n", temp[i]);
		if(file_status == EOF){
			printf("save profile error.\n");
			break;
		}
	}

	fclose(out_file);
}
