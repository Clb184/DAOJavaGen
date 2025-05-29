#ifndef ENTITYDESCRIPTOR_INCLUDED
#define ENTITYDESCRIPTOR_INCLUDED
#include <string>
#include "json.hpp"

struct member_t {
	std::string member_type;
	std::string member_name;
};

struct entity_descriptor_t {
	std::string_view package_name = "";
	std::string_view name = "";
	std::string_view table_name = "";
	std::vector<member_t> members;
	std::vector<std::string_view> imports;
};

bool InitializeEntityDescriptor(nlohmann::json* json, entity_descriptor_t* descriptor);

#endif