#include "onrunevent.h"

cisim::events::OnRunEvent::OnRunEvent(const cisim::nodes::Node* const node, const cisim::Bit value) : node(node), value(value)
{
}

const cisim::nodes::Node* cisim::events::OnRunEvent::GetNode()
{
	return node;
}

cisim::Bit cisim::events::OnRunEvent::GetValue()
{
	return value;
}
