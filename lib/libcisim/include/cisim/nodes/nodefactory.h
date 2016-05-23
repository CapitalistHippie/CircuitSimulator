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
		 * @param typeName The Node type to construct.
		 * @param buffer Pointer to a memory location big enough to hold the to be constructed Node type.
		 * @return Buffer pointer.
		 */
		Node* ConstructNode(const char* const typeName, Node* const buffer);
	};
}}

#endif // _CISIM_NODES_NODEFACTORY_H_
