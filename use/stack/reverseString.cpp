#include <iostream>
#include <string>
#include <stack>
#include <cassert>

void reverseString(std::string& str) {
    std::stack<char> st;

    for (char ch : str) {
        st.push(ch);
    }

    for (int i = 0; i < str.size(); i++)
    {
        str[i] = st.top();
        st.pop();
    }
}

void test_reverseString() {
    std::string s1 = "Hello";
    reverseString(s1);
    assert(s1 == "olleH");

    std::string s2 = "a";
    reverseString(s2);
    assert(s2 == "a");

    std::string s5 = "1001";
    reverseString(s5);
    assert(s5 == "1001");

    std::string s3 = "";
    reverseString(s3);
    assert(s3 == "");

    std::string s4 = "abcd";
    reverseString(s4);
    assert(s4 == "dcba");

    std::cout << "tested " << std::endl;
}


int main() {

    test_reverseString();

    return 0;
}
