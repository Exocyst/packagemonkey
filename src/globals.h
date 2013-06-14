/*
  packagemonkey - a package creation assistant
  Copyright (C) 2013  Bob Mottram <bob@robotics.uk.to>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define VERSION "0.10"

#define PROJECT_NAME "packagemonkey"

/* maximum size of a string */
#define BLOCK_SIZE 256

/* character used to separate directories */
#define DIRECTORY_SEPARATOR '/'

/* location for temporary files */
#define TEMP_DIRECTORY "/tmp"

/* separator used within the settings */
#define SETTINGS_SEPARATOR '\t'

/* commands */
#define COMMAND_MKDIR  "mkdir"
#define COMMAND_COPY   "cp"
#define COMMAND_DELETE "rm -f"
#define COMMAND_MOVE   "mv"

int file_exists(char * filename);
int directory_exists(char * directory);
void get_file_extension(char * filename, char * extension);
void get_subdirectory(char * directory, char * subdirectory);
int valid_project_name(char * project_name);
int match_string(char * str, char ** strings, int no_of_strings);
int valid_license(char * license);
int valid_email(char * email_address);
int valid_gpg(char * email_address);

#endif
