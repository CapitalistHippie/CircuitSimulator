#include "cisim/nodes/nornode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NorNode> cisim::nodes::NorNode::registrar("NOR");

void cisim::nodes::NorNode::Run()
{
	if (!HasAllInputBits())
		throw std::runtime_error("Not every input bit has been set");

	outputBit = (inputBit1 == Bit::BITSTATE_LOW && inputBit2 == Bit::BITSTATE_LOW) ? Bit::BITSTATE_HIGH : Bit::BITSTATE_LOW;

	// Set the child nodes next input bit.
	for (auto& node: GetChildNodes())
		node.second->SetNextInputBit(outputBit);

	// Call the on run event.
//	cisim::events::OnRunEvent event(this, outputBit);
//	CallEvent(event);
}

bool cisim::nodes::NorNode::HasAllInputBits()
{
	return inputBit1 != Bit::BITSTATE_UNDEFINED && inputBit2 != Bit::BITSTATE_UNDEFINED;
}

void cisim::nodes::NorNode::SetNextInputBit(const Bit bit)
{
	if (inputBit1 == Bit::BITSTATE_UNDEFINED)
		inputBit1 = bit;
	else if (inputBit2 == Bit::BITSTATE_UNDEFINED)
		inputBit2 = bit;
	else
		throw std::runtime_error("All input bits have already been set");
}

void cisim::nodes::NorNode::GetInputBits(void(*callback)(Bit bit))
{
	callback(inputBit1);
	callback(inputBit2);
}
