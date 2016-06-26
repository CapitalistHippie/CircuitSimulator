#ifndef _NOMIS_EH_EVENT_H_
#define _NOMIS_EH_EVENT_H_

namespace nomis { namespace eh
{
	class Event
	{
	protected:
		Event() noexcept {};
		virtual ~Event() noexcept {};
	};
}}

#endif // _NOMIS_EH_EVENT_H_
