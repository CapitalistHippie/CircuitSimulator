#ifndef _CISIM_CIRCUITSIMULATOR_H_
#define _CISIM_CIRCUITSIMULATOR_H_

#include <iostream>
#include <string>
#include <vector>

#include "nomis/command.hpp"
#include "nomis/string.hpp"

namespace cisim
{
	/** \brief Application class.
	 *
	 * This class represents the application.
	 */
	class CircuitSimulator
	{
	private:
		/**
		 * Handles a console command.
		 *
		 * \param command A reference to the Command object to handle.
		 */
		bool HandleConsoleCommand(const nomis::Command& command);

	public:
		/**
		 * Runs the application.
		 */
		void Run();
	};
}

#endif // _CISIM_CIRCUITSIMULATOR_H_
