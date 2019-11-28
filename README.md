# Frogger-Clone
 Frogger-like game, built in C++ and Allegro 5.
 Made for an university exam.

# Building instructions

 REQUIRED: C++ compiler with support to C++17, Allegro 5 or later.
 RECOMMENDED: make utility or any make porting for your operating system.

 If you have a make utility (as Linux make built-in), you can just call make with any combination of the following flags:
  1) 'compile': as you expect;
  2) 'run': launch the default executable from out-of-source;
  3) 'clean': deletes the default executable.
 Feel free to modify any variable you want to test with different settings (for example, to add --sanitize==address).

 If you don't have a make utility, just paste this command string in your terminal:
    g++ -std=c++17 src/bin/allegro_wrappers/*.cpp src/bin/gamelogic/*.cpp src/bin/gui/*.cpp src/bin/main.cpp -o frogger \
     -lallegro_monolith #(for monolith users)
     -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf #(for the weak).

 Enjoy!