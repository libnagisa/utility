#pragma once

#include "./compare.h"
#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class R, class T>
constexpr bool in_range(T t) noexcept
{
    return
		details::cmp_greater_equal(t, ::std::numeric_limits<R>::min())
		&& details::cmp_less_equal(t, ::std::numeric_limits<R>::max())
	;
}

NAGISA_BUILD_LIB_DETAIL_END