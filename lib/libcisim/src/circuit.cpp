#include "cisim/circuit.h"

void cisim::Circuit::Clear()
{
	nodes.clear();
}

void cisim::Circuit::Run()
{
	// Run all the nodes in reverse order.
	for (unsigned i = nodes.size(); i-- > 0; )
	{
		nodes.at(i).second->Run();
	}
}

void cisim::Circuit::GetNodes(void(*callback)(const char* identifier, cisim::nodes::Node* node))
{
	for (auto node: nodes)
	{
		callback(node.first.c_str(), node.second.get());
	}
}
