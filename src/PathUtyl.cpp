#include "PathUtyl.hpp"

// Check if directory exists
bool CheckDir(const char* directory) {
	if (DIR* dir = opendir(directory)) {
		closedir(dir);
		return true;
	}
	return false;
}

// Pass a path and create the necessary folders
void CheckCreateExistsDir(const char* directory) {
	size_t sz = strlen(directory);
	char* buffer = (char*)malloc(sz + 1);
	if (nullptr != buffer) {
		for (int i = 0; i < sz; i++) {
			if (directory[i] == '/' || directory[i] == '\\') {
				if (!CheckDir(buffer))
					mkdir(buffer);
			}
			buffer[i] = directory[i];
			buffer[i + 1] = 0;
		}
	}
	CheckDir(directory);
	free(buffer);
}
