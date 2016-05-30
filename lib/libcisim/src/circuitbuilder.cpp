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

std::istream& cisim::operator>>(std::istream& istream, Circuit& circuit)
{
	std::string nodeIdentifier;

	// Read the node identifier.
	while (std::getline(istream, nodeIdentifier, ':'))
	{
		// # line is a comment.
		if (nodeIdentifier[0] == '#')
			continue;

		// First and second section are separated by a white line, break if found.
		if (nodeIdentifier == "\r\n")
			break;

		// Remove all the whitespace as it is irrelevant.
		nodeIdentifier.erase(std::remove_if(nodeIdentifier.begin(), nodeIdentifier.end(), isspace), nodeIdentifier.end());

		// Verify if it is a legitimate node identifier. (a-z,A-Z,_)
		auto found = nodeIdentifier.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_");
		if (found != std::string::npos)
		{
			// TODO: Throw or something.
		}

		// Get the node descriptor.
		std::string nodeDescriptor;
		std::getline(istream, nodeDescriptor, ';');

		// Remove all the whitespace again
		nodeDescriptor.erase(std::remove_if(nodeDescriptor.begin(), nodeDescriptor.end(), isspace), nodeDescriptor.end());

		// TODO: Verify if it is a legitimate node descriptor.

		std::cout << nodeIdentifier << ": " << nodeDescriptor << std::endl;
	}

	// Read second section.
//	while (std::getline(istream, line))
//	{
//		// # line is a comment.
//		if (line[0] == '#')
//			continue;
//
//		std::string nodeIdentifier;
//
//	}

	return istream;
}
