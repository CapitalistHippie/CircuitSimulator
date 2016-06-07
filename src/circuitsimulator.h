#ifndef _CIRCUITSIMULATOR_H_
#define _CIRCUITSIMULATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

#include <nomis/command.hpp>
#include <nomis/string.hpp>

#include <cisim.h>

/** @brief Application class.
 *
 * This class represents the application.
 */
class CircuitSimulator
{
private:
	/**
	 * Collection of loaded circuits.
	 */
	std::vector<cisim::Circuit> circuits;

	/**
	 * Handles a console command.
	 *
	 * @param command A reference to the Command object to handle.
	 */
	bool HandleConsoleCommand(const nomis::Command& command);

public:
	/**
	 * Runs the application.
	 */
	void Run();
};

#endif // _CIRCUITSIMULATOR_H_
