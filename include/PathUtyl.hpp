#ifndef PATHUTYL_INCLUDED
#define PATHUTYL_INCLUDED

#include <direct.h>
#include <dirent.h>

bool CheckDir(const char* directory); // Check if directory exists
void CheckCreateExistsDir(const char* directory); // Pass a path and create the necessary folders

#endif