#ifndef _CISIM_CIRCUITBUILDER_H_
#define _CISIM_CIRCUITBUILDER_H_

#include <fstream>

#include "nomis/singleton.hpp"

#include "circuit.h"

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
}

#endif // _CISIM_CIRCUITBUILDER_H_
