#include "PathUtyl.hpp"
#include "json.hpp"

/*
structure is the following:
controllers/
	-> CNameController.java
models/
	-> dao/
		-> INameDAO.java
	-> entities/
		-> CName.java
services/
	-> INameService.java
	-> CNameServiceImpl.java

*/

// Put the name of the JSON and it will fetch the different source file info
int main(int argc, char** argv) {

	// Print usage if no parameters passed
	if (argc < 2) {
		printf("Usage: daojavagen <json>");
		return -1;
	}

	// Create the structure first, so I don't have to waste performance later
	CheckCreateExistsDir("controllers/");
	CheckCreateExistsDir("models/dao/");
	CheckCreateExistsDir("models/entities/");
	CheckCreateExistsDir("services/");
}
