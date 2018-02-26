/*
 * Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.
 * For example, the message '111' would give 3, since it could be decoded as 'aaa, 'ka', and 'ak'.
 */

#include <iostream>
#include <map>
#include <string>
#include <vector>
int countWays(const std::string &);
int main() {
    std::string input = "11";
    /*cout << "Enter input string: ";
    cin >> input;
    */
    int x = countWays(input);
    std::cout<< "Result: " << x << "\n";
    return 0;
}


int countWays(const std::string &s)
{
    if (s.size() == 0) return 0;
    int w, ways[] = {0,1};
    for (int i=0; i<s.size(); i++) {
        w=0;
        if ((i>0) && ((s[i-1] == '1') || (s[i-1] == '2' && s[i] >= '0' && s[i] < '7'))) {
            w += ways[1];
        }
        if (s[i] > '0' && s[i] <= '9') {
            w += ways[0];
        }
        ways[1] = ways[0];
        ways[0] = w;
    }
    return ways[0];
}
