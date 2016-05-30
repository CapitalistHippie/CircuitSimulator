#ifndef _CISIM_BIT_H_
#define _CISIM_BIT_H_

namespace cisim
{
	enum class BitState
	{
		BITSTATE_UNDEFINED,
		BITSTATE_HIGH,
		BITSTATE_LOW
	};

	class Bit
	{
	public:
		BitState state = BitState::BITSTATE_UNDEFINED;

		Bit() noexcept;
		Bit(BitState bitState) noexcept;
	};
}

#endif // _CISIM_BIT_H_
