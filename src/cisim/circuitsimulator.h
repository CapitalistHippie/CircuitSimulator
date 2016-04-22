#ifndef _CISIM_CIRCUITSIMULATOR_H_
#define _CISIM_CIRCUITSIMULATOR_H_

#include <iostream>
#include <string>
#include <vector>

#include "nomis/command.hpp"
#include "nomis/string.hpp"

namespace cisim
{
	class CircuitSimulator
	{
	private:
		bool HandleCommand(const nomis::Command& command);

	public:
		void Start();
	};
}

#endif // _CISIM_CIRCUITSIMULATOR_H_
