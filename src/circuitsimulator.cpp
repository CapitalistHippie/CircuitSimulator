#include "circuitsimulator.h"

void CircuitSimulator::Run()
{
	nomis::Command command;
	do
	{
		std::cin >> command;
	} while (!HandleConsoleCommand(command));
}

bool CircuitSimulator::HandleConsoleCommand(const nomis::Command& command)
{
	if (!nomis::istrcmp(command.GetCommand(), "exit"))
		return true;
	else if (!nomis::istrcmp(command.GetCommand(), "loadcircuit"))
	{
		// If no parameters. Show some usage text.
		if (!command.GetAmountOfParameters())
		{
			std::cout << "Loads a circuit file." << std::endl
					<< "Usage: loadcircuit <file path>" << std::endl;
			return false;
		}

		// Open the file.
		std::ifstream circuitFileStream;
		circuitFileStream.open(command.GetParameter(0));

		// Check if successfully opened.
		if (!circuitFileStream.is_open())
		{
			std::cout << "Unable to open file." << std::endl;
			return false;
		}

		// Parse circuit from file.
		cisim::Circuit circuit;
		circuitFileStream >> circuit;

		// Put circuit with the others.
		circuits.push_back(circuit);
	}
	else
		std::cout << "Unknown command: " << command.GetCommand() << std::endl;
	return false;
}
