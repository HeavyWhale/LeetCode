#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

#include <string>
#include <iostream>
#include <functional>
#include <sstream>
#include <iomanip>

#include <climits>

// containers
using std::vector, std::unordered_map, std::unordered_set, std::stack, 
    std::pair, std::tuple;
// functions
using std::swap, std::max, std::min, std::function, std::apply, std::stoi,
    std::make_pair, std::transform, std::sort;
// io-related
using std::string, std::cout, std::endl, std::stringstream, std::to_string;


template <class T>
inline void hash_combine(std::size_t & seed, const T & v)
{
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
};

template <class T>
string vec2Str(const vector<T>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << to_string(vec[i]);
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

string vec2Str(const vector<string>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

string vec2Str(const vector<char>& vec)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < vec.size(); ++i) {
        ss << vec[i];
        if (i < vec.size() - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}

template <typename T>
string arr2Str(const T* arr, const size_t size)
{
    stringstream ss;
    ss << '[';
    for (size_t i = 0; i < size; ++i) {
        ss << to_string(arr[i]);
        if (i < size - 1) ss << '|';
    }
    ss << ']';
    return ss.str();
}
