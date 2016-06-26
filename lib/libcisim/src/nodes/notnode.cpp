#include "cisim/nodes/notnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NotNode> cisim::nodes::NotNode::registrar("NOT");

void cisim::nodes::NotNode::Run()
{
	if (!HasAllInputBits())
		throw std::runtime_error("Not every input bit has been set");

	outputBit = (inputBit == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_LOW : Bit::BITSTATE_HIGH;

	// Set the child nodes next input bit.
	for (auto& node: GetChildNodes())
		node.second->SetNextInputBit(outputBit);

	// Call the on run event.
	cisim::events::OnRunEvent event(this, outputBit);
	CallEvent(event);
}

bool cisim::nodes::NotNode::HasAllInputBits()
{
	return inputBit != Bit::BITSTATE_UNDEFINED;
}

void cisim::nodes::NotNode::SetNextInputBit(const Bit bit)
{
	if (inputBit == Bit::BITSTATE_UNDEFINED)
		inputBit = bit;
	else
		throw std::runtime_error("All input bits have already been set");
}

void cisim::nodes::NotNode::GetInputBits(void(*callback)(Bit bit))
{
	callback(inputBit);
}
