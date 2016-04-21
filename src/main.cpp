#include "main.h"

bool HandleCommand(const nomis::Command& command);

int main()
{
	nomis::Command command;
	do
	{
		std::cin >> command;
	} while (!HandleCommand(command));
}

bool HandleCommand(const nomis::Command& command)
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
