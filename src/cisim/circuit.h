#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <string>
#include <vector>

namespace cisim
{
	/** \brief Circuit class.
	 *
	 * This class represents a circuit as given in a circuit file.
	 */
	class Circuit
	{
		friend std::istream& operator>>(std::istream& istream, Circuit& circuit);
	};

	/**
	 * Parses an input stream into a Circuit object.
	 *
	 * \param circuit A reference to a Circuit object buffer.
	 * \return A reference to the istream object.
	 */
	std::istream& operator>>(std::istream& istream, Circuit& circuit);
}

#endif // _CISIM_CIRCUIT_H_
