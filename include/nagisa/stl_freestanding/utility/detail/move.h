#pragma once

#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

template <class T>
[[nodiscard]] constexpr ::std::remove_reference_t<T>&& move(T&& arg) noexcept
{
    return static_cast<::std::remove_reference_t<T>&&>(arg);
}

template <class T>
[[nodiscard]] constexpr
::std::conditional_t<!::std::is_nothrow_move_constructible_v<T>&& ::std::is_copy_constructible_v<T>, const T&, T&&>
move_if_noexcept(T& arg) noexcept
{
    return details::move(arg);
}

NGS_BUILD_LIB_DETAIL_END