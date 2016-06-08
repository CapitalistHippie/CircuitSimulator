#include "cisim/nodes/nornode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NorNode> cisim::nodes::NorNode::registrar("NOR");

void cisim::nodes::NorNode::Run()
{
	if (*inputBit1 == Bit::BITSTATE_UNDEFINED || *inputBit2 == Bit::BITSTATE_UNDEFINED)
		throw std::runtime_error("Input bits not set");

	outputBit = (*inputBit1 == Bit::BITSTATE_LOW && *inputBit2 == Bit::BITSTATE_LOW) ? Bit::BITSTATE_HIGH : Bit::BITSTATE_LOW;
}

void cisim::nodes::NorNode::Clear()
{
	inputBit1.reset();
	inputBit2.reset();
	Node::Clear();
}

void cisim::nodes::NorNode::SetNextInputBit(Bit* const bit)
{
	if (!inputBit1)
		inputBit1.reset(bit);
	else if (!inputBit2)
		inputBit2.reset(bit);
	else
		throw std::runtime_error("All input bits already set");
}

void cisim::nodes::NorNode::SetInputBit(const int index, Bit* const bit)
{
}
