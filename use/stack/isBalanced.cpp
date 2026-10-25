#include <iostream>
#include <string>
#include <stack>
#include <cassert>

bool match(char a, char b) {
    if (b == ')') {
        return a == '(';
    }
    else if (b == '}') {
        return a == '{';
    }
    else if (b == ']') {
        return a == '[';
    }

    return false;
}

bool isBalanced(std::string str) {
    std::stack<char> st;
    for (char ch : str) {
        if (ch == '[' || ch == '(' || ch == '{') {
            st.push(ch);
        }
        else {
            if (st.empty()) {
                return false;
            }
            if (match(st.top(), ch)) {
                st.pop();
            }
            else {
                return false;
            }
        }
    }

    return st.empty();
}

void test_isBalanced() {
    assert(isBalanced(""));
    assert(isBalanced("()"));
    assert(isBalanced("[]"));
    assert(isBalanced("({[]})"));
    assert(isBalanced("((()))"));
    assert(isBalanced("{}"));
    assert(isBalanced("[{}()]"));

    assert(!isBalanced("("));
    assert(!isBalanced("([)]"));
    assert(!isBalanced("{[}]"));
    assert(!isBalanced("((("));
    assert(!isBalanced("())"));
    assert(!isBalanced(")"));
    assert(!isBalanced("(()"));

    std::cout << "tested " << std::endl;
}


int main()
{
    test_isBalanced();
    return 0;
}
