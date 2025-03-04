#include <iostream>
#include <stack>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);  // Đánh dấu bắt đầu để dễ tính toán
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);  // Lưu vị trí '('
        } else {
            st.pop();  // Xóa phần tử trên stack
            if (st.empty()) {
                st.push(i);  // Nếu stack rỗng, lưu vị trí ')'
            } else {
                maxLen = max(maxLen, i - st.top());  // Cập nhật độ dài hợp lệ
            }
        }
    }

    return maxLen;
}

int main() {
    string s = "(()))())(";
    cout << "Longest Valid Parentheses: " << longestValidParentheses(s) << endl;
    return 0;
}
