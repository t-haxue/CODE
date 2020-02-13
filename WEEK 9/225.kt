import java.util.*

class MyStack() {

    /** Initialize your data structure here. */
    private val queue: Queue<Int> = LinkedList<Int>()

    /** Push element x onto stack. */
    fun push(x: Int) {
        queue.offer(x)
    }

    private fun roll() {
        var sz = queue.size
        while (sz-- > 1) {
            queue.offer(queue.poll())
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    fun pop(): Int {
        roll()
        return queue.poll()
    }

    /** Get the top element. */
    fun top(): Int {
        roll()
        val x = queue.peek()
        queue.offer(queue.poll())
        return x
    }

    /** Returns whether the stack is empty. */
    fun empty(): Boolean {
        return queue.isEmpty()
    }

}

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */