#ifndef _CIRCUITSIMULATOR_H_
#define _CIRCUITSIMULATOR_H_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <tuple>
#include <exception>
#include <stdlib.h>
#include <string.h>

#include <nomis/command.hpp>
#include <nomis/string.hpp>

#include <cisim.h>

/** @brief Enum with application state values.
 *
 */
enum class ApplicationState
{
	MAIN,
	CIRCUIT,
	CIRCUIT_INFO
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
	 * The currently opened circuit.
	 */
	std::vector<std::tuple<std::string, cisim::Circuit>>::value_type* openedCircuit;

	/**
	 * Collection of loaded circuits.
	 */
	std::vector<std::tuple<std::string, cisim::Circuit>> circuits;

	/**
	 * Handles a console command.
	 *
	 * @param command A reference to the Command object to handle.
	 * @return True if the program should exit. False if not.
	 */
	bool HandleConsoleInput(const nomis::Command& command);

	/**
	 * Renders text to the console.
	 *
	 * @param errorMessage Any error message to show.
	 */
	void Render(const char* const errorMessage = nullptr);

public:
	/**
	 * Runs the application.
	 */
	void Run();
};

#endif // _CIRCUITSIMULATOR_H_
