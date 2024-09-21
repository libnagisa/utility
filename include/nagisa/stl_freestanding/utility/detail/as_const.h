#pragma once

#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

template<class T>
constexpr ::std::add_const_t<T>& as_const(T& t) noexcept
{
    return t;
}

NGS_BUILD_LIB_DETAIL_END