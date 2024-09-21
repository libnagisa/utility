#pragma once

#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

template<class Enum>
constexpr ::std::underlying_type_t<Enum> to_underlying(Enum e) noexcept
{
	static_assert(::std::is_enum_v<Enum>, "Enum type required.");
	return static_cast<::std::underlying_type_t<Enum>>(e);
}

NGS_BUILD_LIB_DETAIL_END