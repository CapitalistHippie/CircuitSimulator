#include "cisim/nodes/xornode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::XorNode> cisim::nodes::XorNode::registrar("XOR");

void cisim::nodes::XorNode::Run()
{

}

void cisim::nodes::XorNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::XorNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::XorNode::SetInputBit(const int index, Bit* const bit)
{
}
