#ifndef _CISIM_NODES_NOTNODE_H_
#define _CISIM_NODES_NOTNODE_H_

#include <memory>
#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

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
		std::shared_ptr<Bit> inputBit;

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
		bool HasInputBits();
		bool HasUndefinedInputBits();
		void GetInputBits(void(*callback)(Bit* bit));
	};
}}

#endif // _CISIM_NODES_NOTNODE_H_
