#ifndef _CISIM_NODES_XORNODE_H_
#define _CISIM_NODES_XORNODE_H_

#include <bitset>

#include "node.h"
#include "noderegistrar.h"

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
		std::bitset<1> inputBit1;
		std::bitset<1> inputBit2;

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
	};
}}

#endif // _CISIM_NODES_XORNODE_H_
