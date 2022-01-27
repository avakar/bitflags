#include <type_traits>

namespace avakar {
namespace bitflags {

template <typename T, typename = void>
struct _is_bitflags_enum
	: std::false_type
{
};

template <typename T>
struct _is_bitflags_enum<T, typename std::enable_if<
	std::is_enum<T>::value
	&& static_cast<typename std::underlying_type<T>::type>(T::none) == 0>::type
>
	: std::true_type
{
};

template <typename T>
constexpr auto operator|(T lhs, T rhs) noexcept
	-> typename std::enable_if<_is_bitflags_enum<T>::value, T>::type
{
	using U = typename std::underlying_type<T>::type;
	return static_cast<T>(static_cast<U>(lhs) | static_cast<U>(rhs));
}

template <typename T>
constexpr auto operator&(T lhs, T rhs) noexcept
	-> typename std::enable_if<_is_bitflags_enum<T>::value, T>::type
{
	using U = typename std::underlying_type<T>::type;
	return static_cast<T>(static_cast<U>(lhs) & static_cast<U>(rhs));
}

template <typename T>
constexpr auto operator^(T lhs, T rhs) noexcept
	-> typename std::enable_if<_is_bitflags_enum<T>::value, T>::type
{
	using U = typename std::underlying_type<T>::type;
	return static_cast<T>(static_cast<U>(lhs) ^ static_cast<U>(rhs));
}

template <typename T>
constexpr auto operator~(T lhs) noexcept
	-> typename std::enable_if<_is_bitflags_enum<T>::value, T>::type
{
	using U = typename std::underlying_type<T>::type;
	return static_cast<T>(~static_cast<U>(lhs));
}

}
}

#pragma once
