#ifndef _CISIM_NODES_NOTNODE_H_
#define _CISIM_NODES_NOTNODE_H_

#include <vector>
#include <bitset>

#include "node.h"
#include "noderegistrar.h"

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
		/**
		 * The input bit.
		 */
		std::bitset<1> inputBit;

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
	};
}}

#endif // _CISIM_NODES_NOTNODE_H_
