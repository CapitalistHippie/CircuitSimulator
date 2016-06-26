#include "cisim/nodes/nandnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NandNode> cisim::nodes::NandNode::registrar("NAND");

void cisim::nodes::NandNode::Run()
{
	if (!HasUndefinedInputBits())
		throw std::runtime_error("Undefined input bits");

	*outputBit = (*inputBit1 == Bit::BITSTATE_HIGH && *inputBit2 == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_LOW : Bit::BITSTATE_HIGH;
}

void cisim::nodes::NandNode::Clear()
{
	inputBit1.reset();
	inputBit2.reset();
	Node::Clear();
}

void cisim::nodes::NandNode::SetNextInputBit(Node* const node)
{
	if (!inputBit1)
		inputBit1 = node->outputBit;
	else if (!inputBit2)
		inputBit2 = node->outputBit;
	else
		throw std::runtime_error("All input bits already set");
}

void cisim::nodes::NandNode::SetInputBit(const int index, Bit* const bit)
{
}

bool cisim::nodes::NandNode::HasInputBits()
{
	if (!inputBit1 || !inputBit2)
		return false;
	return true;
}

bool cisim::nodes::NandNode::HasUndefinedInputBits()
{
	if (!HasInputBits())
		return false;
	if (*inputBit1 == Bit::BITSTATE_UNDEFINED || *inputBit2 == Bit::BITSTATE_UNDEFINED)
		return false;
	return true;
}

void cisim::nodes::NandNode::GetInputBits(void(*callback)(Bit* bit))
{
	callback(inputBit1.get());
	callback(inputBit2.get());
}
