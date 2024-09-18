#pragma once

#include <utility>
#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

#if (NGS_STL_FREESTANDING_UTILITY_USE_STL)

using ::std::forward;
using ::std::move;
using ::std::move_if_noexcept;
using ::std::addressof;

#else

template <class T>
[[nodiscard]] constexpr auto&& forward(::std::remove_reference_t<T>& arg) noexcept
{
    return static_cast<T&&>(arg);
}

template <class T>
[[nodiscard]] constexpr auto&& forward(::std::remove_reference_t<T>&& arg) noexcept
{
    static_assert(!::std::is_lvalue_reference_v<T>, "bad forward call");
    return static_cast<T&&>(arg);
}

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

template <class T>
[[nodiscard]] constexpr T* addressof(T& val) noexcept
{
    return __builtin_addressof(val);
}

template <class T>
const T* addressof(const T&&) = delete;

#endif

NGS_BUILD_LIB_DETAIL_END