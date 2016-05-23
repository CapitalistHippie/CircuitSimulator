#ifndef _CISIM_NODES_NORNODE_H_
#define _CISIM_NODES_NORNODE_H_

#include <bitset>

#include "node.h"
#include "noderegistrar.h"

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
		std::bitset<1> inputBit1;
		std::bitset<1> inputBit2;

		/**
		 * Runs the node.
		 */
		void Run();
	};
}}

#endif // _CISIM_NODES_NORNODE_H_
