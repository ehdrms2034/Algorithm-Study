import java.util.*

fun main() {
    val data = input()
    calculate(data)
}

fun input(): String {
    var input = Scanner(System.`in`)
    var data = input.nextLine()
    return data
}

fun calculate(input: String) {
    val data = input
    val stack = Stack<Char>()

    data.forEach {
        when (it) {
            '*','/'->{
                if(stack.isNotEmpty()&&(stack.peek()=='*'||stack.peek()=='/'))
                    print(stack.pop())
                stack.push(it)
            }
            '+','-'->{
                if(stack.isNotEmpty()&&(stack.peek()=='*'||stack.peek()=='/'))
                    print(stack.pop())
                if(stack.isNotEmpty()&&(stack.peek()=='+'||stack.peek()=='-'))
                    print(stack.pop())
                stack.push(it)
            }
            '('->{
                stack.push(it)
            }
            ')'->{
                while(stack.isNotEmpty()){
                    val word = stack.pop()
                    if(word == '(')
                        break
                    print(word)
                }
            }
            else->{
                print(it)
            }
        }
    }

    while (stack.isNotEmpty()){
        print(stack.pop())
    }
}