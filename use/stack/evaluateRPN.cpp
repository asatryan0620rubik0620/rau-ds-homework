#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cassert>
#include <stdexcept>

double evaluateRPN(std::vector<std::string> expr) {
    std::stack<double> st;

    for (std::string symbol : expr) {
        if (symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/") {
            double b = st.top();
            st.pop();

            double a = st.top();
            st.pop();

            if (symbol == "+") {
                st.push(a + b);
            }
            else if (symbol == "-")
            {
                st.push(a - b);
            }
            else if (symbol == "*") {
                st.push(a * b);
            }
            else {
                st.push(a / b);
            }
        }
        else {
            st.push(std::stod(symbol));
        }
    }

    return st.top();
}


void test_evaluateRPN() {
    assert(evaluateRPN({ "2", "1", "+", "3", "*" }) == 9);
    assert(evaluateRPN({ "4", "2", "/" }) == 2);
    assert(evaluateRPN({ "10" }) == 10);
    assert(evaluateRPN({ "2", "3", "*" }) == 6);
    assert(evaluateRPN({ "3", "5", "-" }) == -2);
    assert(evaluateRPN({ "5", "3", "-" }) == 2);
    assert(evaluateRPN({ "7", "2", "/" }) == 3.5);

    std::cout << "tested " << std::endl;
}

int main() {
    test_evaluateRPN();

    return 0;
}
