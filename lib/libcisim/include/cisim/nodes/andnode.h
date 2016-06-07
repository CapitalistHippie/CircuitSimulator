#ifndef _CISIM_NODES_ANDNODE_H_
#define _CISIM_NODES_ANDNODE_H_

#include <bitset>

#include "node.h"
#include "noderegistrar.h"

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

#endif // _CISIM_NODES_ANDNODE_H_
