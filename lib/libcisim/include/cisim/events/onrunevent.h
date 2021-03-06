#ifndef _CISIM_EVENTS_ONRUNEVENT_H_
#define _CISIM_EVENTS_ONRUNEVENT_H_

#include <memory>

#include "cisim/nodes/node.h"
#include "cisim/bit.h"

#include "nomis/eh/event.hpp"

namespace cisim { namespace events
{
	/** @brief OnRunEvent class.
	 *
	 * Passed to the event callback when a node has been run.
	 */
	class OnRunEvent : public nomis::eh::Event
	{
	private:
		const cisim::nodes::Node* const node;
		const cisim::Bit value;

	public:
		OnRunEvent(const cisim::nodes::Node* const node, const cisim::Bit value);

		const cisim::nodes::Node* GetNode();
		cisim::Bit GetValue();
	};
}}

#endif // _CISIM_NODES_ANDNODE_H_
