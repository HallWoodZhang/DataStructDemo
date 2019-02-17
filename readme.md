# 这是一个用来测试数据结构以及相关算法的学习用repo

- 首先你需要确认你自己安装好了cmake

- 如果你想要运行这一个repo中的代码，你可以

```shell
$ git clone https://github.com/HallWoodZhang/DataStructDemo.git
$ cd DataStructDemo
$ ./run.sh
```

- 如果你想要自己加入自己的代码（特别是专题，比如树，图等等），你需要适当修改 build 文件夹下的cmake配置文件
 - 你需要注意的是，这个repo的代码结构是很清晰的，如果需要增加别的数据结构类别，你需要加在build/CMakeLists.txt 加入如下include语句，他们分别代表加入了sort, tree, graph相关的数据结构算法

```

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/graph)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/sort)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../header/tree)
```

- 所有的源文件都放在src文件夹下，头文件都放在header文件夹下，并且进行了适当的分类

- 因为本人的时间精力有限，并非所有的数据结构demo都经过测试，这里的代码都仅供参考

- 最后祝您身体健康，再见