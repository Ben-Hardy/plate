#include "plate.h"


/* prints help information to standard output. C90 does not like the length of this string hahaha */
void printhelp( void ) {
    char help[] = "\n\n          __________   ___            _____    ___________   __________\n         /  ____   /  /  /          /  ___  \\  \\____   ___\\  \\   ______\\\n        /  /___/  /  /  /          /  /___\\  \\      \\  \\      \\  \\_____\n       /  _______/  /  /          /  _______  \\      \\  \\      \\   ____\\\n      /  /         /  /_______   /  /       \\  \\      \\  \\      \\  \\______\n     /__/         /__________/  /__/         \\__\\      \\__\\      \\________\\\n\nPlate is a UNIX program which provides a file containing a simple template for a requested programming language, shell script, makefile, or LaTeX file structure.\n\nTo use Plate, simply provide the following command to the terminal:\n\n\tplate language filename\n\nPlate can handle creating multiple simply by adding more arguments to the input command.\n\nFor example:\n\n\tplate language file1 file2 ...\n\nFile names containing multiple words are handled by simply placing a set of quotation marks around the file name argument.\n\nSupported languages: (beside each language name is the accompanying argument to supply to plate. C/h is a C file with accompanying .h file. C++/h is a C++ file with accompanying .h file)\nText         txt\nC             c\nC++           c++\n.h            h\nC/h           ch\nC++/h         c++h\nGoogle Go     go\nHaskell       haskell\nProlog        prolog\nPython        python\nJavascript    javascript\nCoffeeScript  coffeescript\nHTML          html\nHTML/script   htmlscript\nCSS           css\nRuby          ruby\nJQuery        jquery\nPHP           php\nScala         scala\nErlang        erlang\nML            ml\n\nA number of scripts are also available:\nsh            sh\nbash          bash\nksh           ksh\nzsh           zsh\ncsh           csh\nPERL script   perls\nNode script   nodescript\nPython Script pythonscript\nscala script  scalascript\n\nSimple Makefiles of the following types are also available:\n\nC makefile          cmake\nC++ makefile        c++make\nc w/ .h and make    chmake\nc++ w/ .h and make  c++hmake\n\n";
        printf( "%s", help );
}

/* creates a file and outputs if successfully created */
void createfile( char* filename, char* template ) {
    FILE *file = fopen( filename, "wx" );
    fputs( template, file );
    fclose( file );
    printf( "%s was successfully created!\n", filename );
}

/* calculates the sum of the ascii integer values of the provided string. */
int calcstrsum( char* name ) {
    int total = 0;
    int i = 0;
    while ( name[i] != '\0' ) {
        total += name[i];
        ++i;
    }
    return total;
}

/* tests if a file is readable. If it is, that implies that it exists, and in that case we should not mess with it */
int fileexists( char* filename ) {
    FILE *f = fopen( filename, "r" ); // open for reading
    if ( f != NULL ) { // if it is not null, it can be read, thus it must exist!
        fclose( f );
        return 1;
    }
    return 0;
}

/* modifies a string in place, changing the ascii values by 32, in effect making them upper case! */
void uppercaser( char *string ) {
    int i = 0;
    while ( string[i] != '\0' ) {
        if ( string[i] >= 97 && string[i] <= 122 ) // the ascii code range of small letters is 97 to 122, hence the condition!
            string[i] -= 32; // the ascii number code for a given capital letter is 32 below its small version
        ++i;
    }
}

/* 
   gets sum of string and then double checks to make sure the string is what it is supposed to be.
   otherwise, could dupe the 1st arg into accepting the wrong input. For example, if argv[1] is "bash"
   , then the string sum is 414. However, asdf also has a string sum of 414. So this would check to 
   make sure that if the sum is 414, then the input is indeed "bash" and not something malicious.    
*/
int anlzstr( char* str ) { // this will probably be pretty ugly. Big block of ifs
    int sum = calcstrsum( str );

    switch ( sum ) {
        case TXT:        if ( strcmp( str, "txt" ) == 0 )            return TXT;
        case CLANG:      if ( strcmp( str, "c" ) == 0 )              return CLANG;
        case CMAKE:      if ( strcmp( str, "cmake" ) == 0 )          return CMAKE;
        case CHMAKE:     if ( strcmp( str, "chmake" ) == 0 )         return CHMAKE;
        case CPLUSPLUS:  if ( strcmp( str, "c++" ) == 0 )            return CPLUSPLUS;
        case CPPMAKE:    if ( strcmp( str, "c++make" ) == 0 )        return CPPMAKE;
        case CPPHMAKE:   if ( strcmp( str, "c++hmake" ) == 0 )       return CPPHMAKE;
        case HFILE:      if ( strcmp( str, "h" ) == 0 )              return HFILE;
        case CH:         if ( strcmp( str, "ch" ) == 0 )             return CH;
        case CPPH:       if ( strcmp( str, "c++h" ) == 0 )           return CPPH;
        case JAVA:       if ( strcmp( str, "java" ) == 0 )           return JAVA;
        case PYTHON:     if ( strcmp( str, "python" ) == 0 )         return PYTHON;
        case GO:         if ( strcmp( str, "go" ) == 0 )             return GO;
        case SCALA:      if ( strcmp( str, "scala" ) == 0 )          return SCALA;
        case HASKELL:    if ( strcmp( str, "haskell" ) == 0 )        return HASKELL;
        case SH:         if ( strcmp( str, "sh" ) == 0 )             return SH;
        case BASH:       if ( strcmp( str, "bash" ) == 0 )           return BASH;
        case KSH:        if ( strcmp( str, "ksh" ) == 0 )            return KSH;
        case CSH:        if ( strcmp( str, "csh" ) == 0 )            return CSH;
        case PERL:       if ( strcmp( str, "perl" ) == 0 )           return PERL;
        case SCALAS:     if ( strcmp( str, "scalascript" ) == 0 )    return SCALAS;
        case NODES:      if ( strcmp( str, "nodescript" ) == 0 )     return NODES;
        case PYTHONS:    if ( strcmp( str, "pythonscript" ) == 0 )   return PYTHONS;
        case HTML:       if ( strcmp( str, "html" ) == 0 )           return HTML;
        case HTMLS:      if ( strcmp( str, "htmlscript" ) == 0 )     return HTMLS;
        case CSS:        if ( strcmp( str, "css" ) == 0 )            return CSS;
        case JAVASCRIPT: if ( strcmp( str, "javascript" ) == 0 )     return JAVASCRIPT;
        case RUBY:       if ( strcmp( str, "ruby" ) == 0 )           return RUBY;
        case JQUERY:     if ( strcmp( str, "jquery" ) == 0 )         return JQUERY;
        case PHP:        if ( strcmp( str, "php" ) == 0 )            return PHP;
        case OCAML:      if ( strcmp( str, "ocaml" ) == 0 )          return OCAML;
        case ERLANG:     if ( strcmp( str, "erlang" ) == 0 )         return ERLANG;
        case COFFEE:     if ( strcmp( str, "coffeescript" ) == 0 )   return COFFEE;
        case MD:     if ( strcmp( str, "markdown" ) == 0 )   return MD;
        default: printhelp();
    }

    return 1;
}

/* makes a file by looking at the language it is supposed to be, adjusting filenames accordingly, and then passing the relevant info to a helper function */
void makefile( char** filenames, char* lang, int numfiles ) {

    int err = 0;
    int namesum = anlzstr( lang ); // little trick so I can use a switch statement rather than a huge chain of if/else if statements. Much more concise.
    if ( namesum == 1 ) return; // the case where argv[1] was either the wrong input or was malicious
    for ( int i = 2; i < numfiles; i++ ) {
        char *name;
        
        switch ( namesum ) {
            case TXT:  // text files. Most would just use touch to make empty files but since this takes like 5 seconds to implement included it anyway
                if ( fileexists( filenames[i] ) ) {  printf( "The file %s already exists!\n", filenames[i] );  break;}
                else {
                    createfile( filenames[i], "" );
                }
            break; 
            case CLANG: // C file case
                err = asprintf( &name, "%s.c", filenames[i] );
		        if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                    else {
                    char templ[] = "#include <stdio.h>\n\nint main(int argc, char* argv[]){\n    printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;

            case CPLUSPLUS: // C++ file case
                err = asprintf( &name, "%s.cc", filenames[i] );
                if ( fileexists( name ) ) {  printf("The file %s already exists!\n", name);  break;}
                    else {
                    char templ[] = "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    return 0;\n}\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
                
            case HFILE: // .h file case. 
                err = asprintf( &name, "%s.h", filenames[i] );
                if ( fileexists( name ) ) {  printf("The file %s already exists!\n", name);  break;}
                else {
                    char *upper;
                    err = asprintf( &upper, "%s", filenames[i] );
                    uppercaser( upper );
                    char *templ;
                    templ = malloc ( sizeof("#ifndef __\n#define __\n\n#include <stdio.h>\n\n\n\n\n#endif\n") + 2 * ( sizeof( upper ) ) + 4 ); // yeah I know it's ugly as all hell but it works
                    sprintf( templ,  "#ifndef _%s_\n#define _%s_\n\n#include <stdio.h>\n\n\n\n\n#endif\n", upper, upper );
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                    free( upper );
                    upper = NULL;
                }
                break;
            case CH: // C file with an accompanying .h file.
                err = asprintf( &name, "%s.c", filenames[i] );
                char *chfile;
                err = asprintf( &chfile, "%s.h", filenames[i] );
                if ( fileexists( name ) || fileexists( chfile ) ) {  printf( "The file %s or %s already exists!\n", name, chfile );  break;}
                    else {
                    char *ctempl;
                    err = asprintf( &ctempl, "#include \"%s\"\n\nint main(int argc, char* argv[]){\n    printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n", chfile, "%s" );
                    createfile( name, ctempl );
                    char *upper;
                    err = asprintf( &upper, "%s", filenames[i] );
                    uppercaser( upper );
                    char *htempl;
                    err = asprintf( &htempl, "#ifndef _%s_\n#define _%s_\n\n#include <stdio.h>\n\n\n\n\n#endif\n", upper, upper );
                    createfile( chfile, htempl );
                    free( name );
                    name = NULL;
                    free( chfile );
                    chfile = NULL;
                    free( ctempl );
                    ctempl = NULL;
                    free( htempl );
                    htempl = NULL;
                }
                break;
            case CPPH: // C++ wih header file
                err = asprintf( &name, "%s.c", filenames[i] );  // for future reference, cannot start switch cases/if statements with declarations, must start with statements or else will not compile!
                char *hfile;
                err = asprintf( &hfile, "%s.h", filenames[i] );
                if (fileexists( name ) || fileexists( hfile ) ) {  printf( "The file %s or %s already exists!\n", name, hfile );  break;}
                    else {
                    char *ctempl;
                    err = asprintf( &ctempl, "#include \"%s\"\n\nusing namespace std;\n\nint main(int argc, char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    return 0;\n}\n", hfile );
                    createfile(name, ctempl);
                    char *upper;
                    err = asprintf( &upper, "%s", filenames[i] );
                    uppercaser( upper );
                    char *htempl;
                    err = asprintf( &htempl, "#ifndef _%s_\n#define _%s_\n\n#include <iostream>\n\n\n\n\n#endif\n", upper, upper );
                    createfile( hfile, htempl );
                    free( name );
                    name = NULL;
                    free( hfile );
                    hfile = NULL;
                    free( ctempl );
                    ctempl = NULL;
                    free( upper );
                    upper = NULL;
                    free( htempl );
                    htempl = NULL;
                }
                break;
            case CMAKE:
                err = asprintf( &name, "%s.c", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                    else {
                    char templ[] = "#include <stdio.h>\n\nint main(int argc, char* argv[]){\n    printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n";
                    createfile(name, templ);
                    char *make;
                    err = asprintf( &make, "C=gcc\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: %s\n\t$(C) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n", filenames[i], filenames[i], name, name, filenames[i], filenames[i] );
                    createfile( "makefile", make );
                    free( name );
                    name = NULL;
                    free( make );
                    make = NULL;
                }
                break;
            case CHMAKE: // C file with an accompanying .h file and makefile
                err = asprintf( &name, "%s.c", filenames[i] );
                char *chmfile;
                err = asprintf( &chmfile, "%s.h", filenames[i] );
                if ( fileexists( name ) || fileexists( chmfile ) ) {  printf( "The file %s or %s already exists!\n", name, chmfile );  break;}
                    else {
                    char *ctempl;
                    err = asprintf( &ctempl, "#include \"%s\"\n\nint main(int argc, char* argv[]){\n    printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n", chmfile, "%s" ); // sshhhh don't tell
                    createfile( name, ctempl );
                    char *upper;
                    err = asprintf( &upper, "%s", filenames[i] );
                    uppercaser( upper );
                    char *htempl;
                    err = asprintf( &htempl, "#ifndef _%s_\n#define _%s_\n\n#include <stdio.h>\n\n\n\n\n#endif\n", upper, upper );
                    createfile(chmfile, htempl);
                    char *make;
                    err = asprintf( &make, "C=gcc\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: %s\n\t$(C) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n", filenames[i], filenames[i], name, name, filenames[i], filenames[i] );
                    createfile( "makefile", make );
                    free( name );
                    name = NULL;
                    free( chmfile );
                    chmfile = NULL;
                    free( ctempl );
                    ctempl = NULL;
                    free( upper );
                    upper = NULL;
                    free( htempl );
                    htempl = NULL;
                    free( make );
                    make = NULL;
                }
            case CPPMAKE:
                err = asprintf( &name, "%s.cc", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                    else {
                    char templ[] = "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    return 0;\n}\n";
                    createfile( name, templ );
                    char *make;
                    err = asprintf( &make, "CC=g++\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: %s\n\t$(CC) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n", filenames[i], filenames[i], name, name, filenames[i], filenames[i] );
                    createfile( "makefile", make );
                    free( name );
                    name = NULL;
                    free( make );
                    make = NULL;
                }
                break;
            case CPPHMAKE: // C++ wih header file
                err = asprintf( &name, "%s.cc", filenames[i] );
                char *hmfile;
                err = asprintf( &hmfile, "%s.h", filenames[i] );
                if ( fileexists( name ) || fileexists( hmfile ) ) {  printf( "The file %s or %s already exists!\n", name, hmfile );  break;}
                    else {
                    char *ctempl;
                    err = asprintf( &ctempl, "#include \"%s\"\n\nusing namespace std;\n\nint main(int argc, char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    return 0;\n}\n", hmfile );
                    createfile( name, ctempl );
                    char *upper;
                    err = asprintf( &upper, "%s", filenames[i] );
                    uppercaser( upper );
                    char *htempl;
                    err = asprintf( &htempl, "#ifndef _%s_\n#define _%s_\n\n#include <iostream>\n\n\n\n\n#endif\n", upper, upper );
                    createfile( hmfile, htempl );
                    char *make;
                    err = asprintf( &make, "CC=g++\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: %s\n\t$(CC) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n", filenames[i], filenames[i], name, name, filenames[i], filenames[i] );
                    createfile( "makefile", make );
                    free( name );
                    name = NULL;
                    free( hmfile );
                    hmfile = NULL;
                    free( ctempl );
                    ctempl = NULL;
                    free( upper );
                    upper = NULL;
                    free( htempl );
                    htempl = NULL;
                    free( make );
                    make = NULL;
                }
                break;
            case JAVA: // java!
                if ( filenames[i][0] >= 97 && filenames[i][0] <= 122 ) // if the first character of the filename is a small letter, capitalize it!
                    filenames[i][0] -= 32;
                err = asprintf( &name, "%s.java", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                else {
                    char *templ;
                    err = asprintf( &templ, "public class %s {\n\n\tpublic %s() {\n\n\t}\n\n\tpublic static void main(String[] args) {\n\n\t\tSystem.out.println(\"Hello World!\");\n\t}\n}\n", filenames[i], filenames[i] );
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                    free( templ );
                    templ = NULL;
                }
                break;
            case PYTHON: // python!
                err = asprintf( &name, "%s.py", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                else {
                    char templ[] = "import sys\n\n\ndef main():\n\tprint(\"Hello world!\")\n\n\nif __name__==\"__main__\":\n\tmain()\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case GO: // Google Go AKA golang
                err = asprintf( &name, "%s.go", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                else {
                    char templ[] = "package main// change this as needed\n\nimport \"fmt\"\n\nfunc main() {\n\tfmt.Printf(\"Hello World!\\n\")\n}\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case SCALA: // scala!
                if (filenames[i][0] >= 97 && filenames[i][0] <= 122) // if the first character of the filename is a small letter, capitalize it!
                    filenames[i][0] -= 32;
                err = asprintf( &name, "%s.scala", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                else {
                    char *templ;
                    err = asprintf( &templ, "object %s {\n\n\tdef main(args: Array[String]) {\n\t\tprintln(\"Hello World!\")\n\t}\n}", filenames[i] );
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                    free( templ );
                    templ = NULL;
                }
                break;
            case HASKELL: // haskell
                err = asprintf( &name, "%s.hs", filenames[i] );
                if ( fileexists( name ) ) {  printf( "The file %s already exists!\n", name );  break;}
                else {
                    char templ[] = "main = do\n\tputStrLn \"Hello World!\"";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case SH:  // basic sh script
                err = asprintf( &name, "%s.sh", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/bin/sh\n\n\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case BASH: // bash script
                err = asprintf( &name, "%s.sh", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/bin/bash\n\n\n";
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
                // the one below is iffy. zsh is sometimes in usr/bin or usr/local/bin, depending on OS. On Mac, it is in usr/bin. On some Linux distros, it is in one of the three above directories.
            case ZSH: // zsh script
                err = asprintf( &name, "%s.sh", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/bin/zsh\n\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case KSH: // ksh script
                err = asprintf( &name, "%s.sh", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/bin/ksh\n\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case CSH: // csh script
                err = asprintf( &name, "%s.sh", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/bin/csh\n\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case PERL:  // Perl script
                err = asprintf( &name, "%s", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/usr/bin/perl\nprint(\"Hello World!\\n\");\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case SCALAS: // scala script
                err = asprintf( &name, "%s", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/usr/bin/env scala\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case NODES: // node script
                err = asprintf( &name, "%s", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/usr/bin/env node\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case PYTHONS: // python script
                err = asprintf( &name, "%s", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "#!/usr/bin/env python\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case HTML:  // basic html file
                err = asprintf( &name, "%s.html", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "<!DOCTYPE html>\n<html>\n<link href=\"stylesheet.css\" rel=\"stylesheet\" type=\"text/css\" />\n<meta charset=\"utf-8\">\n\n<head>\n\t<title>TITLE GOES HERE</title>\n</head>\n\n<body>\n\t<p>\n\t\tThis is some text\n\t</p>\n</body>\n</html>\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case HTMLS:  // html with script tag
                err = asprintf( &name, "%s.html", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "<!DOCTYPE html>\n<html>\n<link href=\"stylesheet.css\" rel=\"stylesheet\" type=\"text/css\" />\n<meta charset=\"utf-8\">\n\n<head>\n\t<title>TITLE GOES HERE</title>\n</head>\n<script>\n\n</script>\n<body>\n\t<p>\n\t\tThis is some text\n\t</p>\n</body>\n</html>\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case CSS: // rudementary CSS file
                err = asprintf( &name, "%s.css", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {
                    char templ[] = "body {\n\n}\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case JAVASCRIPT: // basic javascript file with a makeshift main since main isn't required in JS
                err = asprintf( &name, "%s.js", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else {  // the main function is a formality of course
                    char templ[] = "\n\nfunction main() {\n\tconsole.log(\"Hello World!\");\n} \n\nmain();\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case RUBY:  // ruby
                err = asprintf( &name, "%s.rb", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "puts \"Hello World!\"\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case JQUERY:  // JQuery
                err = asprintf( &name, "%s.js", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "$(document).ready(function() {\n\n});\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case PHP: // PHP for posterity's sake
                err = asprintf( &name, "%s.php", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "<?php\n\n?>\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case OCAML:  // Objective-CAML
                err = asprintf( &name, "%s.ml", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "let main () =\n\tPrintf.printf \"Hello World!\\n\"\n\nlet _ = main ()\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case ERLANG: // erlang!
                err = asprintf( &name, "%s.erl", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
            case COFFEE:  // coffeescript 
                err = asprintf( &name, "%s.coffee", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "Console.log(\"Hello World!\")\n\n"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            case MD:  // markdown 
                err = asprintf( &name, "%s.md", filenames[i] );
                if ( fileexists( name ) ) printf( "The file %s already exists!\n", name );
                else { 
                    char templ[] = "# Title\n\n## Header 1"; 
                    createfile( name, templ );
                    free( name );
                    name = NULL;
                }
                break;
            default:
                printf( "the file %s was not successfully created! Check command formatting. For help, use \"plate -h\" or \"plate help\"\n", filenames[i] );
        }

    }
    if (err == -1) printf( "There is something wrong. Either memory was not allocated correctly or something else.\n");

}


int main( int argc, char** argv ){
    if ( argc == 1|| calcstrsum(argv[1]) == 425 || calcstrsum( argv[1] ) ==  149 ) printhelp();
   // else if ( calcstrsum(argv[1]) == 448 && argv[1][0] == 't' ) test();
    else {
        makefile( argv, argv[1], argc );
    }

    return 0;

}
