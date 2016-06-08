#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <map>
#include <string>
#include <memory>

#include "nodes/node.h"

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
		std::map<std::string, std::shared_ptr<cisim::nodes::Node>> nodes;

	public:
		void Clear();
		void Run();
		void GetNodes(void(*callback)(const char* identifier, cisim::nodes::Node* node));
	};
}

#endif // _CISIM_CIRCUIT_H_
