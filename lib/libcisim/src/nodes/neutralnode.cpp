#include "cisim/nodes/neutralnode.h"

cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarHigh("INPUT_HIGH", BitState::BITSTATE_HIGH);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarLow("INPUT_LOW", BitState::BITSTATE_LOW);
cisim::nodes::NodeRegistrar<cisim::nodes::NeutralNode> cisim::nodes::NeutralNode::registrarProbe("PROBE");

cisim::nodes::NeutralNode::NeutralNode()
{
}

cisim::nodes::NeutralNode::NeutralNode(BitState bitState) : inputBit(bitState)
{
}

void cisim::nodes::NeutralNode::Run()
{

}
