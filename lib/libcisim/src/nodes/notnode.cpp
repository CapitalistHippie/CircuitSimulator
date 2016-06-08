#include "cisim/nodes/notnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NotNode> cisim::nodes::NotNode::registrar("NOT");

void cisim::nodes::NotNode::Run()
{
	if (*inputBit == Bit::BITSTATE_UNDEFINED)
		throw std::runtime_error("Input bit not set");

	outputBit = (*inputBit == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_LOW : Bit::BITSTATE_HIGH;
}

void cisim::nodes::NotNode::Clear()
{
	Node::Clear();
}

void cisim::nodes::NotNode::SetNextInputBit(Bit* const bit)
{
	if (!inputBit)
		inputBit.reset(bit);
	else
		throw std::runtime_error("Input bit already set");
}

void cisim::nodes::NotNode::SetInputBit(const int index, Bit* const bit)
{
}
