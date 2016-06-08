#include "circuitsimulator.h"

void CircuitSimulator::Run()
{
	Render();

	nomis::Command command;
	do
	{
		std::cin >> command;
	} while (!HandleConsoleInput(command));
}

bool CircuitSimulator::HandleConsoleInput(const nomis::Command& command)
{
	try
	{
		// Global commands.
		if (!nomis::istrcmp(command.GetCommand(), "exit"))
			return true;

		switch (applicationState)
		{
		case ApplicationState::MAIN:
			if (!nomis::istrcmp(command.GetCommand(), "loadcircuit"))
			{
				// If no parameters. Show some usage text.
				if (!command.GetAmountOfParameters())
				{
					std::cout << "Loads a circuit file." << std::endl
							<< "Usage: loadcircuit <file path>" << std::endl;
				}
				else
				{
					// Build a circuit from the file.
					auto circuit = cisim::CircuitBuilder().GetInstance().BuildCircuit(command.GetParameter(0));

					// Put the circuit with the others.
					circuits.push_back(std::make_tuple(command.GetParameter(0), circuit));
				}
			}
			else if (!nomis::istrcmp(command.GetCommand(), "opencircuit"))
			{

			}
			break;
		}
	}
	catch (std::exception& exception)
	{
		Render();
		std::cerr << "An exception occurred: " << exception.what() << std::endl;
	}

	Render();
	return false;
}

void CircuitSimulator::Render()
{
	// Clear screen.
	for (int i = 0; i < 80; ++i)
		std::cout << std::endl;

	switch (applicationState)
	{
	case ApplicationState::MAIN:
		std::cout << "Available commands: " << std::endl
		<< "loadcircuit <file path>: Loads a circuit file." << std::endl
		<< "opencircuit <circuit index>: Opens a circuit." << std::endl << std::endl
		<< "Loaded circuits: " << std::endl;

		int i = 0;
		for (auto& circuit: circuits)
		{
			std::cout << '[' << i++ << "] " << std::get<0>(circuit) << std::endl;
		}
		break;
	}
}








