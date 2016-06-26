#include "cisim/nodes/node.h"

void cisim::nodes::Node::AddChildNode(std::string identifier, std::shared_ptr<cisim::nodes::Node> node)
{
	childNodes.emplace(identifier, node);
}

const std::map<std::string, std::shared_ptr<cisim::nodes::Node>>& cisim::nodes::Node::GetChildNodes()
{
	return childNodes;
}
