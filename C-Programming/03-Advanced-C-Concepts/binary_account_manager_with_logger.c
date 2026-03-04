#include <stdio.h> 
#include <string.h>
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

/* clientData structure definition */
struct clientData { 
 unsigned int acctNum; 
 char lastName[15]; 
 char firstName[10];
 double balance; 
}; 

void new_record(FILE *fp) {
	struct clientData client;
	unsigned int acctNum;
	
	/* user enters information, which is copied into file */
	printf("Enter account number (1 to 100): ");
	scanf("%d", &acctNum);
	
	/* seek position in file to user-specified record and read */
	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET); 
	fread(&client, sizeof(struct clientData), 1, fp);
	/* verify the record is empty */
	if (client.acctNum != 0)  {
		printf("account %d is not empty. Use update to change.\n", client.acctNum);
		return;
	}	

	client.acctNum = acctNum;
	/* read new record information */
	printf("Enter lastname, firstname, balance: ");
	scanf("%s %s %lf", client.lastName, client.firstName, &client.balance);

	/* write user-specified information in file */
	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET);
 	fwrite(&client, sizeof(struct clientData), 1, fp);
 	
 	log_message(INFO, "New record");	
 	
}

void update_record(FILE *fp){
	struct clientData client;
	unsigned int acctNum;
	
	/* user enters information, which is copied into file */
	printf("Enter account number (1 to 100): ");
	scanf("%d", &acctNum);
	
	/* seek position in file to user-specified record and read */
	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET); 
	fread(&client, sizeof(struct clientData), 1, fp);
	/* verify the record is empty */
	if (client.acctNum == 0)  {
		printf("account %d is empty. Use write to change.\n", acctNum);
		return;
	}	

	client.acctNum = acctNum;
	/* read new record information */
	printf("Enter lastname, firstname, balance: ");
	scanf("%s %s %lf", client.lastName, client.firstName, &client.balance);

	/* write user-specified information in file */
	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET);
 	fwrite(&client, sizeof(struct clientData), 1, fp);	
 	
 	log_message(INFO, "Record update");
}

void delete_record(FILE *fp) {
	struct clientData client, blankClient = { 0, "", "", 0.0 };
	unsigned int acctNum;
	
	/* user enters information, which is copied into file */
	printf("Enter account number (1 to 100): ");
	scanf("%d", &acctNum);
	
	/* seek position in file to user-specified record and read */
	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET); 
	fread(&client, sizeof(struct clientData), 1, fp);
	/* verify the record is empty */
	if (client.acctNum == 0)  {
		printf("account %d is already empty.\n", acctNum);
		return;
	}	

	fseek(fp, (acctNum - 1) *  sizeof(struct clientData), SEEK_SET); 
	fwrite(&blankClient, sizeof(struct clientData), 1, fp);	
	
	log_message(INFO, "Delete record");
}

void print_records(FILE *fp) {
	struct clientData client;
 	int i;	
	
	rewind(fp);
	for (i = 1; i <= 100; i++) {
		fread(&client, sizeof(struct clientData), 1, fp);
		if (client.acctNum)
			printf("%d:	%s	%s	%lf\n", client.acctNum, client.lastName, client.firstName, client.balance);		
	}
		
}

int main(void)
{ 
 	FILE *fp;
 	char c ='e';

	initialize_log();		/* start logging */	
	
 	/* fopen opens the file; exits if file cannot be opened */
 	if ((fp = fopen("accounts.dat", "rb+") ) == NULL) {
 		printf("File accounts.dat could not be opened.\n");
 		return 0;
 	} 
 	
	 /* loop to process user input until e specified */	
 	do {
 		if (c != '\n') 
  			printf("Enter a selection (w - write, p - print, d - delete, u - update, e - exit):");				 
 		scanf("%c", &c);
 		switch (c) {
 			case 'w': new_record(fp);
 				break;
 			case 'p': print_records(fp);
 				break;
 			case 'u': update_record(fp);
 				break;
  			case 'd': delete_record(fp);
 				break;
			case 'e': break;
			case '\n': break;
			default: printf("Invalid selection.\n");			
		 }
	 } while (c != 'e');
	
	fclose (fp); /* fclose closes the file */
	end_log();				/* end logging */
	return 0;
}


