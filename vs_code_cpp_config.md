# vs code配置C++工程
---------------------
## 工程代码和makefile
师范工程如下：
头文件employee.h
```c++
#include <string>
using std::string;

typedef struct employee_s{
    string name;
    unsigned short age;
}employee_t;
```
源文件：
```c++
#include <iostream>
#include "employee.h"
using std::cout;
using std::endl;

int main(int argc, char* argv[])
{
    cout<<"hellp world!"<<endl;
    employee_t jonah; 
    jonah.name = "jonah";
    jonah.age = 28;
    cout<<"employee name:"<<jonah.name<<endl;
    cout<<"employee age :"<<jonah.age<<endl;
    return 0;
}
```
makefile文件如下：
```makefile
exec:src.o
	g++ src.o -o exec

src.o:src.cpp ./inc/employee.h
	g++ -g -c src.cpp -I./inc

.PHONY:clean
clean:
	rm -f *.o exec
```
## 配置vs code头文件路径，智能提示补全
* 打开命令面板，配置includePath

![打开c_cpp_properties](https://github.com/JonahZeng/cpp_primer_note/blob/master/markdown_img/vs_code1.png)

![包含所需要的头文件路径](https://github.com/JonahZeng/cpp_primer_note/blob/master/markdown_img/vs_code2.png)
## 配置编译环境
* 同样的，打开命令面板

![配置task](https://github.com/JonahZeng/cpp_primer_note/blob/master/markdown_img/vs_code3.png)
```json
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build hello world",
            "type": "shell",
            "command": "make"
        }
    ]
}
```
注意这个label，这个标签名需要和launch配置一致，因为是用makefile来编译，所以command填make就可以了，如果填g++，额外的args也要填；

## 配置运行/debug
在debug面板点设置，打开launch.json:
```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/exec",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "build hello world"
        }
    ]
}
```
注意preLaunchTask标签，**需要和task.json中的label保持一致**；
然后就是program标签填你编译出来的可执行文件名

## Windows环境下使用MSVC编译
以pybind11为例,编译一个cpp: example.cpp
```c++
#include <pybind11/pybind11.h>
#include <Python.h>

namespace py = pybind11;

int add(int i, int j)
{
    return i+j;
}

PYBIND11_MODULE(example, m)
{
    m.doc() = "pybind11 example plugin";
    m.def("add", &add, "A function which adds two numbers");
}
```
要编译这个cpp文件，新建一个task.json
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build pybind11 example",
            "type": "shell",
            "command": "./build.bat"
        }
    ]
}
```
这个task直接调用同目录下的build.bat文件：
```bat
@echo off
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Enterprise\VC\Auxiliary\Build\vcvarsall.bat" x64     
set compilerflags=/I "C:/python3/include" /I "D:/pybind11/pybind11-master/include"
cl.exe %compilerflags% example.cpp  /LD /Fe:example.pyd  /link/LIBPATH:"C:/python3/libs/"
```
