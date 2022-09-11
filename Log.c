#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#pragma warning(disable:4996)

void Log(char message[100]);
void NumbersFile(int num);
void LogError(char message[100]);
void LogEvent(char message[100]);

#define LogFile "Logfile.log"

time_t t;
struct tm* timeinfo;


int main() {
	time(&t);
	timeinfo = localtime(&t);
	LogEvent("Start of log And run");

	int num;
	printf("Please enter a number: ");
	scanf("%d", &num);
	
	char EnterdNum[100];
	sprintf(EnterdNum, "%s %d", "The user enterd the Number: ", num);
	LogEvent(EnterdNum);

	NumbersFile(num);
	
	
	LogEvent("End of log And run\n");
	return 0;
}

void Log(char message[100]) {
	
	FILE* f = fopen( LogFile , "a");
	if(!f){
		//LogError("File Not Opened");
	}
	else
	{
	char logstring[1000];
	sprintf(logstring, "%d.%d.%d:%d%d%d-%s", timeinfo->tm_year+1900, timeinfo->tm_mon+1, timeinfo->tm_wday+1, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec,message);
	fputs("\n", f);
	fputs(logstring, f);
	fclose(f);
	}
}

void NumbersFile(int num) {

	FILE* F = fopen("Numbers.txt", "a");

	if (!F) {
		LogError("Numbers File Not Opened");
	}
	else {

	LogEvent("Numbers file (named: Numbers.txt) opend with success");

	char numbers[1000];
	sprintf(numbers, "%d.%d.%d:%d%d%d- ", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_wday + 1, timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
	fputs(numbers, F);
	for (int i = 1; i <= num; i++)
	{
		sprintf(numbers, " %d ", i);
		fputs(numbers, F);

	}
	fputs("\n", F);
	fclose(F);
	LogEvent("Numbers.txt written and closed succesfully");
	}
}

void LogError(char message[100]) {

	char MSG[100];
	sprintf(MSG, "ERROR - %s", message);
	Log(MSG);

}

void LogEvent(char message[100]) {

	char MSG[100];
	sprintf(MSG, "Event - %s", message);
	Log(MSG);

}