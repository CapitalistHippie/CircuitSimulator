#ifndef _CISIM_NODES_NODEREGISTRAR_H_
#define _CISIM_NODES_NODEREGISTRAR_H_

#include <string>
#include <map>
#include <functional>

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
			NodeFactory::GetNodeConstructorsMap().emplace(typeName, [](){ return (Node*)new NodeType(); });
		}

		template<typename... Args>
		NodeRegistrar(const char* const typeName, Args... args)
		{
			auto lambda = std::bind([=](Args... args){ return (Node*)new NodeType(args...); }, args...);

			NodeFactory::GetNodeConstructorsMap().emplace(typeName, lambda);
		}
	};
}}

#endif // _CISIM_NODES_NODEREGISTRAR_H_
