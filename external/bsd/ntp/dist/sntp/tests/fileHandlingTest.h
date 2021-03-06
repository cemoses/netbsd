/*	$NetBSD: fileHandlingTest.h,v 1.3 2015/07/10 14:20:35 christos Exp $	*/

#ifndef FILE_HANDLING_TEST_H
#define FILE_HANDLING_TEST_H

#include "stdlib.h"
#include "sntptest.h"

#include <string.h>
#include <unistd.h>


enum DirectoryType {
	INPUT_DIR = 0,
	OUTPUT_DIR = 1
};

const char * CreatePath(const char* filename, enum DirectoryType argument) {
	
	 char * path = malloc (sizeof (char) * 256);

	/*
	if (m_params.size() >= argument + 1) {
		path = m_params[argument];
	}

	if (path[path.size()-1] != DIR_SEP && !path.empty()) {
		path.append(1, DIR_SEP);
	}
	*/
	//strcpy(path,filename);
	//path.append(filename);

	//return path;

	char cwd[1024];
	if (getcwd(cwd, sizeof(cwd)) != NULL)
		printf("Current working dir: %s\n", cwd);
	
	printf("builddir is   <.>\n");
	printf("abs_srcdir is </deacon/backroom/snaps/ntp-stable/sntp/tests>\n");
	strcpy(path,"/deacon/backroom/snaps/ntp-stable/sntp/tests/data/");

	//strcpy(path,"");
	strcat(path,filename);
	printf("PATH IS : %s\n",path);
	return path;
}

int GetFileSize(FILE *file) {

	fseek(file, 0L, SEEK_END);
	int length = ftell(file);
	fseek(file, 0L, SEEK_SET);
	
	//int initial = file.tellg();

	//file.seekg(0, ios::end);
	//int length = file.tellg();
	//file.seekg(initial);

	return length;
}

bool CompareFileContent(FILE* expected, FILE* actual) {
	int currentLine = 1;

	char actualLine[1024];
	char expectedLine[1024];
	size_t lenAct = sizeof actualLine;
	size_t lenExp = sizeof expectedLine;
	
	while (  ( (fgets(actualLine, lenAct, actual)) != NULL)
	      && ( (fgets(expectedLine, lenExp, expected)) != NULL )
	      ) {

		//printf("%s",actualLine);
		//printf("%s",expectedLine);
	
		if( strcmp(actualLine,expectedLine) !=0 ){
			printf("Comparision failed on line %d",currentLine);
			return FALSE;
		}

		//I removed this and modified the test kodFile.c, because there shouldn't be any ASSERTs in .h files!
		//TEST_ASSERT_EQUAL_STRING(actualLine,expectedLine);//EXPECT_EQ(expectedLine, actualLine) << "Comparision failed on line " << currentLine;
		currentLine++;
	}

	return TRUE;
}

void ClearFile(const char * filename) {
	FILE * clear = fopen(filename, "w");//ios::trunc); //similar to truncate, I GUESS???!
	
	//I removed this because there shouldn't be any ASSERTs in .h files!
	//TEST_ASSERT_TRUE(clear != NULL);
	fclose(clear);
}


#endif // FILE_HANDLING_TEST_H
