#include "cisim/bit.h"

cisim::Bit::Bit() noexcept
{
}

cisim::Bit::Bit(BitState bitState) noexcept : state(bitState)
{
}
