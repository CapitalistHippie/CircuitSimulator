#include "command.h"

int nomis::Command::GetAmountOfParameters() const noexcept
{
	return parameters.size();
}

const char* nomis::Command::GetCommand() const noexcept
{
	return command.c_str();
}

const char* nomis::Command::GetParameter(const unsigned int parameterNumber) const
{
	return parameters.at(parameterNumber).c_str();
}

std::istream& nomis::operator>>(std::istream& istream, Command& command)
{
	// Get the command line.
	std::string commandLine;
	std::getline(istream, commandLine);

	// Strip leading whitespace from the command line.
	commandLine.erase(0, commandLine.find_first_not_of(" \t"));

	// Get the command.
	std::size_t location = commandLine.find_first_of(" \t");
	if (location != std::string::npos)
		command.command = commandLine.substr(0, location);
	else
	{
		command.command = commandLine;
		return istream;
	}

	// Get the parameters if there are any.
	for (;;)
	{
		std::string parameter;
		location = commandLine.find_first_not_of(" \t", location + 1);
		if (location == std::string::npos)
			break;

		std::size_t nextLocation = commandLine.find_first_of(" \t", location);
		if (nextLocation != std::string::npos)
			parameter = commandLine.substr(location, nextLocation - location);
		else
		{
			parameter = commandLine.substr(location, commandLine.size() - location);
			break;
		}

		location = nextLocation;

		command.parameters.push_back(parameter);
	}

	return istream;
}
