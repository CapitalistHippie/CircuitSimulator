#ifndef _CISIM_NODES_NOTNODE_H_
#define _CISIM_NODES_NOTNODE_H_

#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

#include "cisim/events/onrunevent.h"

namespace cisim { namespace nodes
{
	/** @brief NotNode class.
	 *
	 * This class represents a NOT node in a circuit.
	 */
	class NotNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<NotNode> registrar;

	public:
		Bit inputBit = Bit::BITSTATE_UNDEFINED;

		void Run();
		bool HasAllInputBits();
		void SetNextInputBit(const Bit bit);
		void GetInputBits(void(*callback)(Bit bit));
	};
}}

#endif // _CISIM_NODES_NOTNODE_H_
