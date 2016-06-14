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
			throw exceptions::InvalidCircuitFileFormat("Could not find node identifier delimiter");
		std::string nodeIdentifier = line.substr(0, index);

		// Verify if it is a legitimate node identifier. (a-z,A-Z,0-9,_)
		auto found = nodeIdentifier.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_");
		if (found != std::string::npos)
			throw exceptions::InvalidCircuitFileFormat("Invalid node identifier");

		// Get the node descriptor.
		std::size_t nextIndex = line.find_first_of(';', index + 1);
		if (nextIndex == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat("Could not find node descriptor delimiter");
		std::string nodeDescriptor = line.substr(index + 1, line.size() - index - 2);

		// Construct the node.
		auto ret = circuit.nodes.emplace(nodeIdentifier, nodes::NodeFactory::GetInstance().ConstructNode(nodeDescriptor.c_str()));
		if (ret.second == false) // Node already exists.
			throw exceptions::InvalidCircuitFileFormat("Node already defined");
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
			throw exceptions::InvalidCircuitFileFormat("Could not find node source identifier delimiter");
		std::string nodeSourceIdentifier = line.substr(0, index);

		// Check if the source node has been defined.
		auto sourceNode = circuit.nodes.find(nodeSourceIdentifier);
		if (sourceNode == circuit.nodes.end())
			throw exceptions::InvalidCircuitFileFormat("Source node not defined");

		// Loop through the node target identifiers.
		std::size_t nextIndex = line.find_first_of(",;", index + 1);
		if (nextIndex == std::string::npos)
			throw exceptions::InvalidCircuitFileFormat("Could not find node target identifier delimiter");

		do
		{
			std::string nodeTargetIdentifier = line.substr(index + 1, line.size() - (line.size() - nextIndex) - index - 1);

			// Check if the target node has been defined.
			auto targetNode = circuit.nodes.find(nodeTargetIdentifier);
			if (targetNode == circuit.nodes.end())
				throw exceptions::InvalidCircuitFileFormat("Target node not defined");

			targetNode->second->SetNextInputBit(&sourceNode->second->outputBit);
			throw std::runtime_error("ayy lmao");

			index = nextIndex;
		} while ((nextIndex = line.find_first_of(",;", index + 1)) != std::string::npos);
	}

	// Check if every node has all its input bits.
	for (auto node: circuit.nodes)
	{
		if (!node.second->HasInputBits())
		{
			std::cout << node.first << ": " << node.second->HasInputBits() << std::endl;
			throw exceptions::InvalidCircuitFileFormat("Not all input bits defined.");
		}
	}

	return istream;
}
