#ifndef _CISIM_NODES_NEUTRALNODE_H_
#define _CISIM_NODES_NEUTRALNODE_H_

#include <memory>
#include <stdexcept>

#include "node.h"
#include "noderegistrar.h"

#include "cisim/bit.h"

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
		static NodeRegistrar<NeutralNode> registrarHigh;
		static NodeRegistrar<NeutralNode> registrarLow;
		static NodeRegistrar<NeutralNode> registrarProbe;

	public:
		/**
		 * The input bit.
		 */
		std::shared_ptr<Bit> inputBit;

		NeutralNode();
		NeutralNode(Bit bit);

		/**
		 * Runs the node.
		 */
		void Run();
		void Clear();
		void SetNextInputBit(Bit* const bit);
		void SetInputBit(const int index, Bit* const bit);
	};
}}

#endif // _CISIM_NODES_NEUTRALNODE_H_
