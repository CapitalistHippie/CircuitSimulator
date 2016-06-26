#ifndef _CISIM_NODES_NEUTRALNODE_H_
#define _CISIM_NODES_NEUTRALNODE_H_

#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

#include "cisim/events/onrunevent.h"

namespace cisim { namespace nodes
{
	/** @brief NeutralNode class.
	 *
	 * This class represents a neutral(without action) node in a circuit.
	 */
	class NeutralNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<NeutralNode> registrarHigh;
		static NodeRegistrar<NeutralNode> registrarLow;
		static NodeRegistrar<NeutralNode> registrarProbe;

	public:
		Bit inputBit = Bit::BITSTATE_UNDEFINED;

		NeutralNode();
		NeutralNode(Bit bit);

		void Run();
		bool HasAllInputBits();
		void SetNextInputBit(const Bit bit);
		void GetInputBits(void(*callback)(Bit bit));
	};
}}

#endif // _CISIM_NODES_NEUTRALNODE_H_
