#include "circuitsimulator.h"

void cisim::CircuitSimulator::Start()
{
	nomis::Command command;
	do
	{
		std::cin >> command;
	} while (!HandleCommand(command));
}

bool cisim::CircuitSimulator::HandleCommand(const nomis::Command& command)
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
