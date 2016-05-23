#ifndef _CISIM_NODES_INPUTNODE_H_
#define _CISIM_NODES_INPUTNODE_H_

#include <bitset>

#include "node.h"
#include "noderegistrar.h"

namespace cisim { namespace nodes
{
	/** @brief InputNode class.
	 *
	 * This class represents an input node in a circuit.
	 */
	class InputNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<InputNode> registrar;

	public:
		/**
		 * The input bit.
		 */
		std::bitset<1> inputBit;

		/**
		 * Runs the node.
		 */
		void Run();
	};
}}

#endif // _CISIM_NODES_INPUTNODE_H_
