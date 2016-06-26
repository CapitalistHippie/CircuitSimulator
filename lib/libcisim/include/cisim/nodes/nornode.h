#ifndef _CISIM_NODES_NORNODE_H_
#define _CISIM_NODES_NORNODE_H_

#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

#include "cisim/events/onrunevent.h"

namespace cisim { namespace nodes
{
	/** @brief NorNode class.
	 *
	 * This class represents a NOR node in a circuit.
	 */
	class NorNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<NorNode> registrar;

	public:
		Bit inputBit1 = Bit::BITSTATE_UNDEFINED;
		Bit inputBit2 = Bit::BITSTATE_UNDEFINED;

		void Run();
		bool HasAllInputBits();
		void SetNextInputBit(const Bit bit);
		void GetInputBits(void(*callback)(Bit bit));
	};
}}

#endif // _CISIM_NODES_NORNODE_H_
