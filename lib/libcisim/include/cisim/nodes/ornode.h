#ifndef _CISIM_NODES_ORNODE_H_
#define _CISIM_NODES_ORNODE_H_

#include <memory>
#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

namespace cisim { namespace nodes
{
	/** @brief OrNode class.
	 *
	 * This class represents an OR node in a circuit.
	 */
	class OrNode : public Node
	{
	private:
		/**
		 * Registrar functor to register the node to the factory with.
		 */
		static NodeRegistrar<OrNode> registrar;

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
		bool HasUndefinedInputBits();
		void GetInputBits(void(*callback)(Bit* bit));
	};
}}

#endif // _CISIM_NODES_ORNODE_H_
