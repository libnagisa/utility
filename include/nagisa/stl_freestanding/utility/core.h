#pragma once

#include "./detail/value_category.h"
#include "./environment.h"

NGS_BUILD_LIB_BEGIN

using details::forward;
using details::move;
using details::move_if_noexcept;
using details::addressof;

#define NGS_STL_FREESTANDING_UTILITY_FORWARD(x) ::NGS_NS::stl_freestanding::utility::forward<decltype(x)>(x)

NGS_BUILD_LIB_END