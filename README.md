# CPE390Lab0: Getting Setup

## Final Setup

1. You should have a directory named `Lab0` in the current directory. You can verify this either using Windows Explorer, or better yet, using `ls` or `dir` to list all the files in the current directory.
2. If on Linux/MacOS/WSL, you can open the local copy of the repository (on your machine) using `code Lab0`.
   - If on MSYS2 or other unsupported shell, open VS Code manually.
   - Click File (Top-Left) >> Open Folder.
   - Navigate to and open the repository.
3. In the sidebar, you should see several folders named `.vscode_<System_Name>`. Rename the correct folder for your system to `.vscode`. The folder structure, when you complete this step should look like this:
   - .vscode/
     - launch.json
     - tasks.json
   - etc...

## Getting Started: helloworld.cpp

1. Read through the code and the comments.
2. Run `make helloworld.cpp`: this will build the code into something your processor can understand.
3. Run `./helloworld.cpp` (to run the program)
4. Any modifications you make to the program need to be recompiled into the executable (by repeating steps 2-3 each time). Note that if you do not recompile, the output will not match the latest version of your program.

## A quick thing about `make`

Make is a utility that simplifies the building of code. It essentially just runs the commands provided in `Makefile`. Generally, if you run `make` by itself and if there is a `Makefile` in the same directory, then it will run the first target (in this case, `DebugDemo`). You could manually specify which target to build if you don't want to build the first one automatically (`make DebugDemo`). As a good practice, I've included a target `clean`, which will remove binary files, and other non-source files that you can generate. This is a practice you should follow when writing makefiles.

## Writing DebugDemo.cpp

1. Read & Follow the instructions in `DebugDemo.cpp` to write the base program in C++.
2. Once you are done, you will need to build the C++ file into an executable that your processor can understand. Run `g++ DebugDemo.cpp -g3 -o DebugDemo`. If this command complains:
   1. Make sure you typed the command correctly.
   2. Read the output of running the g++ command. There are usually helpful hints in there, including line numbers. Note that sometimes the line causing the error might be one line up/down.
   3. Make sure you aren't missing semicolons.
3. Here are some common flags (`-FLAG_GOES_HERE`) for `g++`:
   - `-o`: instead of using the default output filename (`a`, `a.out`, `a.exe`), we will use the name specified (ie `DebugDemo`). Note that MSYS2 ignores the lack of file extension for some reason, but it will find the executable even if you omit the `.exe`.
   - `-O3`: Optimizations. You can use basic optimizations (1-3), or [other optimizations](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html). Note that if you need to debug anything, this will make it difficult as the line numbers might not match. Also, experimental optimizations may break your code.
   - `-g`: the debug flag, note that you can use `-g0` up to `-g3` to determine how much debugging information gets put into the executable. `-g` is usually sufficient.
   - `-L [Folder]`: Link with files in a folder you specify; useful if you need to link in library files.
   - `-I [Folder]`: Include a directory containing header files... useful for large projects.
4. Run your program `./DebugDemo`. If you see the expected output, continue; otherwise, you need to modify your program to match the expected output.

## Learning to debug

1. Set a break point on the first statement in each loop.
2. Right click the break point in the second loop and click `Edit Breakpoint...`.
3. Set the expression to `loopvariable == 5`, replacing loop variable with i or j or whatever the variable you used.
4. Finally, set a breakpoint on the final line of the main method (prewritten).
5. Use the run button on the left to compile and enter debugging mode. If the compiler fails to compile, you need to fix your code.
6. Walk through the first loop using the `step` button. Note how the highlighted line is about to be run when you click on an action, but has not been run yet.
7. When you reach the second break point, open the debugging console at the bottom of the screen, where the terminal usually appears.
8. Set the value of your loop-variable to 1 and hit continue to allow the program to almost finish.
9. Click on the terminal tab to see the output of your program. It should match this:

    ```text
    Part 1:
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    0
    1
    2
    3
    4

    Part 2:
    =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

    10
    9
    8
    7
    6
    1
    ```

## A Quick Rundown of `Git`

Git is a version control system (VCS), which allows you to make changes to your codebase without being worried that you may break it. It allows you to go back in the "commit history" and see what changes were made, and even recover previous revisions of files among other things.

For the purposes of this lab, you will be submitting your work through this repository. Generally, when you have finished fixing a bug, implementing a feature, or otherwise finished doing something to your codebase, you want to commit and push your code, so even if you accidentally break it in the future, lose your laptop/pi/etc, you will be able to go back. To do so you must do the following three things.

1. `git status`: This changes nothing in your repository. It only shows you what changes have been made since your last commit.
2. `git add file1 file2 directory1/ etc`: by using this command, you tell git (the version control system) that `file1...` are files that you would like to include in your commit. We generally group files that accomplished the same function toghether. ie if I fixed an off-by-one error in a file and a different error in another file, I would make two separate commits (though I should have run through this process at the end of fixing each error). Note that you should not break up trivial code changes/fixes into multiple commits. Just group everything together.
3. `git commit -m "What did I change this commit?"`: Git commit tells git to save the current state of your work. `-m` allows you to put your commit message (what the purpose of the commit was) right in the command, as opposed to having git open a text editor for you.
   - If you accidentally omit the message and are unsure how to get out:
     - Vim: type `<esc>` followed by `:wq` and hit `enter`.
     - Nano: type `ctrl-x`, followed by `y`, then `enter`.
4. `git pull`: If you are working with other people, you need to run this. Otherwise, it won't do anything. The idea is that if anyone made any changes and pushed them to [github.com](https://github.com), then you will need to incorporate their commits before you can push your own.
   - If this step fails, you will see an error message saying failed to automatically merge, or something along those lines. Doing `git status` will tell you what failed to merge and will allow you to open those files yourself and edit out the changes. VSCode in dark mode highlights those changes in blue/green. The first section should be your code, and the second, the remote-code.
5. `git push` - Just tells git to push your code to [github.com](github.com), so that I and others can see it/grade it. If you committed your changes but forgot to push them, it is as good as not having done the work in the first place. Before you consider an assignment done, ensure that you can go to the github repo and see your latest commit message. If you cannot, then your work is not submitted.

## Submitting Your Work

1. Take screenshots of your programs working as expected, and put in the `submission/screenshots` folder.
2. Save all of your files.
3. Rename `Atilla_The_Duck (Replace with your name).name` to your name.
4. Use the info above to push your code to your repository.

## How to do everything from the terminal

These instructions are for if you cannot debug in VS Code. They will be generic, assuming you have a file `a.cpp`, which you want to debug... Note that breakpoints set in VS Code are not relevant to things in GDB. Note that GDB relies on a library known as [curses](https://en.wikipedia.org/wiki/Curses_(programming_library)), which is prone to issues. If you ever notice that your screen looks strange, just hit `ctrl`+`L` to force the library to redraw your entire screen.

1. Compile a.cpp:
   1. If you have a `Makefile`, you may use `make` (or `make <target>`) to build the file.
   2. `g++ -g3 a.cpp`: `-g3` tells the compiler to include as much debugging information as possible. 
2. Start the debugger: 
   1. `gdb a.out` (may be a.exe on some systems). This will open the GNU Debugger as a sort of terminal. 
3. Set the layout of the debugger:
   1. `layout src`: the source code layout. Usually, if you are not working with assembly, this is the only layout you need to use.
   2. `layout reg`: this shows only the registers, usually combined with the `asm` layout, as the registers are largely irrelevant when programming pure C++.
   3. `layout asm`: this shows the assembly instructions you are running.
4. Set your breakpoints. A few different ways to set breakpoints:
   1. `b main`: sets a breakpoint at the entry point to the main function
   2. `b a.cpp:123`: sets a breakpoint in a.cpp at line 123. Note that if you edit the file while you debug, the line numbers that GDB will not update. This is also applicable to VS Code.
   3. `b a.cpp:123 if var == value`: conditional breakpoint that only breaks if the var reaches the value. Note that other conditions can be specified.
5. Run your program:
   1. `r`: runs your program. If you are already running your program, you can use `r` to restart.
   2. `c`: continues if you are paused.
   3. `s`: step until you hit the next line in source code.
   4. `si`: step instruction
   5. `n`: step, but won't enter lower level stuff (ie loops, function calls, etc)
   6. `q`: quit.
