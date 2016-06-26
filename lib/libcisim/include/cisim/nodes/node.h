#ifndef _CISIM_NODES_NODE_H_
#define _CISIM_NODES_NODE_H_

#include <string>
#include <map>
#include <memory>

#include "cisim/bit.h"

#include "nomis/eh/eventhandler.hpp"

namespace cisim { namespace nodes
{
	class Node : public nomis::eh::EventHandler
	{
	private:
		/**
		 * Collection of all the child nodes and their identifiers.
		 */
		std::map<std::string, std::shared_ptr<cisim::nodes::Node>> childNodes;

	public:
		Bit outputBit = Bit::BITSTATE_UNDEFINED;

		void AddChildNode(std::string identifier, std::shared_ptr<cisim::nodes::Node> node);
		const std::map<std::string, std::shared_ptr<cisim::nodes::Node>>& GetChildNodes();

		virtual ~Node() = default;

		/**
		 * Runs the node.
		 */
		virtual void Run() = 0;

		/**
		 * Checks whether all input bits have a value and are not undefined.
		 */
		virtual bool HasAllInputBits() = 0;

		/**
		 * Sets the next input bit.
		 */
		virtual void SetNextInputBit(const Bit bit) = 0;

		/**
		 * Gets all the input bits.
		 */
		virtual void GetInputBits(void(*callback)(Bit bit)) = 0;

	};
}}

#endif // _CISIM_NODES_NODE_H_
