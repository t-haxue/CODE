import java.util.*

class MinStack() {

    /** initialize your data structure here. */
    val stk = Stack<Int>()
    var min_value = Int.MAX_VALUE
    var min_index: Int = -1

    fun push(x: Int) {
        if (x < min_value) {
            min_value = x
            min_index = stk.size
        }
        stk.push(x)
    }

    fun pop() {
        stk.pop()
        if (stk.size == min_index) {
            val tstk = Stack<Int>()
            min_value = Int.MAX_VALUE
            while (!stk.empty()) {
                tstk.push(stk.pop())
            }
            while (!tstk.empty()) {
                push(tstk.pop())
            }
        }
    }

    fun top(): Int {
        return stk.peek()
    }

    fun getMin(): Int {
        return min_value
    }

}

/**
 * Your MinStack object will be instantiated and called as such:
 * var obj = MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */