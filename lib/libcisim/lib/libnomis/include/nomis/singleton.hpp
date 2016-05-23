#ifndef _NOMIS_SINGLETON_HPP_
#define _NOMIS_SINGLETON_HPP_

namespace nomis
{
	template<typename T>
	class Singleton
	{
	protected:
		Singleton() = default;

	public:
		static T& GetInstance()
		{
			static auto instance = new T;
			return *instance;
		}
	};
}

#endif // _NOMIS_SINGLETON_HPP_
