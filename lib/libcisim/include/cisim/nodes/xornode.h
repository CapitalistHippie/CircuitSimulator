#ifndef _CISIM_NODES_XORNODE_H_
#define _CISIM_NODES_XORNODE_H_

#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

#include "cisim/events/onrunevent.h"

namespace cisim { namespace nodes
{
	/** @brief XorNode class.
	 *
	 * This class represents a XOR node in a circuit.
	 */
	class XorNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<XorNode> registrar;

	public:
		Bit inputBit1 = Bit::BITSTATE_UNDEFINED;
		Bit inputBit2 = Bit::BITSTATE_UNDEFINED;

		void Run();
		bool HasAllInputBits();
		void SetNextInputBit(const Bit bit);
		void GetInputBits(void(*callback)(Bit bit));
	};
}}

#endif // _CISIM_NODES_XORNODE_H_
