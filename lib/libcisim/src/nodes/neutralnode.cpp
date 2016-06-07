#include "cisim/nodes/neutralnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarHigh("INPUT_HIGH", Bit::BITSTATE_HIGH);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarLow("INPUT_LOW", Bit::BITSTATE_LOW);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarProbe("PROBE");

cisim::nodes::NeutralNode::NeutralNode()
{
}

cisim::nodes::NeutralNode::NeutralNode(Bit bitState) : inputBit(bitState)
{
}

void cisim::nodes::NeutralNode::Run()
{

}

void cisim::nodes::NeutralNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::NeutralNode::SetNextInputBit(Bit* const bit)
{
}

void cisim::nodes::NeutralNode::SetInputBit(const int index, Bit* const bit)
{
}
