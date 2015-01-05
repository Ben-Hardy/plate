            __________   ___            _____    ___________   __________
           /  ____   /  /  /          /  ___  \  \____   ___\  \   ______\
          /  /___/  /  /  /          /  /___\  \      \  \      \  \_____
         /  _______/  /  /          /  _______  \      \  \      \   ____\
        /  /         /  /_______   /  /       \  \      \  \      \  \______
       /__/         /__________/  /__/         \__\      \__\      \________\


Plate is a UNIX program which provides a file containing a simple template for a requested programming language, shell script, makefile, or LaTeX file structure. Plate is useful for rapid prototyping, testing new systems (each template comes with a hello world equivalent that is tested works so plate templates can be used to test and make sure a new install of a compiler or interpreter works correctly)

To use Plate, simply provide the following command to the terminal:
     plate language filename

Plate can handle creating multiple files simply by adding more arguments to the input command.

For example:
        plate language file1 file2 ...

File names containing multiple words are handled by simply placing a set of quotation marks around the file name argument.

Supported languages: (beside each language name is the accompanying argument to supply to plate. 

##### Note:C/h is a C file with accompanying header file. C++/h is a C++ file with accompanying .h file):
-   Text         txt
-   C             c
-   C++           c++
-   .h            h
-   C/h           ch
-   C++/h         c++h
-   Google Go     go
-   Haskell       haskell
-   Prolog        prolog
-   Python        python
-   Javascript    javascript
-   CoffeeScript  coffeescript
-   HTML          html
-   HTML/script   htmlscript
-   CSS           css
-   Ruby          ruby
-   JQuery        jquery
-   PHP           php
-   Scala         scala
-   Erlang        erlang
-   ML            ml
-   Markdown      md
A number of script stubs are also available:
sh            sh
bash          bash
ksh           ksh
zsh           zsh
csh           csh
PERL script   perls
Node script   nodescript
Python Script pythonscript
scala script  scalascript

Simple Makefiles of the following types are also available:

C makefile                    cmake

C++ makefile                  c++make

c file w/ .h and makefile     chmake

c++ file w/ .h and makefile   c++hmake
