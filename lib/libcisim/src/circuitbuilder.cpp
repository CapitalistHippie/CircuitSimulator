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
		if (line == "")
			break;

		// Remove any comment section in the line.
		auto index = line.find('#');
		if (index != std::string::npos)
			line.erase(index, std::string::npos);

		// Remove all the whitespace as it is irrelevant.
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

		// Get the node identifier.
		index = line.find_first_of(':');
		if (index == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();
		std::string nodeIdentifier = line.substr(0, index);

		// Verify if it is a legitimate node identifier. (a-z,A-Z,0-9,_)
		auto found = nodeIdentifier.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_");
		if (found != std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();

		// Get the node descriptor.
		std::size_t nextIndex = line.find_first_of(';', index + 1);
		if (nextIndex == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();
		std::string nodeDescriptor = line.substr(index + 1, line.size() - index - 2);

		// Construct the node.
		auto ret = circuit.nodes.emplace(nodeIdentifier, nodes::NodeFactory::GetInstance().ConstructNode(nodeDescriptor.c_str()));
		if (ret.second == false) // Node already exists.
			throw exceptions::InvalidCircuitFileFormat();

//		std::cout << nodeIdentifier << ": " << nodeDescriptor << std::endl;
	}

	// Read second (edge) section.
	while (std::getline(istream, line))
	{
		// # line is a comment.
		if (line[0] == '#')
			continue;

		// Remove any comment section in the line.
		auto index = line.find('#');
		if (index != std::string::npos)
			line.erase(index, std::string::npos);

		// Remove all the whitespace as it is irrelevant.
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());

		// Get the node source identifier.
		index = line.find_first_of(':');
		if (index == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat();
		std::string nodeSourceIdentifier = line.substr(0, index);

		// Check if the node has been defined.
		auto node = circuit.nodes.find(nodeSourceIdentifier);
		if (node == circuit.nodes.end())
			throw exceptions::InvalidCircuitFileFormat();

		// Loop through the node target identifiers.
		std::size_t nextIndex;
		do
		{
			nextIndex = line.find_first_of(",;", index + 1);

			std::string nodeTargetIdentifier = line.substr(index + 1, line.size() - nextIndex);
			std::cout << nodeTargetIdentifier << std::endl;

			index = nextIndex;

		} while (nextIndex != std::string::npos);
	}

	return istream;
}
