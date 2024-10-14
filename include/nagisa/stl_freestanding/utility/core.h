#pragma once

#include "./detail/move.h"
#include "./detail/as_const.h"
#include "./detail/forward.h"
#include "./detail/address_of.h"
#include "./detail/declval.h"
#include "./detail/compare.h"
#include "./detail/in_range.h"
#include "./detail/to_underlying.h"
#include "./environment.h"

NAGISA_BUILD_LIB_BEGIN

using details::move;
using details::move_if_noexcept;

using details::as_const;

using details::forward;
using details::forward_like;
#define NAGISA_STL_FREESTANDING_UTILITY_FORWARD(x) ::NAGISA_NS::stl_freestanding::utility::forward<decltype(x)>(x)

using details::addressof;

using details::declval;

using details::cmp_equal;
using details::cmp_greater;
using details::cmp_greater_equal;
using details::cmp_less;
using details::cmp_less_equal;
using details::cmp_not_equal;

using details::in_range;

using details::to_underlying;

NAGISA_BUILD_LIB_END