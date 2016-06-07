#ifndef _CISIM_NODES_NODE_H_
#define _CISIM_NODES_NODE_H_

#include <iostream>
#include <vector>

#include "cisim/bit.h"

namespace cisim { namespace nodes
{
	class Node
	{
	public:
		std::vector<Bit> outputBits;

		virtual ~Node() = default;
		virtual void Run() = 0;
	};

	std::istream& operator>>(std::istream& istream, Node& node);
}}

#endif // _CISIM_NODES_NODE_H_
