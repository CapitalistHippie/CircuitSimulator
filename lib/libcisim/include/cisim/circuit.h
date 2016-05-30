#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <locale>
#include <algorithm>

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

	/**
	 * Parses an input stream into a Circuit object.
	 *
	 * @param circuit A reference to a Circuit object buffer.
	 * @return A reference to the istream object.
	 */
#ifndef CISIM_PUBLIC_HEADERS
	std::istream& operator>>(std::istream& istream, Circuit& circuit);
#endif
}

#endif // _CISIM_CIRCUIT_H_
