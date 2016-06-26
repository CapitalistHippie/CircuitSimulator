#include "cisim/nodes/andnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::AndNode> cisim::nodes::AndNode::registrar("AND");

void cisim::nodes::AndNode::Run()
{
	if (!HasInputBits())
		throw std::runtime_error("Input bits not set");

	*outputBit = (*inputBit1 == Bit::BITSTATE_HIGH && *inputBit2 == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_HIGH : Bit::BITSTATE_LOW;
}

void cisim::nodes::AndNode::Clear()
{
	inputBit1.reset();
	inputBit2.reset();
	Node::Clear();
}

void cisim::nodes::AndNode::SetNextInputBit(Node* const node)
{
	if (!inputBit1)
		inputBit1 = node->outputBit;
	else if (!inputBit2)
		inputBit2 = node->outputBit;
	else
		throw std::runtime_error("All input bits already set");
}

void cisim::nodes::AndNode::SetInputBit(const int index, Bit* const bit)
{
}

bool cisim::nodes::AndNode::HasInputBits()
{
	if (!inputBit1 || !inputBit2)
		return false;
	return true;
}

bool cisim::nodes::AndNode::HasUndefinedInputBits()
{
	if (!HasInputBits())
		return false;
	if (*inputBit1 == Bit::BITSTATE_UNDEFINED || *inputBit2 == Bit::BITSTATE_UNDEFINED)
		return false;
	return true;
}

void cisim::nodes::AndNode::GetInputBits(void(*callback)(Bit* bit))
{
	callback(inputBit1.get());
	callback(inputBit2.get());
}
