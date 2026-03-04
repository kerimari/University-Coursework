#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

enum LogLevel { INFO, WARNING, ERROR, CRITICAL };
char *level_string[] = {"INFO", "WARNING", "ERROR", "CRITICAL"};
FILE *fp_log;

void initialize_log() {
	if ((fp_log = fopen("logfile.txt", "a")) == NULL)  {
		printf("Error opening log file\n");
		exit(1);
	}
}

void end_log() {
	fclose(fp_log);
}

void log_message(enum LogLevel level, char *msg){
	char timestamp[20], line[255];
	time_t now = time(0);
	struct tm *timeinfo = localtime(&now);

	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);
	sprintf(line, "[%s] %s: %s\n", timestamp, level_string[level], msg);	
	fputs(line, fp_log); 
}

int main() 
{ 
	int c; 
	FILE *fp1, *fp3;
	
	initialize_log();		/* start logging */
	
	/* Open the files */
	if ((fp1 = fopen("chapter12_1.c", "r")) == NULL) {
		log_message(ERROR, "Cannot open chapter12_1.c file");
		return 0;
	}

	if ((fp3 = fopen("output3.txt", "w")) == NULL)  {
		log_message(ERROR, "Cannot create output3.txt file");
		return 0;
	}
	
	/* read file1 */	
	while ((c = fgetc(fp1)) != EOF)  {
		if (isupper(c))
			fputc(c, fp3); 
	} 	
 	log_message(INFO, "File read/write completed");	
	 	
	/* close files */
	fclose(fp1); 
	fclose(fp3);
	end_log();				/* end logging */	
	return 0; 
} 




