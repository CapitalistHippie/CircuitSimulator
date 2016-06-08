#ifndef _CISIM_NODES_NANDNODE_H_
#define _CISIM_NODES_NANDNODE_H_

#include <memory>
#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

namespace cisim { namespace nodes
{
	/** @brief NandNode class.
	 *
	 * This class represents a NAND node in a circuit.
	 */
	class NandNode : Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<NandNode> registrar;

	public:
		std::shared_ptr<Bit> inputBit1;
		std::shared_ptr<Bit> inputBit2;

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
	};
}}

#endif // _CISIM_NODES_NANDNODE_H_
