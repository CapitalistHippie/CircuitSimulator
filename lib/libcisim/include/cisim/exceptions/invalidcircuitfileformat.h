#ifndef _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_
#define _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_

#include <exception>

namespace cisim { namespace exceptions
{
	class InvalidCircuitFileFormat : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Invalid circuit file format";
		}
	};
}}

#endif // _CISIM_EXCEPTIONS_INVALIDCIRCUITFILEFORMAT_H_
