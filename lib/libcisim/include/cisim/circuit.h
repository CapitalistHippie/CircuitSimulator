#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <vector>
#include <memory>

#include "nodes/node.h"

namespace cisim
{
	/** @brief Circuit class.
	 *
	 * This class represents a circuit as given in a circuit file.
	 */
	class Circuit
	{
		friend std::istream& operator>>(std::istream& istream, Circuit& circuit);

	private:
		std::vector<std::shared_ptr<cisim::nodes::Node>> nodes;
	};
}

#endif // _CISIM_CIRCUIT_H_
