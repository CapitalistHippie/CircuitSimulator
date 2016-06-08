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
			if (node2.second->HasInputBits())
				node2.second->Run();
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
