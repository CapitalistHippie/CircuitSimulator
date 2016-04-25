#include "circuitsimulator.h"

void cisim::CircuitSimulator::Run()
{
	nomis::Command command;
	do
	{
		std::cin >> command;
	} while (!HandleConsoleCommand(command));
}

bool cisim::CircuitSimulator::HandleConsoleCommand(const nomis::Command& command)
{
	if (!nomis::istrcmp(command.GetCommand(), "exit"))
		return true;
	else if (!nomis::istrcmp(command.GetCommand(), "test"))
	{

	}
	else
		std::cout << "Unknown command: " << command.GetCommand() << std::endl;
	return false;
}
