#include "cisim/circuitbuilder.h"

cisim::Circuit cisim::CircuitBuilder::BuildCircuit(const char* const filePath)
{
	// Open the file.
	std::ifstream circuitFileStream;
	circuitFileStream.open(filePath);

	// Check if successfully opened.
	if (!circuitFileStream.is_open())
	{
		// TODO: Throw exception or something.
	}

	// Parse circuit from file.
	Circuit circuit;
	circuitFileStream >> circuit;

	return circuit;
}
