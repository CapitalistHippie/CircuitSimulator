#ifndef _CIRCUITSIMULATOR_H_
#define _CIRCUITSIMULATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <exception>

#include <nomis/command.hpp>
#include <nomis/string.hpp>

#include <cisim.h>

enum class ApplicationState
{
	MAIN,

};


/** @brief Application class.
 *
 * This class represents the application.
 */
class CircuitSimulator
{
private:
	/**
	 * Variable to hold our current application state.
	 * This is used to decide what to show in the console.
	 */
	ApplicationState applicationState = ApplicationState::MAIN;

	/**
	 * Collection of loaded circuits.
	 */
	std::vector<std::tuple<std::string, cisim::Circuit>> circuits;

	/**
	 * Handles a console command.
	 *
	 * @param command A reference to the Command object to handle.
	 */
	bool HandleConsoleInput(const nomis::Command& command);

	/**
	 * Renders text to the console.
	 */
	void Render();

public:
	/**
	 * Runs the application.
	 */
	void Run();
};

#endif // _CIRCUITSIMULATOR_H_
