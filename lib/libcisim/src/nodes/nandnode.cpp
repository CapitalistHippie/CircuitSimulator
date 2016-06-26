#include "cisim/nodes/nandnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NandNode> cisim::nodes::NandNode::registrar("NAND");

void cisim::nodes::NandNode::Run()
{
	if (!HasAllInputBits())
		throw std::runtime_error("Not every input bit has been set");

	outputBit = (inputBit1 == Bit::BITSTATE_HIGH && inputBit2 == Bit::BITSTATE_HIGH) ? Bit::BITSTATE_LOW : Bit::BITSTATE_HIGH;

	// Set the child nodes next input bit.
	for (auto& node: GetChildNodes())
		node.second->SetNextInputBit(outputBit);

	// Call the on run event.
//	cisim::events::OnRunEvent event(this, outputBit);
//	CallEvent(event);
}

bool cisim::nodes::NandNode::HasAllInputBits()
{
	return inputBit1 != Bit::BITSTATE_UNDEFINED && inputBit2 != Bit::BITSTATE_UNDEFINED;
}

void cisim::nodes::NandNode::SetNextInputBit(const Bit bit)
{
	if (inputBit1 == Bit::BITSTATE_UNDEFINED)
		inputBit1 = bit;
	else if (inputBit2 == Bit::BITSTATE_UNDEFINED)
		inputBit2 = bit;
	else
		throw std::runtime_error("All input bits have already been set");
}

void cisim::nodes::NandNode::GetInputBits(void(*callback)(Bit bit))
{
	callback(inputBit1);
	callback(inputBit2);
}
