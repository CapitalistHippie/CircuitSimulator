#ifndef _CISIM_NODES_NODEFACTORY_H_
#define _CISIM_NODES_NODEFACTORY_H_

#include "nomis/singleton.hpp"

#include "node.h"

namespace cisim { namespace nodes
{
	class NodeFactory : nomis::Singleton<NodeFactory>
	{
	public:
		/**
		 * Constructs a Node object into the memory given by the nodeBuffer.
		 *
		 * @param type The Node type to construct.
		 * @param buffer Pointer to a memory location big enough to hold the to be constructed Node type.
		 * @return Buffer pointer.
		 *
		 * This class represents a circuit as given in a circuit file.
		 */
		Node* ConstructNode(const char* const type, Node* const buffer)
	};
}}

#endif // _CISIM_NODES_NODEFACTORY_H_
