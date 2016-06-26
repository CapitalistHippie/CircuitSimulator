#ifndef _NOMIS_EH_EVENTHANDLER_H_
#define _NOMIS_EH_EVENTHANDLER_H_

#include <map>
#include <vector>
#include <memory>
#include <functional>
#include <typeinfo>
#include <typeindex>

#include "event.hpp"
// TODO: Base event hooking

namespace nomis { namespace eh
{
	namespace detail
	{
		class CallbackHandlerBase
		{
		public:
			virtual ~CallbackHandlerBase() noexcept {};

			virtual void Call(Event&) = 0;
		};

		template <typename EventType>
		class CallbackHandler : public CallbackHandlerBase
		{
		public:
			void Call(Event& event)
			{
				for (const auto& callback: callbacks)
					callback(static_cast<EventType&>(event));
			}

			std::vector<std::function<void(EventType&)>> callbacks;
		};
	}

	class EventHandler
	{
		typedef std::map<std::type_index, std::shared_ptr<detail::CallbackHandlerBase>> CallbackHandlersMapType;

	private:
		CallbackHandlersMapType callbackHandlers;

	public:
		virtual ~EventHandler() noexcept {};

		template <typename EventType>
		void CallEvent(EventType& event)
		{
			auto iterator = callbackHandlers.find(typeid(EventType));
			if (iterator != callbackHandlers.end())
				std::static_pointer_cast<detail::CallbackHandler<EventType>>(iterator->second)->Call(event);
		}

		template <typename EventType>
		void HookEvent(void (&callback)(EventType&))
		{
			auto iterator = callbackHandlers.find(typeid(EventType));

			if (iterator != callbackHandlers.end())
				std::static_pointer_cast<detail::CallbackHandler<EventType>>(iterator->second)->callbacks.emplace_back(callback);
			else
			{
				auto callbackHandler = std::shared_ptr<detail::CallbackHandlerBase>(new detail::CallbackHandler<EventType>);
				std::static_pointer_cast<detail::CallbackHandler<EventType>>(callbackHandler)->callbacks.emplace_back(callback);

				callbackHandlers[typeid(EventType)] = callbackHandler;
			}
		}

		template <typename EventType, typename ObjectType>
		void HookEvent(void (ObjectType::*callback)(EventType&), ObjectType& object)
		{
			auto iterator = callbackHandlers.find(typeid(EventType));

			if (iterator != callbackHandlers.end())
				std::static_pointer_cast<detail::CallbackHandler<EventType>>(iterator->second)->callbacks.emplace_back(std::bind(callback, object, std::placeholders::_1));
			else
			{
				auto callbackHandler = std::shared_ptr<detail::CallbackHandlerBase>(new detail::CallbackHandler<EventType>);
				std::static_pointer_cast<detail::CallbackHandler<EventType>>(callbackHandler)->callbacks.emplace_back(std::bind(callback, object, std::placeholders::_1));

				callbackHandlers[typeid(EventType)] = callbackHandler;
			}
		}
	};
}}

#endif // _NOMIS_EH_EVENTHANDLER_H_
