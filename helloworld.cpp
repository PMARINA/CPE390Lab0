// Something to be aware of: https://google.github.io/styleguide/cppguide.html

// We don't expect you to understand ^^ right now; however, you
// should be able to understand a good chunk of it by the end of the semester.
// Try to follow the guidelines to write readable, modular, and maintainable
// code

#include <cstdint>
#include <iostream>  // This is how you get input/output in C++ (to the shell)
#include <string>
using namespace std;  // This is generally inadvisable by Google, but it will
                      // make our code smaller/easier to read

// Google also doesn't like us declaring functions without defining them. Don't
// do this (definition after main)
void print_hello_world();
void print_loop(string message, uint8_t num_iterations = 10);
// Note the = 10. Python and C++ allow us to have default arguments.

/*
 * int main():
 *    This is the main method. All C++ programs need to have a main method. Note
 *    that this does not mean that each file needs a main method. If you are
 *    trying to compile a single file into an executable, then you need a main
 *    method
 *
 * Prints out Hello World, then prints out numbers in a loop.
 */
int main() {
  print_hello_world();
  cout << endl;
  print_loop("oreos");
  cout << endl;  // to flush the buffer, just in case
  // Notice how the contents of the main method make the comment above main
  // essentially unhelpful, as it is clear what is happening. This is the
  // example to follow when writing main methods. They should be simple and have
  // as few lines of code in them where possible.

  // You technically don't need the return 0 at the end of your program, as it
  // will automatically happen for you. Note that I use 0. Not 1. Not any other
  // number. This is because the value you return is interpretted as how the
  // program ran. If the return value is 0, then it ran successfully. If you
  // return anything else, it is assumed that your program crashed. Here is a
  // resource for seeing what some common return codes are:
  // http://tldp.org/LDP/abs/html/exitcodes.html#AEN23549
  return 0;
}
/*
 * void print_hello_world():
 *    Prints out hello world to cout
 *
 * Note that this is painfully obvious from the function name. Generally, I
 * would avoid putting a comment to explain what the method does for a 1-liner,
 * but comments above methods is generally a good idea.
 */
void print_hello_world() {
  cout << "Hello World" << endl;
  // ^^ Print out Hello World, followed by a newline.
  // The difference between endl and "\n": endl flushes the buffer. This means
  // "\n" is technically more efficient; however, when debugging, if your
  // program crashes before it flushes the buffer, it might not be able to flush
  // the buffer, meaning there will be missing output.
}
/*
 * void print_loop(uint8_t number_of_iterations):
 *    Prints out the numbers from 0 to number_of_iterations.
 *
 *    uint8_t number_of_iterations: The number of iterations to run the loop
 *
 * Note that I use uint8_t. I could instead use int, unsigned int, or others.
 *    uint: unsigned integer (cannot represent a negative number)
 *    8: the number of bits the int will occupy
 *        (maximum value = 2^8-1 = 255)
 */
void print_loop(string message, uint8_t num_iterations) {
  // The structure of a C++ for loop:
  // for(declare & initialize a variable; the end condition; what to do at the
  // end of every time we run the loop)
  for (uint8_t i = 0; i < num_iterations; i++) {
    // [i=0 ; i<10] OR [i=1 ; i<=10] will run the same number of times but print
    // different things, try and see what happens when you change the bounds of
    // the loop

    // Note that i++ is almost the same as ++i. It does the same thing in this
    // case; however, if you ever do array[++i] instead of array[i++], you will
    // achieve different things.

    // unsigned(i) to keep cout from thinking it's a char, and not a uint8_t
    cout << unsigned(i) << ": " << message << "\n";
  }
}