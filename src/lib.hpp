#ifndef LIB_HPP_INCLUDE
#define LIB_HPP_INCLUDE
#include "jomna.hpp"

template<class T> inline bool cover(const T& from, const T& val, const T& to) { return from <= val && val <= to; }
template<class T> inline signed int size(const T& container) { return (signed int)container.size(); }

#endif
