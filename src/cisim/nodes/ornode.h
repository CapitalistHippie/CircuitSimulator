#ifndef _CISIM_NODES_ORNODE_H_
#define _CISIM_NODES_ORNODE_H_

#include <bitset>

#include "node.h"
#include "noderegistrar.h"

namespace cisim { namespace nodes
{
	/** @brief OrNode class.
	 *
	 * This class represents an OR node in a circuit.
	 */
	class OrNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<OrNode> registrar;

	public:
		std::bitset<1> inputBit1;
		std::bitset<1> inputBit2;

		/**
		 * Runs the node.
		 */
		void Run();
	};
}}

#endif // _CISIM_NODES_ORNODE_H_
