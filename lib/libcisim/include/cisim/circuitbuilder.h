#ifndef _CISIM_CIRCUITBUILDER_H_
#define _CISIM_CIRCUITBUILDER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <memory>

#include "nomis/singleton.hpp"

#include "circuit.h"
#include "nodes/nodefactory.h"
#include "exceptions/invalidcircuitfileformat.h"

namespace cisim
{
	/** @brief Circuit builder class.
	 *
	 * This class represents a circuit as given in a circuit file.
	 */
	class CircuitBuilder : public nomis::Singleton<CircuitBuilder>
	{
	public:
		/**
		 * Builds a Circuit object from a Circuit file.
		 *
		 * @param filePath Path to the Circuit file.
		 * @return Built Circuit object.
		 */
		Circuit BuildCircuit(const char* const filePath);
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

#endif // _CISIM_CIRCUITBUILDER_H_
