#include "circuitsimulator.h"

bool IsNumeric(const char* const input);
void GetNodesCallback(const char* identifier, cisim::nodes::Node* node);
void GetInputBitsCallback(cisim::Bit* inputBit);

void CircuitSimulator::Run()
{
	std::string errorMessage;

	while (true)
	{
		try
		{
			Render(errorMessage.c_str());

			nomis::Command command;
			do
			{
				std::cin >> command;
			} while (!HandleConsoleInput(command));

			return;
		}
		catch (std::exception& exception)
		{
			errorMessage = std::string("An exception occurred: ") + exception.what();
		}
	}
}

bool CircuitSimulator::HandleConsoleInput(const nomis::Command& command)
{
	// Global commands.
	if (!nomis::istrcmp(command.GetCommand(), "exit"))
		return true;

	switch (applicationState)
	{
	case ApplicationState::MAIN:
		{
			if (!nomis::istrcmp(command.GetCommand(), "loadcircuit"))
			{
				if (!command.GetAmountOfParameters())
				{
					Render("Invalid amount of parameters.");
					return false;
				}

				// Build a circuit from the file.
				auto circuit = cisim::CircuitBuilder().GetInstance().BuildCircuit(command.GetParameter(0));

				// Put the circuit with the others.
				circuits.push_back(std::make_tuple(command.GetParameter(0), circuit));
			}
			else if (!nomis::istrcmp(command.GetCommand(), "opencircuit"))
			{
				if (!command.GetAmountOfParameters())
				{
					Render("Invalid amount of parameters.");
					return false;
				}

				// Check if the given parameter is a number.
				auto parameter = command.GetParameter(0);
				if (!IsNumeric(parameter))
				{
					Render("Parameter must be a number.");
					return false;
				}

				// Set the opened circuit.
				int openedCircuitIndex = atoi(command.GetParameter(0));

				if (openedCircuitIndex >= circuits.size())
				{
					Render("Invalid circuit index.");
					return false;
				}

				openedCircuit = &circuits.at(openedCircuitIndex);

				// Change the application state.
				applicationState = ApplicationState::CIRCUIT;
			}
		}
		break;
	case ApplicationState::CIRCUIT:
		{
			if (!nomis::istrcmp(command.GetCommand(), "back"))
			{
				applicationState = ApplicationState::MAIN;
			}
			else if (!nomis::istrcmp(command.GetCommand(), "run"))
			{
				std::get<1>(*openedCircuit).Run();
				applicationState = ApplicationState::CIRCUIT_INFO;
			}
			else if (!nomis::istrcmp(command.GetCommand(), "info"))
			{
				applicationState = ApplicationState::CIRCUIT_INFO;
			}
		}
		break;
	case ApplicationState::CIRCUIT_INFO:
		{
			if (!nomis::istrcmp(command.GetCommand(), "back"))
			{
				applicationState = ApplicationState::CIRCUIT;
			}
		}
		break;
	}

	Render();
	return false;
}

void CircuitSimulator::Render(const char* const errorMessage)
{
	// Clear screen.
	for (int i = 0; i < 80; ++i)
		std::cout << std::endl;

	if (errorMessage != nullptr && errorMessage != "")
		std::cout << errorMessage << std::endl << std::endl;

	switch (applicationState)
	{
	case ApplicationState::MAIN:
		{
			std::cout << "Available commands: " << std::endl
					<< "loadcircuit <file path>: Loads a circuit file." << std::endl
					<< "opencircuit <circuit index>: Opens a circuit." << std::endl << std::endl
					<< "Loaded circuits: " << std::endl;

			int i = 0;
			for (auto& circuit: circuits)
			{
				std::cout << '[' << i++ << "] " << std::get<0>(circuit) << std::endl;
			}
		}
		break;
	case ApplicationState::CIRCUIT:
		{
			std::cout << "Circuit: " << std::get<0>(*openedCircuit) << std::endl << std::endl
					<< "Available commands: " << std::endl
					<< "run: Runs the circuit." << std::endl
					<< "info: Shows info about all the nodes in the circuit." << std::endl
					<< "back: Go back to the main screen." << std::endl;
		}
		break;
	case ApplicationState::CIRCUIT_INFO:
		{
			std::cout << "Circuit: " << std::get<0>(*openedCircuit) << std::endl << std::endl
					<< "Available commands: " << std::endl
					<< "back: Go back to the circuit screen." << std::endl << std::endl
					<< "Nodes:" << std::endl;

			std::get<1>(*openedCircuit).GetNodes(GetNodesCallback);
		}
		break;
	}
}

void GetNodesCallback(const char* identifier, cisim::nodes::Node* node)
{
	std::cout << identifier << std::endl;
	node->GetInputBits(GetInputBitsCallback);
	if (node->outputBit == cisim::Bit::BITSTATE_UNDEFINED)
		std::cout << "Output: undefined" << std::endl;
	else if (node->outputBit == cisim::Bit::BITSTATE_HIGH)
		std::cout << "Output: high" << std::endl;
	else if (node->outputBit == cisim::Bit::BITSTATE_LOW)
		std::cout << "Output: low" << std::endl;
	std::cout << std::endl;
}

void GetInputBitsCallback(cisim::Bit* inputBit)
{
	if (*inputBit == cisim::Bit::BITSTATE_UNDEFINED)
		std::cout << "Input: undefined" << std::endl;
	else if (*inputBit == cisim::Bit::BITSTATE_HIGH)
		std::cout << "Input: high" << std::endl;
	else if (*inputBit == cisim::Bit::BITSTATE_LOW)
		std::cout << "Input: low" << std::endl;
}

bool IsNumeric(const char* const input)
{
	for (int i = 0; i < strlen(input); i++)
	{
		if (!isdigit(input[i]))
			return false;
	}
	return true;
}
















