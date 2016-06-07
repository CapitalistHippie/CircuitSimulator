#ifndef _CISIM_NODES_NODE_H_
#define _CISIM_NODES_NODE_H_

#include <iostream>
#include <vector>
#include <memory>

#include "cisim/bit.h"

namespace cisim { namespace nodes
{
	class Node
	{
	public:
		Bit outputBit = Bit::BITSTATE_UNDEFINED;

		virtual ~Node() = default;

		virtual void Run() = 0;
		virtual void Clear() = 0;
		virtual void SetNextInputBit(Bit* const bit) = 0;
		virtual void SetInputBit(const int index, Bit* const bit) = 0;
	};
}}

#endif // _CISIM_NODES_NODE_H_
