#ifndef _CISIM_NODES_NODEFACTORY_H_
#define _CISIM_NODES_NODEFACTORY_H_

#include <map>
#include <functional>
#include <memory>

#include "nomis/singleton.hpp"

#include "node.h"
#include "cisim/exceptions/invalidnodetype.h"

namespace cisim { namespace nodes
{
	class NodeFactory : public nomis::Singleton<NodeFactory>
	{
		typedef std::map<std::string, std::function<Node*()>> NodeConstructorsMapType;

		template <typename NodeType>
		friend class HeaderRegistrar;

	public:
		static NodeConstructorsMapType& GetNodeConstructorsMap() noexcept;

		/**
		 * Constructs a Node object into the memory given by the nodeBuffer.
		 *
		 * @param typeName The Node type to construct.
		 * @return Shared pointer to the new object.
		 */
#ifndef CISIM_PUBLIC_HEADERS
		std::shared_ptr<Node> ConstructNode(const char* const typeName);
#endif
	};
}}

#endif // _CISIM_NODES_NODEFACTORY_H_
