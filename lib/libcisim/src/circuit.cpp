#include "cisim/circuit.h"

void cisim::Circuit::Clear()
{
	nodes.clear();
}

void cisim::Circuit::Run()
{
	for (auto node: nodes)
	{
		for (auto node2: nodes)
		{
			if (node2.second->HasUndefinedInputBits())
				node2.second->Run();
		}
	}

	// Check if every output bit was set.
	for (auto node: nodes)
	{
		if (node.second->HasUndefinedInputBits())
		{
			throw std::runtime_error("Result incomplete. Nodes incorrectly connected");
		}
	}
}

void cisim::Circuit::GetNodes(void(*callback)(const char* identifier, cisim::nodes::Node* node))
{
	for (auto node: nodes)
	{
		callback(node.first.c_str(), node.second.get());
	}
}

void cisim::Circuit::GetNodes(void(*callback)(const char* identifier, cisim::nodes::NeutralNode* node))
{
	for (auto node: nodes)
	{
		callback(node.first.c_str(), node.second.get());
	}
}
