#include "cisim/nodes/andnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::AndNode> cisim::nodes::AndNode::registrar("AND");

void cisim::nodes::AndNode::Run()
{

}

void cisim::nodes::AndNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::AndNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::AndNode::SetInputBit(const int index, Bit* const bit)
{
}
