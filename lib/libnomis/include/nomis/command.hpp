#ifndef _NOMIS_COMMAND_HPP_
#define _NOMIS_COMMAND_HPP_

#include <iostream>
#include <string>
#include <vector>

namespace nomis
{
	class Command
	{
		friend std::istream& operator>>(std::istream& istream, Command& command);

	private:
		std::string command;
		std::vector<std::string> parameters;

	public:
		int GetAmountOfParameters() const noexcept
		{
			return parameters.size();
		}

		const char* GetCommand() const noexcept
		{
			return command.c_str();
		}

		const char* GetParameter(const unsigned int parameterNumber) const
		{
			return parameters.at(parameterNumber).c_str();
		}
	};

	inline std::istream& operator>>(std::istream& istream, Command& command)
	{
		// Clear the command object.
		command.parameters.clear();

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
			location = commandLine.find_first_not_of(" \t\r", location + 1);
			if (location == std::string::npos)
				break;

			std::size_t nextLocation = commandLine.find_first_of(" \t", location);
			if (nextLocation != std::string::npos)
				parameter = commandLine.substr(location, nextLocation - location);
			else
			{
				parameter = commandLine.substr(location, commandLine.size() - location);
				command.parameters.push_back(parameter);
				break;
			}

			location = nextLocation;

			command.parameters.push_back(parameter);
		}

		return istream;
	}
}

#endif // _NOMIS_COMMAND_HPP_
