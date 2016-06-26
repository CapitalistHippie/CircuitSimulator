#include "onrunevent.h"

cisim::events::OnRunEvent::OnRunEvent(const cisim::nodes::Node* const node) : node(node)
{
}

const cisim::nodes::Node* const cisim::events::OnRunEvent::GetNode()
{
	return node;
}

cisim::Bit const cisim::events::OnRunEvent::GetValue()
{
	return value;
}
