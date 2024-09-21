#pragma once

#include "./move.h"
#include "./as_const.h"
#include "./environment.h"

NGS_BUILD_LIB_DETAIL_BEGIN

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

template<class T, class U>
constexpr auto&& forward_like(U&& x) noexcept
{
    constexpr bool is_adding_const = ::std::is_const_v<std::remove_reference_t<T>>;
    if constexpr (::std::is_lvalue_reference_v<T&&>)
    {
        if constexpr (is_adding_const)
            return details::as_const(x);
        else
            return static_cast<U&>(x);
    }
    else
    {
        if constexpr (is_adding_const)
            return details::move(details::as_const(x));
        else
            return details::move(x);
    }
}


NGS_BUILD_LIB_DETAIL_END