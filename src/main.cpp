#include "PathUtyl.hpp"
#include "SourceCreator.hpp"
#include <fstream>

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
		printf("Usage: daojavagen <json>...");
		return -1;
	}

	// Create the structure first, so I don't have to waste performance later
	CheckCreateExistsDir("controllers/");
	CheckCreateExistsDir("models/dao/");
	CheckCreateExistsDir("models/entities/");
	CheckCreateExistsDir("services/");

	// The necessary stuff to load the JSON file
	std::ifstream file;

	for (int i = 1; i < argc; i++) {
		file.open(argv[i]);
		if (file.is_open()) {
			try {
				// JSON and decriptor that is going to be filled
				nlohmann::json json;
				entity_descriptor_t descriptor;

				json = nlohmann::json::parse(file);
				InitializeEntityDescriptor(&json, &descriptor);

				// Create the source files
				CreateEntitySource(descriptor);
				CreateControllerSource(descriptor);
				CreateDAOSource(descriptor);
				CreateInterfaceSource(descriptor);
				CreateImplementationSource(descriptor);
			}
			catch (std::exception e) {
				printf("Error while processing %s: %s \n", argv[i], e.what());
			}
			file.close();
		}
	}

	return 0;
}
