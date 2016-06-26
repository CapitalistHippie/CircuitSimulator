#include "cisim/nodes/neutralnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarHigh("INPUT_HIGH", Bit::BITSTATE_HIGH);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarLow("INPUT_LOW", Bit::BITSTATE_LOW);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarProbe("PROBE");

cisim::nodes::NeutralNode::NeutralNode()
{
}

cisim::nodes::NeutralNode::NeutralNode(Bit bit) : inputBit(bit)
{
}

void cisim::nodes::NeutralNode::Run()
{
	if (!HasAllInputBits())
		throw std::runtime_error("Not every input bit has been set");

	outputBit = inputBit;

	// Set the child nodes next input bit.
	for (auto& node: GetChildNodes())
		node.second->SetNextInputBit(outputBit);

	// Call the on run event.
//	cisim::events::OnRunEvent event(this, inputBit);
//	CallEvent(event);
}

bool cisim::nodes::NeutralNode::HasAllInputBits()
{
	return inputBit != Bit::BITSTATE_UNDEFINED;
}

void cisim::nodes::NeutralNode::SetNextInputBit(const Bit bit)
{
	if (inputBit == Bit::BITSTATE_UNDEFINED)
		inputBit = bit;
	else
		throw std::runtime_error("All input bits have already been set");
}

void cisim::nodes::NeutralNode::GetInputBits(void(*callback)(Bit bit))
{
	callback(inputBit);
}
