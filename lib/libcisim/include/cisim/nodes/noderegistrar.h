#ifndef _CISIM_NODES_NODEREGISTRAR_H_
#define _CISIM_NODES_NODEREGISTRAR_H_

#include <string>
#include <map>

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
		NodeRegistrar(const char* const typeName)
		{
			NodeFactory::GetNodeConstructorsMap().insert(std::make_pair(typeName, [](){ return (Node*)new NodeType(); }));
		}
	};
}}

#endif // _CISIM_NODES_NODEREGISTRAR_H_
