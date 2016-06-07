#include "cisim/circuitbuilder.h"

cisim::Circuit cisim::CircuitBuilder::BuildCircuit(const char* const filePath)
{
	// Open the file.
	std::ifstream circuitFileStream;
	circuitFileStream.open(filePath);

	// Check if successfully opened.
	if (!circuitFileStream.is_open())
		throw std::runtime_error("Could not open file");

	// Parse circuit from file.
	Circuit circuit;
	circuitFileStream >> circuit;

	return circuit;
}

std::istream& cisim::operator>>(std::istream& istream, Circuit& circuit)
{
	// Clear the circuit.
	circuit.Clear();

	std::string line;

	// Read the first section.
	while (std::getline(istream, line))
	{
		// # line is a comment.
		if (line[0] == '#')
			continue;

		// First and second section are separated by a white line, break if found.
		if (line == "\r\n")
			break;

		// Remove any comment section in the line.
		auto index = line.find('#');
		if (index != std::string::npos)
			line.erase(index, std::string::npos);

		// Remove all the whitespace as it is irrelevant.
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

		// Get the node identifier.
		std::size_t location = line.find_first_of(':');
		if (location == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();
		std::string nodeIdentifier = line.substr(0, location);

		// Verify if it is a legitimate node identifier. (a-z,A-Z,0-9,_)
		auto found = nodeIdentifier.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_");
		if (found != std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();

		// Get the node descriptor.
		std::size_t nextLocation = line.find_first_of(';', location + 1);
		if (nextLocation == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();
		std::string nodeDescriptor = line.substr(location + 1, line.size() - location - 2);

		// TODO: Verify if it is a legitimate node descriptor.

		std::cout << nodeIdentifier << ": " << nodeDescriptor << std::endl;

		// Construct the node.
		auto node = nodes::NodeFactory::GetInstance().ConstructNode(nodeDescriptor.c_str());
		auto ret = circuit.nodes.emplace(nodeIdentifier, std::shared_ptr<nodes::Node>(node));
		if (ret.second == false) // Node already exists.
			throw exceptions::InvalidCircuitFileFormat();
	}

	// Read second (edge) section.
	while (std::getline(istream, line))
	{
		// # line is a comment.
		if (line[0] == '#')
			continue;

		std::string nodeSourceIdentifier;

	}

	return istream;
}
