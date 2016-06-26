#include "cisim/circuit.h"

void cisim::Circuit::Clear()
{
	nodes.clear();
}

void cisim::Circuit::Run()
{
	// Run all the nodes.
	for (auto node: nodes)
	{
		node.second->Run();
	}
}

void cisim::Circuit::GetNodes(void(*callback)(const char* identifier, cisim::nodes::Node* node))
{
	for (auto node: nodes)
	{
		callback(node.first.c_str(), node.second.get());
	}
}
