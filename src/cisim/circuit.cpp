#include "circuit.h"

std::istream& cisim::operator>>(std::istream& istream, Circuit& circuit)
{
	std::string line;

	// Read first section.
	while (std::getline(istream, line))
	{
		// # line is a comment.
		if (line[0] == '#')
			continue;

		// First and second section are separated by a white line.
		if (line == "\r\n")
			break;

		// Erase all the whitespace as it is irrelevant.
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

		// Get the node identifier.
		std::size_t location = line.find_first_of(':');
		if (location == std::string::npos)
		{
			// TODO: Throw format error.
		}
		std::string nodeIdentifier = line.substr(0, location);

		// Get the node descriptor.
		std::size_t nextLocation = line.find_first_of(';', location + 1);
		if (nextLocation == std::string::npos)
		{
			// TODO: Throw format error.
		}
		std::string nodeDescriptor = line.substr(location + 1, line.size() - location - 1);

		std::cout << nodeIdentifier << ": " << nodeDescriptor << std::endl;
	}

	// Read second section.
	while (std::getline(istream, line))
	{
		// # line is a comment.
		if (line[0] == '#')
			continue;

		std::string nodeIdentifier;

	}

	return istream;
}
