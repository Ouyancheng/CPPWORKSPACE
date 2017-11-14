# SublimeBuildSystems
***
### There are four build systems: 
	1. clang
	2. clang++
	3. fpc
	4. Python3
***
### clang
Build .c files using clang compiler, supports C99. Three selections are provided: Only compiling, Compile the .C file and run the program in Sublime internal console, Compile and run in new window. 
Note that the build system works in macOS, the commands will be slightly different if using Windows, and it uses the "open" command, which is only provided in macOS. (but you can replace it with "start" in Windows.)
### clang++
Almost the same as clang, except that it supports C++11 instead of C99. 
### fpc
Build .pas files using FPC, FPC must be installed. 
If you want a light environment to write Pascal, this may be a good choice, or you can use Lazarus or FPC "the blue window". 
### Python3
Nothing special, just run .py files in Python3 environment. Note that it uses Sublime internal console, so input is unsupported. Use SublimeREPL plugin instead of this guy. 
