#ifndef _CISIM_NODES_NODEFACTORY_H_
#define _CISIM_NODES_NODEFACTORY_H_

#include <map>
#include <functional>

#include "nomis/singleton.hpp"

#include "node.h"

namespace cisim { namespace nodes
{
	class NodeFactory : public nomis::Singleton<NodeFactory>
	{
		typedef std::map<std::string, std::function<Node*()>> NodeConstructorsMapType;

		template <typename NodeType>
		friend class HeaderRegistrar;

	public:
		static NodeConstructorsMapType& GetNodeConstructorsMap() noexcept;

	public:
		/**
		 * Constructs a Node object into the memory given by the nodeBuffer.
		 *
		 * @param typeName The Node type to construct.
		 * @return Pointer to the new object.
		 */
		cisim::nodes::Node* ConstructNode(const char* const typeName);
	};
}}

#endif // _CISIM_NODES_NODEFACTORY_H_
