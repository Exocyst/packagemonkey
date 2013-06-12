#include "globals.h"

/* returns non-zero value if the given file exists */
int file_exists(char * filename)
{
	FILE * fp = fopen(filename,"r");
	if (fp) {
		fclose(fp);
		return 1;
	}
	return 0;
}

int directory_exists(char * name)
{
	struct stat sts;
	if ((stat(name, &sts)) == -1) {
		return 0;
	}
	return 1;
}

/* returns teh extension of a filename */
void get_file_extension(char * filename, char * extension)
{
	int i, j, ctr=0;

	extension[0]=0;

	for (i = strlen(filename)-1; i >= 0; i--) {
		if (filename[i]=='.') break;
	}
	if (i > 0) {
		for (j = i+1; j < strlen(filename); j++) {
			extension[ctr++] = filename[j];
		}
		extension[ctr]=0;
	}
}

/* returns the last directory in the given tree */
void get_subdirectory(char * directory, char * subdirectory)
{
	int i, j, ctr=0;

	for (i = strlen(directory)-2; i >= 0; i--) {
		if (directory[i] == DIRECTORY_SEPARATOR) {
			break;
		}
	}

	if (i > 0) {
		for (j = i+1; j < strlen(directory); j++) {
			if (directory[j] != DIRECTORY_SEPARATOR) {
				subdirectory[ctr++] = directory[j];
			}
		}
	}
	else {
		for (j = 0; j < strlen(directory); j++) {
			if (directory[j] != DIRECTORY_SEPARATOR) {
				subdirectory[ctr++] = directory[j];
			}
		}
	}
	subdirectory[ctr] = 0;
}

/* returns non-zero value if the given string is a valid project name */
int valid_project_name(char * project_name)
{
	int i;

	for (i = 0; i < strlen(project_name); i++) {
		if (((project_name[i] < 'a') ||
			 (project_name[i] > 'z')) &&
			((project_name[i] < '0') ||
			 (project_name[i] > '9'))) {
			return 0;
		}
	}
	return 1;
}

/* returns a non-zero value if the given string is within the set of strings */
int match_string(char * str, char ** strings, int no_of_strings)
{
	int i;

	for (i = 0; i < no_of_strings; i++) {
		if (strcmp(str,strings[i])==0) {
			return 1;
		}
	}
	return 0;
}