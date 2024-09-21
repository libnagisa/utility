#pragma once

#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

template <class T>
[[nodiscard]] constexpr T* addressof(T& val) noexcept
{
    return __builtin_addressof(val);
}

template <class T>
const T* addressof(const T&&) = delete;

NGS_BUILD_LIB_DETAIL_END