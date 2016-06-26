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
	if (!HasInputBits())
		throw std::runtime_error("Input bit not set");

	*outputBit = *inputBit;
}

void cisim::nodes::NeutralNode::Clear()
{
	inputBit.reset();
	Node::Clear();
}

void cisim::nodes::NeutralNode::SetNextInputBit(Node* const node)
{
	if (!inputBit)
		inputBit = node->outputBit;
	else
		throw std::runtime_error("Input bit already set");
}

void cisim::nodes::NeutralNode::SetInputBit(const int index, Bit* const bit)
{
}

bool cisim::nodes::NeutralNode::HasInputBits()
{
	if (!inputBit)
		return false;
	return true;
}

bool cisim::nodes::NeutralNode::HasUndefinedInputBits()
{
	if (!HasInputBits())
		return false;
	if (*inputBit == Bit::BITSTATE_UNDEFINED)
		return false;
	return true;
}

void cisim::nodes::NeutralNode::GetInputBits(void(*callback)(Bit* bit))
{
	callback(inputBit.get());
}
