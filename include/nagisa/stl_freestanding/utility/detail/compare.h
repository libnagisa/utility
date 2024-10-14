#pragma once

#include "./environment.h"


NAGISA_BUILD_LIB_DETAIL_BEGIN

template<class T, class U>
constexpr bool cmp_equal(T t, U u) noexcept
{
    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>)
        return t == u;
    else if constexpr (::std::is_signed_v<T>)
        return t >= 0 && ::std::make_unsigned_t<T>(t) == u;
    else
        return u >= 0 && ::std::make_unsigned_t<U>(u) == t;
}

template<class T, class U>
constexpr bool cmp_not_equal(T t, U u) noexcept
{
    return !details::cmp_equal(t, u);
}

template<class T, class U>
constexpr bool cmp_less(T t, U u) noexcept
{
    if constexpr (::std::is_signed_v<T> == ::std::is_signed_v<U>)
        return t < u;
    else if constexpr (::std::is_signed_v<T>)
        return t < 0 || ::std::make_unsigned_t<T>(t) < u;
    else
        return u >= 0 && t < ::std::make_unsigned_t<U>(u);
}

template<class T, class U>
constexpr bool cmp_greater(T t, U u) noexcept
{
    return details::cmp_less(u, t);
}

template<class T, class U>
constexpr bool cmp_less_equal(T t, U u) noexcept
{
    return !details::cmp_less(u, t);
}

template<class T, class U>
constexpr bool cmp_greater_equal(T t, U u) noexcept
{
    return !details::cmp_less(t, u);
}

NAGISA_BUILD_LIB_DETAIL_END