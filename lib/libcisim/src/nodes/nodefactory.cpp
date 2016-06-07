#include "cisim/nodes/nodefactory.h"

cisim::nodes::NodeFactory::NodeConstructorsMapType& cisim::nodes::NodeFactory::GetNodeConstructorsMap() noexcept
{
	static auto nodeConstructors = new NodeConstructorsMapType;
	return *nodeConstructors;
}

std::shared_ptr<cisim::nodes::Node> cisim::nodes::NodeFactory::ConstructNode(const char* const typeName)
{
	auto iterator = GetNodeConstructorsMap().find(typeName);

	if (iterator != GetNodeConstructorsMap().end())
		return std::shared_ptr<nodes::Node>(iterator->second());
	else
		throw cisim::exceptions::InvalidNodeType();
}
