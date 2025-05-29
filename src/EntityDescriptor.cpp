#include "EntityDescriptor.hpp"

bool InitializeEntityDescriptor(nlohmann::json* json, entity_descriptor_t* descriptor) {

	try {
		descriptor->name = json->at("name");
		descriptor->package_name = json->at("package_name");
		descriptor->table_name = json->at("table_name");
		for (auto& m : json->at("members")) {
			descriptor->members.emplace_back(m["type"], m["name"]);
		}
		for (auto& i : json->at("imports")) {
			descriptor->imports.emplace_back(i);
		}
	}
	catch (...) {
		return false;
	}
	return true;
}