// These includse are needed even if you have <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

// Use these
order_of_key (k) : Number of items strictly smaller than k .
find_by_order(k) : K-th element in a set (counting from zero).

// To make it a map (instead of a set) define as the following:
#define ordered_set tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// In other words, the second template argument determines the mapped type, whereas the first template argument is still the key type
