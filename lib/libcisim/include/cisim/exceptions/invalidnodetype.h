#ifndef _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_
#define _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_

#include <stdexcept>

namespace cisim { namespace exceptions
{
	class InvalidNodeType : public std::runtime_error
	{
		using std::runtime_error::runtime_error;

	public:
		InvalidNodeType() : runtime_error("Invalid node type") {}
	};
}}

#endif // _CISIM_EXCEPTIONS_INVALIDNODETYPE_H_
