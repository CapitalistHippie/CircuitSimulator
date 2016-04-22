#ifndef _CISIM_CIRCUIT_H_
#define _CISIM_CIRCUIT_H_

#include <iostream>
#include <string>
#include <vector>

namespace cisim
{
	class Circuit
	{
		friend std::istream& operator>>(std::istream& istream, Circuit& command);
	};

	std::istream& operator>>(std::istream& istream, Circuit& command);
}

#endif // _CISIM_CIRCUIT_H_
