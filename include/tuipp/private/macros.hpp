// some macros for cross-platform, cross-compiler and cross-version compatibility

#pragma once

#if !(defined(_MSC_VER) && __cplusplus == 199711L) && !defined(__INTEL_COMPILER)
#  if __cplusplus >= 201402L
#    define TUIPP_CPP14
#    if __cplusplus >= 201703L
#      define TUIPP_CPP17
#      if __cplusplus > 201703L
#        define TUIPP_CPP20
#        if __cplusplus > 202002L
#          define TUIPP_CPP23
#          if __cplusplus > 202302L
#            define TUIPP_CPP26
#          endif
#        endif
#      endif
#    endif
#  endif
#elif defined(_MSC_VER) && __cplusplus == 199711L
#  if _MSVC_LANG >= 201402L
#    define TUIPP_CPP14
#    if _MSVC_LANG > 201402L && _MSC_VER >= 1910
#      define TUIPP_CPP17
#      if _MSVC_LANG > 201703L && _MSC_VER >= 1910
#        define TUIPP_CPP20
#        if _MSVC_LANG > 202002L && _MSC_VER >= 1922
#          define TUIPP_CPP23
#        endif
#      endif
#    endif
#  endif
#endif

#if !defined(TUIPP_CPP17) || (defined(__GNUC__) && !defined(__llvm__) &&                           \
                              !defined(__INTEL_COMPILER) && __GNUC__ < 10 && __GNUC__ > 4)
#  define TUIPP_NODISCARD
#else
#  define TUIPP_NODISCARD [[nodiscard]]
#endif

#if defined(_WIN32) || defined(_WIN64)
#  define ON_WINDOWS 1
#elif defined(__linux__) || defined(__unix) || defined(__unix__) || defined(__FreeBSD__) ||        \
  defined(__APPLE__) || defined(__MACH__)
#  define ON_UNIX_LIKE 1
#endif
