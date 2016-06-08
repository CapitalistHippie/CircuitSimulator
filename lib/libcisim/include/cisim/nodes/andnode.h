#ifndef _CISIM_NODES_ANDNODE_H_
#define _CISIM_NODES_ANDNODE_H_

#include <memory>
#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

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
		std::shared_ptr<Bit> inputBit1;
		std::shared_ptr<Bit> inputBit2;

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
		bool HasInputBits();
		void GetInputBits(void(*callback)(Bit* bit));
	};
}}

#endif // _CISIM_NODES_ANDNODE_H_
