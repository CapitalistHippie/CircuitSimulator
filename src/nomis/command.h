#ifndef _NOMIS_COMMAND_H_
#define _NOMIS_COMMAND_H_

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
		int GetAmountOfParameters() const noexcept;

		const char* GetCommand() const noexcept;
		const char* GetParameter(const unsigned int parameterNumber) const;
	};

	std::istream& operator>>(std::istream& istream, Command& command);
}

#endif // _NOMIS_COMMAND_H_
