#include <stdio.h>
#include <memory>
#include <map>
#include <unordered_map>

namespace ly {
template<typename T>
using unique = std::unique_ptr<T>;

template<typename T>
using shared = std::shared_ptr<T>;

template<typename T>
using weak = std::weak_ptr<T>;

template<typename T>
using List = std::vector<T>;

template<typename keyType, typename valType, typename Pr = std::less<keyType>>
using Map = std::map<keyType, valType, Pr> // map is ordered; uses Pr for ordering; slower than
										   // dictionary (logn lockup)
						   
template<typename keyType, typename valType, typename hasher = std::hash<keyType>
using Dictionary = std::unordered_map<keyType, valType, hasher>;

// macro - replaces LOG with printf
// M is the string for logging, adds newline to string, ## - for older models - removes , if no args
// __VA__ARGS is Variadic Arguments
#define LOG(M, ...) printf(M "\n", ##__VA_ARGS__)
}