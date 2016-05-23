#ifndef _CISIM_NODES_NODE_H_
#define _CISIM_NODES_NODE_H_

#include <iostream>

namespace cisim { namespace nodes
{
	class Node
	{
		friend std::istream& operator>>(std::istream& istream, Node& node);
	};

	std::istream& operator>>(std::istream& istream, Node& node);
}}

#endif // _CISIM_NODES_NODE_H_
