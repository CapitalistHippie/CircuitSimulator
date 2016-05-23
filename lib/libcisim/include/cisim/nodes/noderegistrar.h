#ifndef _CISIM_NODES_NODEREGISTRAR_H_
#define _CISIM_NODES_NODEREGISTRAR_H_

#include "nodefactory.h"

namespace cisim { namespace nodes
{
	template<typename NodeType>
	class NodeRegistrar
	{
	public:
		/**
		 * Registers a node type to the NodeFactory singleton.
		 *
		 * @param typeName The Node type to register.
		 */
		NodeRegistrar(const char* const typeName);
	};
}}

#endif // _CISIM_NODES_NODEREGISTRAR_H_
