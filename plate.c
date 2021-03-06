#include "plate.h"

/* prints help information to standard output. */
void printhelp(void) {
  char help[] =
      "\n\n          __________   ___            _____    ___________   "
      "__________\n         /  ____   /  /  /          /  ___  \\  \\____   "
      "___\\  \\   ______\\\n        /  /___/  /  /  /          /  /___\\  \\  "
      "    \\  \\      \\  \\_____\n       /  _______/  /  /          /  "
      "_______  \\      \\  \\      \\   ____\\\n      /  /         /  "
      "/_______   /  /       \\  \\      \\  \\      \\  \\______\n     /__/   "
      "      /__________/  /__/         \\__\\      \\__\\      "
      "\\________\\\n\nPlate is a UNIX program which provides a file "
      "containing a simple template for a requested programming language, "
      "shell script, makefile, or LaTeX file structure.\n\nTo use Plate, "
      "simply provide the following command to the terminal:\n\n\tplate "
      "language filename\n\nPlate can handle creating multiple simply by "
      "adding more arguments to the input command.\n\nFor example:\n\n\tplate "
      "language file1 file2 ...\n\nFile names containing multiple words are "
      "handled by simply placing a set of quotation marks around the file name "
      "argument.\n\nSupported languages: (beside each language name is the "
      "accompanying argument to supply to plate. C/h is a C file with "
      "accompanying .h file. C++/h is a C++ file with accompanying .h "
      "file)\nText         txt\nC             c\nC++           c++\n.h         "
      "   h\nC/h           ch\nC++/h         c++h\nGoogle Go     go\nHaskell   "
      "    haskell\nProlog        prolog\nPython        python\nJavascript    "
      "javascript\nCoffeeScript  coffeescript\nHTML          html\nHTML/script "
      "  htmlscript\nCSS           css\nRuby          ruby\nJQuery        "
      "jquery\nPHP           php\nScala         scala\nErlang        "
      "erlang\nML            ml\n\nA number of scripts are also available:\nsh "
      "           sh\nbash          bash\nksh           ksh\nzsh           "
      "zsh\ncsh           csh\nPERL script   perls\nNode script   "
      "nodescript\nPython Script pythonscript\nscala script  "
      "scalascript\n\nSimple Makefiles of the following types are also "
      "available:\n\nC makefile          cmake\nC++ makefile        c++make\nc "
      "w/ .h and make    chmake\nc++ w/ .h and make  c++hmake\n\nThe following "
      "project templates are also available:\n\nC project:          cproj\n\n";
  printf("%s", help);
}

/* creates a file and outputs if successfully created */
void createfile(char *filename, char *template) {
  FILE *file = fopen(filename, "wx");
  fputs(template, file);
  fclose(file);
  printf("%s was successfully created!\n", filename);
}

/* calculates the sum of the ascii integer values of the provided string. */
int calcstrsum(char *name) {
  int total = 0;
  int i = 0;
  while (name[i] != '\0') {
    total += name[i];
    ++i;
  }
  return total;
}

/* tests if a file is readable. If it is, that implies that it exists, and in
 * that case we should not mess with it */
int fileexists(char *filename) {
  FILE *f = fopen(filename, "r");  // open for reading
  if (f != NULL) {  // if it is not null, it can be read, thus it must exist!
    fclose(f);
    return 1;
  }
  return 0;
}

/* modifies a string in place, changing the ascii values by 32, in effect making
 * them upper case! */
void uppercaser(char *string) {
  int i = 0;
  while (string[i] != '\0') {
    if (string[i] >= 97 && string[i] <= 122)  // the ascii code range of small
                                              // letters is 97 to 122, hence the
                                              // condition!
      string[i] -= 32;  // the ascii number code for a given capital letter is
                        // 32 below its small version
    ++i;
  }
}

/*
   gets sum of string and then double checks to make sure the string is what it
   is supposed to be.
   otherwise, could dupe the 1st arg into accepting the wrong input. For
   example, if argv[1] is "bash"
   , then the string sum is 414. However, asdf also has a string sum of 414. So
   this would check to
   make sure that if the sum is 414, then the input is indeed "bash" and not
   something malicious.
*/
int checkstring(
    char *str) {  // this will probably be pretty ugly. Big block of ifs
  int sum = calcstrsum(str);
  switch (sum) {
    case TXT:
      if (strcmp(str, "txt") == 0) return TXT;
    case CLANG:
      if (strcmp(str, "c") == 0) return CLANG;
    case CMAKE:
      if (strcmp(str, "cmake") == 0) return CMAKE;
    case CHMAKE:
      if (strcmp(str, "chmake") == 0) return CHMAKE;
    case CPLUSPLUS:
      if (strcmp(str, "c++") == 0) return CPLUSPLUS;
    case CPPMAKE:
      if (strcmp(str, "c++make") == 0) return CPPMAKE;
    case CPPHMAKE:
      if (strcmp(str, "c++hmake") == 0) return CPPHMAKE;
    case CPROJ:
      if (strcmp(str, "cproj") == 0) return CPROJ;
    case HFILE:
      if (strcmp(str, "h") == 0) return HFILE;
    case CH:
      if (strcmp(str, "ch") == 0) return CH;
    case CPPH:
      if (strcmp(str, "c++h") == 0) return CPPH;
    case JAVA:
      if (strcmp(str, "java") == 0) return JAVA;
    case PYTHON:
      if (strcmp(str, "python") == 0) return PYTHON;
    case GO:
      if (strcmp(str, "go") == 0) return GO;
    case SCALA:
      if (strcmp(str, "scala") == 0) return SCALA;
    case HASKELL:
      if (strcmp(str, "haskell") == 0) return HASKELL;
    case SH:
      if (strcmp(str, "sh") == 0) return SH;
    case BASH:
      if (strcmp(str, "bash") == 0) return BASH;
    case KSH:
      if (strcmp(str, "ksh") == 0) return KSH;
    case CSH:
      if (strcmp(str, "csh") == 0) return CSH;
    case PERL:
      if (strcmp(str, "perl") == 0) return PERL;
    case SCALAS:
      if (strcmp(str, "scalascript") == 0) return SCALAS;
    case NODES:
      if (strcmp(str, "nodescript") == 0) return NODES;
    case PYTHONS:
      if (strcmp(str, "pythonscript") == 0) return PYTHONS;
    case HTML:
      if (strcmp(str, "html") == 0) return HTML;
    case HTMLS:
      if (strcmp(str, "htmlscript") == 0) return HTMLS;
    case CSS:
      if (strcmp(str, "css") == 0) return CSS;
    case JAVASCRIPT:
      if (strcmp(str, "javascript") == 0) return JAVASCRIPT;
    case RUBY:
      if (strcmp(str, "ruby") == 0) return RUBY;
    case JQUERY:
      if (strcmp(str, "jquery") == 0) return JQUERY;
    case PHP:
      if (strcmp(str, "php") == 0) return PHP;
    case OCAML:
      if (strcmp(str, "ocaml") == 0) return OCAML;
    case ERLANG:
      if (strcmp(str, "erlang") == 0) return ERLANG;
    case COFFEE:
      if (strcmp(str, "coffeescript") == 0) return COFFEE;
    case MD:
      if (strcmp(str, "markdown") == 0) return MD;
    default:
      printhelp();
  }

  return 1;
}
/*
    These are the two main functions that handle the actually creation of
    templates. the only difference between them is that sh customizes the
    file contents to the script type rather than have an inputted extention
 and file contents
*/
int templatizer(char **filenames, char *ext, int numfiles, char *text) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.%s", filenames[i], ext);
    if (fileexists(name))
      printf("The file %s already exists!\n", name);
    else {
      char *templ;
      err = asprintf(&templ, "%s", text);
      createfile(name, templ);
      free(name);
      name = NULL;
    }
  }
  return 0;
}

int sh(char **filenames, char *lang, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.sh", filenames[i]);
    if (fileexists(name))
      printf("The file %s already exists!\n", name);
    else {
      char *templ;
      err = asprintf(&templ, "#!/bin/%s\n\necho \"Hello, World!\"\n", lang);
      createfile(name, templ);
      free(name);
      name = NULL;
    }
  }
  return 0;
}

/*
   Past the two main functions are a bunch of more specialized functions.
   These functions handle special cases for certain filetypes. For example,
   for C/C++ header files, it will ALL-CAPS the file name and put in in an
   #ifndef setup that is standard fair for a header file.
   Also included are some more advanced C/C++ based file/project creation tools
   like a paired C file and header, or a C file, header, and custom makefile.
*/
int hfile(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.h", filenames[i]);
    if (err == -1) {
      printf("There was an issue allocating memory for the filename!\n");
      return -1;
    }
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      char *upper;
      err = asprintf(&upper, "%s", filenames[i]);
      uppercaser(upper);
      char *templ;
      err = asprintf(
          &templ,
          "#ifndef _%s_\n#define _%s_\n\n#include <stdio.h>\n\n\n\n\n#endif\n",
          upper, upper);
      createfile(name, templ);
      free(name);
      name = NULL;
      free(upper);
      upper = NULL;
    }
  }
  return 0;
}

int ch(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.c", filenames[i]);
    char *chfile;
    err = asprintf(&chfile, "%s.h", filenames[i]);
    if (fileexists(name) || fileexists(chfile)) {
      printf("The file %s or %s already exists!\n", name, chfile);
      return -1;
    } else {
      char *ctempl;
      err =
          asprintf(&ctempl,
                   "#include \"%s\"\n\nint main(int argc, char* argv[]){\n    "
                   "printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n",
                   chfile, "%s");
      createfile(name, ctempl);
      char *upper;
      err = asprintf(&upper, "%s", filenames[i]);
      uppercaser(upper);
      char *htempl;
      err = asprintf(
          &htempl,
          "#ifndef _%s_\n#define _%s_\n\n#include <stdio.h>\n\n\n\n\n#endif\n",
          upper, upper);
      createfile(chfile, htempl);
      free(name);
      name = NULL;
      free(chfile);
      chfile = NULL;
      free(ctempl);
      ctempl = NULL;
      free(htempl);
      htempl = NULL;
    }
  }
  return 0;
}

int cpph(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.cc", filenames[i]);  
    /*
        for future reference, cannot start switch cases/if statements with
        declarations, must start with statements or else will not compile!
    */
    char *hfile;
    err = asprintf(&hfile, "%s.h", filenames[i]);
    if (fileexists(name) || fileexists(hfile)) {
      printf("The file %s or %s already exists!\n", name, hfile);
      return -1;
    } else {
      char *ctempl;
      err = asprintf(&ctempl,
                     "#include \"%s\"\n\nusing namespace std;\n\nint main(int "
                     "argc, char* argv[]){\n    cout << \"Hello World!\" << "
                     "endl;\n\n    return 0;\n}\n",
                     hfile);
      createfile(name, ctempl);
      char *upper;
      err = asprintf(&upper, "%s", filenames[i]);
      uppercaser(upper);
      char *htempl;
      err = asprintf(
          &htempl,
          "#ifndef _%s_\n#define _%s_\n\n#include <iostream>\n\n\n\n\n#endif\n",
          upper, upper);
      createfile(hfile, htempl);
      free(name);
      name = NULL;
      free(hfile);
      hfile = NULL;
      free(ctempl);
      ctempl = NULL;
      free(upper);
      upper = NULL;
      free(htempl);
      htempl = NULL;
    }
  }
  return 0;
}

int cmake(char **filenames, int numfiles) {
  char *name;
  int first = TRUE;
  char *make = (char*) malloc(1024);
  int err;

  if (fileexists("makefile")) {
    printf("The file %s already exists!\n", "makefile");
      return -1;
    }

  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.c", filenames[i]);
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      char templ[] =
          "#include <stdio.h>\n\nint main(int argc, char* argv[]){\n    "
          "printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n";
      createfile(name, templ);
      free(name);
      name = NULL;

    }
  }

  err = asprintf(&name, "%s.c", filenames[0]);
  err = asprintf(&make,
                    "C=gcc\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: "
                    "%s\n\t$(C) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n",
                    filenames[2], filenames[2], name, name, filenames[2],
                    filenames[2]);
  createfile("makefile", make);
  free(make);
  make = NULL;

  return 0;
}

// THIS NEEDS TO BE REDONE
int chmake(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.c", filenames[i]);
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      err = asprintf(&name, "%s.c", filenames[i]);
      char *chmfile;
      err = asprintf(&chmfile, "%s.h", filenames[i]);
      if (fileexists(name) || fileexists(chmfile)) {
        printf("The file %s or %s already exists!\n", name, chmfile);
        return -1;
      } else {
        char *ctempl;
        err = asprintf(&ctempl,
                       "#include \"%s\"\n\nint main(int argc, char* argv[]){\n "
                       "   printf(\"%s\", \"Hello world!\\n\");\n\n    return "
                       "0;\n}\n",
                       chmfile, "%s");
        createfile(name, ctempl);
        char *upper;
        err = asprintf(&upper, "%s", filenames[i]);
        uppercaser(upper);
        char *htempl;
        err = asprintf(&htempl,
                       "#ifndef _%s_\n#define _%s_\n\n#include "
                       "<stdio.h>\n\n\n\n\n#endif\n",
                       upper, upper);
        createfile(chmfile, htempl);
        char *make;
        err = asprintf(
            &make,
            "C=gcc\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: "
            "%s\n\t$(C) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n",
            filenames[i], filenames[i], name, name, filenames[i], filenames[i]);
        createfile("makefile", make);
        free(name);
        name = NULL;
        free(chmfile);
        chmfile = NULL;
        free(ctempl);
        ctempl = NULL;
        free(upper);
        upper = NULL;
        free(htempl);
        htempl = NULL;
        free(make);
        make = NULL;
      }
    }
  }
  return 0;
}

int cppmake(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.c", filenames[i]);
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      err = asprintf(&name, "%s.cc", filenames[i]);
      if (fileexists(name)) {
        printf("The file %s already exists!\n", name);
        return -1;
      } else {
        char templ[] =
            "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, "
            "char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    "
            "return 0;\n}\n";
        createfile(name, templ);
        char *make;
        err = asprintf(
            &make,
            "CC=g++\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: "
            "%s\n\t$(CC) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n",
            filenames[i], filenames[i], name, name, filenames[i], filenames[i]);
        createfile("makefile", make);
        free(name);
        name = NULL;
        free(make);
        make = NULL;
      }
    }
  }
  return 0;
}

int cpphmake(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s.cc", filenames[i]);
    char *hmfile;
    err = asprintf(&hmfile, "%s.h", filenames[i]);
    if (fileexists(name) || fileexists(hmfile)) {
      printf("The file %s or %s already exists!\n", name, hmfile);
      return -1;
    } else {
      char *ctempl;
      err = asprintf(&ctempl,
                     "#include \"%s\"\n\nusing namespace std;\n\nint main(int "
                     "argc, char* argv[]){\n    cout << \"Hello World!\" << "
                     "endl;\n\n    return 0;\n}\n",
                     hmfile);
      createfile(name, ctempl);
      char *upper;
      err = asprintf(&upper, "%s", filenames[i]);
      uppercaser(upper);
      char *htempl;
      err = asprintf(
          &htempl,
          "#ifndef _%s_\n#define _%s_\n\n#include <iostream>\n\n\n\n\n#endif\n",
          upper, upper);
      createfile(hmfile, htempl);
      char *make;
      err = asprintf(
          &make,
          "CC=g++\nCFLAGS=-Wall -pedantic\n\nexecutables=%s\n\n%s.o: "
          "%s\n\t$(CC) $(CFLAGS) %s -o %s\n\nclean:\n\trm -rf %s\n\n",
          filenames[i], filenames[i], name, name, filenames[i], filenames[i]);
      createfile("makefile", make);
      free(name);
      name = NULL;
      free(hmfile);
      hmfile = NULL;
      free(ctempl);
      ctempl = NULL;
      free(upper);
      upper = NULL;
      free(htempl);
      htempl = NULL;
      free(make);
      make = NULL;
    }
  }
  return 0;
}

int java(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    if (filenames[i][0] >= 97 &&
        filenames[i][0] <= 122)  // if the first character of the filename is a
                                 // small letter, capitalize it!
      filenames[i][0] -= 32;
    err = asprintf(&name, "%s.java", filenames[i]);
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      char *templ;
      err = asprintf(&templ,
                     "public class %s {\n\n\tpublic %s() {\n\n\t}\n\n\tpublic "
                     "static void main(String[] args) "
                     "{\n\n\t\tSystem.out.println(\"Hello World!\");\n\t}\n}\n",
                     filenames[i], filenames[i]);
      createfile(name, templ);
      free(name);
      name = NULL;
      free(templ);
      templ = NULL;
    }
  }
  return 0;
}

int scala(char **filenames, int numfiles) {
  char *name;
  int err;
  for (int i = 2; i < numfiles; i++) {
    if (filenames[i][0] >= 97 &&
        filenames[i][0] <= 122)  // if the first character of the filename is a
                                 // small letter, capitalize it!
      filenames[i][0] -= 32;
    err = asprintf(&name, "%s.scala", filenames[i]);
    if (fileexists(name)) {
      printf("The file %s already exists!\n", name);
      return -1;
    } else {
      char *templ;
      err = asprintf(&templ,
                     "object %s {\n\n\tdef main(args: Array[String]) "
                     "{\n\t\tprintln(\"Hello World!\")\n\t}\n}",
                     filenames[i]);
      createfile(name, templ);
      free(name);
      name = NULL;
      free(templ);
      templ = NULL;
    }
  }
  return 0;
}

int cproject(char **filenames, int numfiles) {
  int err;
  char *name;
  for (int i = 2; i < numfiles; i++) {
    err = asprintf(&name, "%s", filenames[2]);
    struct stat dir = {0};
    // MAKING DIRECTORIES IS WAY MORE COMPLICATED THAN IT NEEDS TO BE
    if (stat(name, &dir) == -1) {  // make sure the directory doesn't
                                    // exist. stat returns -1 if it doesn't
      mode_t process_mask = umask(0);
      mkdir(name, S_IRWXU | S_IROTH | S_IRGRP | S_IXOTH | S_IXGRP);
      err = asprintf(&name, "%s/headers", filenames[2]);
      mkdir(name, S_IRWXU | S_IROTH | S_IRGRP | S_IXOTH | S_IXGRP);
      err = asprintf(&name, "%s/bin", filenames[2]);
      mkdir(name, S_IRWXU | S_IROTH | S_IRGRP | S_IXOTH | S_IXGRP);
      umask(process_mask);

      // now onto the more straightforward part:
      err = asprintf(&name, "%s/%s.c", filenames[2], filenames[i]);
      char *chmfile;
      err = asprintf(&chmfile, "%s/headers/%s.h", filenames[2],
                      filenames[i]);
      if (fileexists(name) || fileexists(chmfile)) {
        printf("The file %s or %s already exists!\n", name, chmfile);
      } else {
        char *ctempl;
        err = asprintf(&ctempl,
                        "#include \"headers/%s.h\"\n\nint main(int argc, "
                        "char* argv[]){\n    printf(\"%s\", \"Hello "
                        "world!\\n\");\n\n    return 0;\n}\n",
                        filenames[i], "%s");
        createfile(name, ctempl);
        char *upper;
        err = asprintf(&upper, "%s", filenames[i]);
        uppercaser(upper);
        char *htempl;
        err = asprintf(&htempl,
                        "#ifndef _%s_\n#define _%s_\n\n#include "
                        "<stdio.h>\n\n\n\n\n#endif\n",
                        upper, upper);
        createfile(chmfile, htempl);
        char *make;
        err = asprintf(
            &make,
            "C=gcc\nCFLAGS=-Wall "
            "-pedantic\n\nexecutables=%s\n\nbin/%s.o: %s.c\n\t$(C) "
            "$(CFLAGS) %s.c -o "
            "bin/%s\n\nrun:\n\t./bin/%s\n\nclean:\n\trm -rf bin/%s\n\n",
            filenames[i], filenames[i], filenames[i], filenames[i],
            filenames[i], filenames[i], filenames[i]);
        char *makefilename;
        err = asprintf(&makefilename, "%s/makefile", filenames[i]);
        printf("%s", makefilename);
        createfile(makefilename, make);
        
        free(name);
        name = NULL;
        free(chmfile);
        chmfile = NULL;
        free(ctempl);
        ctempl = NULL;
        free(upper);
        upper = NULL;
        free(htempl);
        htempl = NULL;
        free(make);
        make = NULL;
        free(makefilename);
        makefilename = NULL;
      }

    } else {
      printf(
          "Sorry, that directory already exists. Move to a different "
          "directory to create the project.\n");
      return 1;
    }
  }

  return 0;
}

/* 
    makes a file by looking at the language it is supposed to be, adjusting
    filenames accordingly, and then passing the relevant info to a helper
    function 
*/
void makefile(char **filenames, char *lang, int numfiles) {
  int err = 0;
  
  /*
      This flag is used as a way to combine projects with the standard plate file
      creation functions. With projects, it works like
      makefiles, the first name input is the name of the project, and the rest
      will just be files included with the project.
      When this is set, creation of new projects will be skipped for the rest of
      the iterations through filenames
  */

  int namesum =
      checkstring(lang);  // little trick so I can use a switch statement
                          // rather than a huge chain of if/else if
                          // statements. Much more concise.
  if (namesum == 1)
    return;  // the case where argv[1] was either the wrong input or was
             // malicious

  switch (namesum) {
    case TXT:  // text files. Most would just use touch to make empty files
                // but since this takes like 5 seconds to implement included it
                // anyway
      err = templatizer(filenames, "txt", numfiles, "");
      break;

    case CLANG:  // C file case
      err = templatizer(
          filenames, "c", numfiles,
          "#include <stdio.h>\n\nint main(int argc, char* argv[]){\n    "
          "printf(\"%s\", \"Hello world!\\n\");\n\n    return 0;\n}\n");
      break;

    case CPLUSPLUS:  // C++ file case
      err = templatizer(
          filenames, "cc", numfiles,
          "#include <iostream>\n\nusing namespace std;\n\nint main(int argc, "
          "char* argv[]){\n    cout << \"Hello World!\" << endl;\n\n    "
          "return "
          "0;\n}\n");
      break;

    case HFILE:  // .h file case.
      err = hfile(filenames, numfiles);
      break;

    case CH:  // C file with an accompanying .h file.
      err = ch(filenames, numfiles);
      break;

    case CPPH:  // C++ wih header file
      err = cpph(filenames, numfiles);
      break;

    case CMAKE:
      err = cmake(filenames, numfiles);
      break;

    case CHMAKE:  // C file with an accompanying .h file and makefile
      err = chmake(filenames, numfiles);
      break;
    case CPPMAKE:
      err = cppmake(filenames, numfiles);
      break;

    case CPPHMAKE:  // C++ wih header file
      err = cpphmake(filenames, numfiles);
      break;

    case JAVA:  // java!
      err = java(filenames, numfiles);
      break;

    case PYTHON:  // python!
      err =
          templatizer(filenames, "py", numfiles,
                      "import sys\n\n\ndef main():\n\tprint(\"Hello world!\")"
                      "\n\n\nif __name__==\"__main__\":\n\tmain()\n");
      break;

    case GO:  // Google Go AKA golang
      err = templatizer(
          filenames, "go", numfiles,
          "package main// change this as needed\n\nimport \"fmt\"\n\nfunc "
          "main() {\n\tfmt.Printf(\"Hello World!\\n\")\n}\n");
      break;

    case SCALA:  // scala!
      err = scala(filenames, numfiles);
      break;

    case HASKELL:  // haskell
      err = templatizer(filenames, "hs", numfiles,
                        "main = do\n\tputStrLn \"Hello World!\"");
      break;

    case SH:  // basic sh script
      err = sh(filenames, lang, numfiles);
      break;

    case BASH:  // bash script
      err = sh(filenames, lang, numfiles);
      break;
    /*
        the one below is iffy. zsh is sometimes in usr/bin or usr/local/bin,
        depending on OS. On Mac, it is in usr/bin. On some Linux distros, it is
        in one of the two above directories.
    */
    case ZSH:  // zsh script
      err = sh(filenames, lang, numfiles);
      break;

    case KSH:  // ksh script
      err = sh(filenames, lang, numfiles);
      break;

    case CSH:  // csh script
      err = sh(filenames, lang, numfiles);
      break;

    case PERL:  // Perl script
      err = templatizer(filenames, "", numfiles,
                        "#!/usr/bin/perl\nprint(\"Hello World!\\n\");\n");
      break;

    case SCALAS:  // scala script
      err = templatizer(filenames, "", numfiles, "#!/usr/bin/env scala\n\n");
      break;

    case NODES:  // node script
      err = templatizer(filenames, "", numfiles, "#!/usr/bin/env node\n\n");
      break;

    case PYTHONS:  // python script
      err = templatizer(filenames, "", numfiles, "#!/usr/bin/env python\n\n");
      break;

    case HTML:  // basic html file
      err = templatizer(
          filenames, "html", numfiles,
          "<!DOCTYPE html>\n<html>\n<link href=\"stylesheet.css\" "
          "rel=\"stylesheet\" type=\"text/css\" />\n<meta "
          "charset=\"utf-8\">\n\n<head>\n\t<title>TITLE GOES "
          "HERE</title>\n</head>\n\n<body>\n\t<p>\n\t\tThis is some "
          "text\n\t</p>\n</body>\n</html>\n");
      break;

    case HTMLS:  // html with script tag
      err = templatizer(
          filenames, "html", numfiles,
          "<!DOCTYPE html>\n<html>\n<link href=\"stylesheet.css\" "
          "rel=\"stylesheet\" type=\"text/css\" />\n<meta "
          "charset=\"utf-8\">\n\n<head>\n\t<title>TITLE GOES "
          "HERE</title>\n</head>\n<script>\n\n</"
          "script>\n<body>\n\t<p>\n\t\tThis is some "
          "text\n\t</p>\n</body>\n</html>\n");
      break;

    case CSS:  // rudementary CSS file
      err = templatizer(filenames, "css", numfiles, "body {\n\n}\n");
      break;

    case JAVASCRIPT:  // basic javascript file with a makeshift main since
                      // main isn't required in JS
      err = templatizer(
          filenames, "js", numfiles,
          "\n\nfunction main() {\n\tconsole.log(\"Hello World!\");\n} "
          "\n\nmain();\n");
      break;

    case RUBY:  // ruby
      err =
          templatizer(filenames, "rb", numfiles, "puts \"Hello World!\"\n\n");
      break;

    case JQUERY:  // JQuery
      err = templatizer(filenames, "js", numfiles,
                        "$(document).ready(function() {\n\n});\n");
      break;

    case PHP:  // PHP for posterity's sake
      err = templatizer(filenames, "php", numfiles,
                        "<?php\n\necho \"Hello World!\"\n\n?>\n");
      break;

    case OCAML:  // Objective-CAML
      err = templatizer(
          filenames, "ml", numfiles,
          "let main () =\n\tPrintf.printf \"Hello World!\\n\"\n\nlet _ = "
          "main ()\n");
      break;

    case ERLANG:  // erlang!
      err = templatizer(filenames, "erl", numfiles, "\n");
      break;

    case COFFEE:  // coffeescript
      err = templatizer(filenames, "coffee", numfiles,
                        "Console.log(\"Hello World!\")\n\n");
      break;

    case MD:  // markdown
      err = templatizer(filenames, "md", numfiles, "# Title\n\n## Header 1");
      break;

    case CPROJ:  // this was more of an exercise in learning file operations
                  // in C than anything. It actually works.
      cproject(filenames, numfiles);
      break;
    default:
      printf(
          "the file was not successfully created! Check command "
          "formatting. For help, use \"plate -h\" or \"plate help\"\n");
  }
  if (err == -1)
    printf("There is something wrong. Check above output to see why!");
}

int main(int argc, char **argv) {
  if (argc == 1 || calcstrsum(argv[1]) == 425 || calcstrsum(argv[1]) == 149)
    printhelp();
  // else if ( calcstrsum(argv[1]) == 448 && argv[1][0] == 't' ) test();
  else {
    makefile(argv, argv[1], argc);
  }
  printf("Testing");
  return 0;
}
