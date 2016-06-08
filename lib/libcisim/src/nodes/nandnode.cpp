#include "cisim/nodes/nandnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NandNode> cisim::nodes::NandNode::registrar("NAND");

void cisim::nodes::NandNode::Run()
{
	if (!HasInputBits())
		throw std::runtime_error("Input bits not set");

	outputBit = (*inputBit1 == Bit::BITSTATE_HIGH && *inputBit2 == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_LOW : Bit::BITSTATE_HIGH;
}

void cisim::nodes::NandNode::Clear()
{
	inputBit1.reset();
	inputBit2.reset();
	Node::Clear();
}

void cisim::nodes::NandNode::SetNextInputBit(Bit* const bit)
{
	if (!inputBit1)
		inputBit1.reset(bit);
	else if (!inputBit2)
		inputBit2.reset(bit);
	else
		throw std::runtime_error("All input bits already set");
}

void cisim::nodes::NandNode::SetInputBit(const int index, Bit* const bit)
{
}

bool cisim::nodes::NandNode::HasInputBits()
{
	if (*inputBit1 == Bit::BITSTATE_UNDEFINED || *inputBit2 == Bit::BITSTATE_UNDEFINED)
		return false;
	return true;
}

void cisim::nodes::NandNode::GetInputBits(void(*callback)(Bit* bit))
{
	callback(inputBit1.get());
	callback(inputBit2.get());
}
