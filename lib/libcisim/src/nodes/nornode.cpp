#include "cisim/nodes/nornode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NorNode> cisim::nodes::NorNode::registrar("NOR");

void cisim::nodes::NorNode::Run()
{

}

void cisim::nodes::NorNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::NorNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::NorNode::SetInputBit(const int index, Bit* const bit)
{
}
