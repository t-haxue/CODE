import java.util.*

class MyQueue() {

    /** Initialize your data structure here. */
    private val inStk = Stack<Int>()
    private val outStk = Stack<Int>()

    /** Push element x to the back of queue. */
    fun push(x: Int) {
        inStk.push(x)
    }

    private fun transfer() {
        if (outStk.empty()) {
            while (!inStk.empty()) {
                outStk.push(inStk.pop())
            }
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    fun pop(): Int {
        transfer()
        return outStk.pop()
    }

    /** Get the front element. */
    fun peek(): Int {
        transfer()
        return outStk.peek()
    }

    /** Returns whether the queue is empty. */
    fun empty(): Boolean {
        return inStk.empty() && outStk.empty()
    }

}

/**
 * Your MyQueue object will be instantiated and called as such:
 * var obj = MyQueue()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.peek()
 * var param_4 = obj.empty()
 */