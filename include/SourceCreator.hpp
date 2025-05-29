#ifndef SOURCECREATOR_INCLUDED
#define	SOURCECREATOR_INCLUDED

#include "EntityDescriptor.hpp"

// Entity
void CreateEntitySource(const entity_descriptor_t& descriptor);

// Controller
void CreateControllerSource(const entity_descriptor_t& descriptor);

// DAO
void CreateDAOSource(const entity_descriptor_t& descriptor);

// Service + Implementation
void CreateInterfaceSource(const entity_descriptor_t& descriptor);
void CreateImplementationSource(const entity_descriptor_t& descriptor);


#endif