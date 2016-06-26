#ifndef _CISIM_NODES_ANDNODE_H_
#define _CISIM_NODES_ANDNODE_H_

#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

#include "cisim/events/onrunevent.h"

namespace cisim { namespace nodes
{
	/** @brief AndNode class.
	 *
	 * This class represents an AND node in a circuit.
	 */
	class AndNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<AndNode> registrar;

	public:
		Bit inputBit1 = Bit::BITSTATE_UNDEFINED;
		Bit inputBit2 = Bit::BITSTATE_UNDEFINED;

		void Run();
		bool HasAllInputBits();
		void SetNextInputBit(const Bit bit);
		void GetInputBits(void(*callback)(Bit bit));
	};
}}

#endif // _CISIM_NODES_ANDNODE_H_
