#ifndef _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_
#define _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_

#include <stdexcept>

namespace cisim { namespace exceptions
{
	class InvalidCircuitFileFormat : public std::runtime_error
	{
		using std::runtime_error::runtime_error;

		virtual const char* what() const throw()
		{
			return "Invalid circuit file format";
		}
	};
}}

#endif // _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_
