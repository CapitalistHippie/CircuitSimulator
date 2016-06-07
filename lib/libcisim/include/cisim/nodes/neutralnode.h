#ifndef _CISIM_NODES_NEUTRALNODE_H_
#define _CISIM_NODES_NEUTRALNODE_H_

#include <bitset>
#include <string>

#include "node.h"
#include "noderegistrar.h"

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
		static NodeRegistrar<NeutralNode> registrar;

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

#endif // _CISIM_NODES_NEUTRALNODE_H_
