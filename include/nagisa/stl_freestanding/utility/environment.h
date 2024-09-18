#pragma once

#include <type_traits>

#if (NGS_STL_FREESTANDING_UTILITY_USE_STL)
#
#	if (__cpp_lib_freestanding_utility >= 202306L)
#		include <utility>
#	else
#		error freestanding utility is not supported
#	endif
#
#endif

#define NGS_BUILD_LIB_NAME stl_freestanding::utility
#define NGS_BUILD_LIB_CONFIG_VERSION (0,0,0)
#include <nagisa/build_lib/construct.h>