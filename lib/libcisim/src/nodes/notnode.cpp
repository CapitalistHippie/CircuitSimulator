#include "cisim/nodes/notnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NotNode> cisim::nodes::NotNode::registrar("NOT");

void cisim::nodes::NotNode::Run()
{

}

void cisim::nodes::NotNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::NotNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::NotNode::SetInputBit(const int index, Bit* const bit)
{
}
