1. 读取用户输入并且打印到终端
    ```shell
        read str
        echo $str
    ```
2. 读取用户输入的x个字符并打印到终端，输入的字符超过x个会立即退出等待并且打印
    ```shell
        read -n [x] str
        echo $str
    ```
3. Shell通过控制PS1和PS2来控制命令提示符
    ```javascript
        比如默认是：felix@iZwz9gjv53q8tisvzntl66Z:~$ 
        这个格式就是：[\u@\h \W]\$
    ```
4. 输出当前进程的PID
    ```shell
        echo $$
    ```
5. 强制执行脚本文件
    ```shell
        source test.sh
        或者直接使用. test.sh，注意.和文件之间有一个空格
    ```
6. 交互式shell使用bash_profile之类的配置文件，非交互式shell使用bashrc配置文件
    ```javascript
        但是bash_profile里面会嵌套bashrc的配置，所以bashrc无论是使用交互式shell还是非交互式都会执行
    ```
7. 将shell命令的结果赋值给变量
    ```javascript
        var=`command`
        或者
        var=$(command) // 比较推荐这种，但是只可以在bash中使用，其余的环境不一定支持
    ```
8. 使用readonly将变量设置为只读
    ```shell
        var="test"
        readonly var
        var="test666"
        # 会提示var: readonly variable
    ```
9. 使用unset删除变量，但是unset无法删除只读变量
10. shell变量的作用域
    ```shell
        # 在函数中定义的变量的作用域是全局，默认就是全局变量。如果需要将变量设置为局部变量，需要使用local
        #!/bin/bash
        function func1() {
            a=10
        }

        function func2() {
            a=20
        }

        func1
        echo $a
        func2
        echo $a
        # 结果是 10 20

        # 如果使用local将变量设置为局部变量
        #!/bin/bash
        function func1() {
            local a=10
        }

        function func2() {
            local a=20
        }

        a=30
        func1
        echo $a
        func2
        echo $a
        # 结果是30 30
        # 所以变量默认是全局变量，但是在同一个shell进程中不可以共享，如果子进程和父进程之间需要共享变量，可是使用export将全局变量导出为环境变量，但是如果在毫无关系的两个进程之间进行变量的共享，就需要将变量放入配置文件中了。
    ```
11. 使用date命令显示时间
    ```shell
        # date直接显示：Wed Aug 13 10:36:22 AM CST 2025
        date
        # 使用date +%s: 1755052527 显示 seconds since the Epoch (1970-01-01 00:00 UTC)
        date +%s
    ```
12. shell中的位置参数
    ```shell
        # 在shell中定义函数时不需要指定参数，但是在使用的时候可以传入参数，在函数内部使用$n来接收，$1表示第一个参数，以此类推，如果n>=10,就需要使用${n}，使用{}来帮助解释器识别参数的边界
        echo "name" $1
        echo "gender" $2
        # 使用./test.sh felix male会出现name felix / geneder male, 这是给脚本文件传递位置参数

        # 给函数传递位置参数
        function func() {
            echo "name:" $1
            echo "number:" $2
        }

        func "felix" "123456"
    ```
13. shell中的特殊变量
    ```shell
        echo "第一个参数为:" $1
        echo "所有参数的个数为:" $#
        echo "所有的参数为:" $*
        echo "所有的参数为:" $@
        echo "进程IPD为:" $$

        # felix@iZwz9gjv53q8tisvzntl66Z:~/study/test$ ./test.sh felix 123456 male
        # 第一个参数为: felix
        # 所有参数的个数为: 3
        # 所有的参数为: felix 123456 male
        # 所有的参数为: felix 123456 male
        # 进程IPD为: 89164
    ```
14. shell中的$*和$@的区别
    ```shell
        # 如果添加了双引号
        echo "第一个参数为:" $1
        echo "所有参数的个数为:" $#
        echo "所有的参数为:" $*
        echo "所有的参数为:" $@
        echo "进程IPD为:" $$

        for var in "$*"
        do
                echo $var
        done

        echo "---------------------------------"

        for var in "$@"
        do
                echo $var
        done

        # felix@iZwz9gjv53q8tisvzntl66Z:~/study/test$ ./test.sh felix 123456 male
        
        #felix 123456 male
        #---------------------------------
        #felix
        #123456
        #male

        # $*的话如果使用for循环输出的一整个整体
        # $@的话使用for循环输出的一个一个的输入参数
    ```
15. 获取上一个命令的退出状态
    ```shell
        # 需要使用bash新起一个进程执行，不然会exit会关闭当前的交互窗口
        echo $?
        # 同时$?还可以获取函数的返回值
    ```
16. 获取字符串的长度
    ```shell
        # 使用${#string}来获取字符串的长度
        string="hello,this is \"felix\" how are you?"
        echo ${string}
        echo len: ${#string}

        # 输出
        # hello,this is "felix" how are you?
        # len: 34
    ```
17. shell字符串的截取
    ```shell
        # 字符串的截取有两种分为，从指定位置截取和从指定字符串截取

        # 从指定位置截取，${string:start:length} start从0开始，这是从左开始计数，如果从右边开始计数，就使用0-start，右边开始计数从1取值。
        string="http://baidu.com/login/user=felix&password=123"
        echo $string
        echo ${string:7:9}
        echo ${string:0-18:5}
        # 输出
        # http://baidu.com/login/user=felix&password=123
        # baidu.com
        # felix

        # 从指定字符串或者字符截取分为使用#截取右边的字符串和使用%截取左边的字符串
        string="http://baidu.com/login/user=felix&password=123"
        echo ${string#*//}
        echo ${string%/login*}
        # 输出
        # baidu.com/login/user=felix&password=123
        # http://baidu.com
    ```
18. shell数组
    ```shell
        # shell数组使用()来定义
    ```