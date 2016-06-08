#include "cisim/nodes/neutralnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarHigh("INPUT_HIGH", Bit::BITSTATE_HIGH);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarLow("INPUT_LOW", Bit::BITSTATE_LOW);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarProbe("PROBE");

cisim::nodes::NeutralNode::NeutralNode()
{
}

cisim::nodes::NeutralNode::NeutralNode(Bit bit) : inputBit(new Bit(bit))
{
}

void cisim::nodes::NeutralNode::Run()
{
	if (*inputBit == Bit::BITSTATE_UNDEFINED)
		throw std::runtime_error("Input bit not set");

	outputBit = *inputBit;
}

void cisim::nodes::NeutralNode::Clear()
{
	inputBit.reset();
	Node::Clear();
}

void cisim::nodes::NeutralNode::SetNextInputBit(Bit* const bit)
{
	if (!inputBit)
		inputBit.reset(bit);
	else
		throw std::runtime_error("Input bit already set");
}

void cisim::nodes::NeutralNode::SetInputBit(const int index, Bit* const bit)
{
}
