//
// Created by Massimo Biancalani on 2019-05-02.
//

#include "../catch.hpp"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// not working with templates
/*
template <typename T>
typedef map<int, T> myMap;
*/
template <typename T>
using ptr = T *;
template <typename T>
using myMapTemplate = map<int, T>;

template <typename Seq, typename Pred>
Seq filter(Seq s, Pred p) {
    using f = function<bool(typename Seq::value_type)>;

    Seq result;
    remove_copy_if(begin(s), end(s), back_inserter(result), not1(f(p)));
    return result;
}
TEST_CASE("alias_show_functionality") {

    using myInt = int; //typedef int myInt;
    myInt a = 3;

    // Function pointer
    using func = void (*) (int);

    typedef map<int, string> myMap;

    vector<int> v = {1,2,3, 4, 5,6,7,8};

    function<bool (int)> is_even = [] (int x) { return x % 2 == 0; };
    function<bool (int)> is_large = [] (int x) { return x > 5;};
    vector <int> v_expected01 =  {2, 4, 6, 8};
    vector <int> v_expected02 =  {6,7,8};

    REQUIRE(filter(v, is_even) == v_expected01);
    REQUIRE(filter(v, is_large) == v_expected02);
}