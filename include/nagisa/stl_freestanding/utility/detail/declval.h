#pragma once

#include "./environment.h"

NAGISA_BUILD_LIB_DETAIL_BEGIN

template <class T>
::std::add_rvalue_reference_t<T> declval() noexcept
{
    static_assert(false, "calling declval is ill-formed, see N4950 [declval]/2.");
}

NAGISA_BUILD_LIB_DETAIL_END