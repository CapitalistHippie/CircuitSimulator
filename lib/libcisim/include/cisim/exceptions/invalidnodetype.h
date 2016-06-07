#ifndef _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_
#define _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_

#include <exception>

namespace cisim { namespace exceptions
{
	class InvalidNodeType : public std::exception
	{
		virtual const char* what() const throw()
		{
			return "Invalid node type";
		}
	};
}}

#endif // _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_
