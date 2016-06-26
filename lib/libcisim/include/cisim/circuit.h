#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "nodes/node.h"
#include "nodes/neutralnode.h"

namespace cisim
{
	/** @brief Circuit class.
	 *
	 * This class represents a circuit as given in a circuit file.
	 */
	class Circuit
	{
		friend std::istream& operator>>(std::istream& istream, Circuit& circuit);

	private:
		/**
		 * Topologically sorted collection of all the nodes and their identifiers.
		 */
		std::vector<std::pair<std::string, std::shared_ptr<nodes::Node>>> nodes;

	public:
		/**
		 * Clears the circuit class.
		 */
		void Clear();

		/**
		 * Runs the circuit.
		 */
		void Run();

		/**
		 * Get all the nodes in the circuit.
		 * The nodes are delivered one by one in a callback function.
		 *
		 * @param callback Callback function pointer which is called for each node in the circuit.
		 */
		void GetNodes(void(*callback)(const char* identifier, cisim::nodes::Node* node));
	};
}

#endif // _CISIM_CIRCUIT_H_
