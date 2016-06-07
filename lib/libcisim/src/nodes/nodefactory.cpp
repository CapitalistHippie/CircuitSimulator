#include "cisim/nodes/nodefactory.h"

cisim::nodes::NodeFactory::NodeConstructorsMapType& cisim::nodes::NodeFactory::GetNodeConstructorsMap() noexcept
{
	static auto nodeConstructors = new NodeConstructorsMapType;
	return *nodeConstructors;
}

cisim::nodes::Node* cisim::nodes::NodeFactory::ConstructNode(const char* const typeName)
{
	auto iterator = GetNodeConstructorsMap().find(typeName);

	if (iterator != GetNodeConstructorsMap().end())
		return iterator->second();
	else
		return nullptr;
}
