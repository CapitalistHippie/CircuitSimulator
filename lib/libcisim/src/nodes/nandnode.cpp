#include "cisim/nodes/nandnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NandNode> cisim::nodes::NandNode::registrar("NAND");

void cisim::nodes::NandNode::Run()
{

}

void cisim::nodes::NandNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::NandNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::NandNode::SetInputBit(const int index, Bit* const bit)
{
}
