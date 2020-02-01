import java.util.*

class Solution {
    private fun index(x: Char): Int = when (x) {
        '(', ')' -> 1
        '[', ']' -> 2
        '{', '}' -> 3
        else -> -1
    }

    fun isValid(s: String): Boolean {
        val stk = Stack<Char>()
        var flag = true
        loop@ for (i in s.indices) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i])
            } else {
                if (stk.empty() || index(stk.pop()) != index(s[i])) {
                    flag = false
                    break@loop
                }
            }
        }
        if (!stk.empty()) {
            flag = false
        }
        return flag
    }
}
