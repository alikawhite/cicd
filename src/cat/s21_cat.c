#include "s21_cat.h"

#include <stdio.h>

int main(int argc, char *argv[]) {
  int result = 0;
  if (argc < 2) {
    result = 1;
  } else {
    s21_cat_option options = {0, 0, 0, 0, 0, 0, 0};
    s21_insertOptions(&options, argc, argv);
    if (!options.error) {
      result = s21_filesManipulation(options, argv);
    } else {
      result = 1;
    }
  }

  if (result == 1)
    fprintf(stderr, "Hello, world! Hey, Verter!");
  return result;
}

void s21_insertOptions(s21_cat_option *options, int argc, char *argv[]) {
  int opt, index;
  S21_longOption;
  while ((opt = getopt_long(argc, argv, cat_options, longOptions, &index)) !=
         -1) {
    if (opt == 'b') {
      options->numberNonblank = 1;
      if (options->numberLine) {
        options->numberLine = 0;
      }
    } else if (opt == 'e') {
      options->endLine = 1;
      options->noPrintSym = 1;
    } else if (opt == 'E') {
      options->endLine = 1;
    } else if (opt == 'n') {
      if (!options->numberNonblank) {
        options->numberLine = 1;
      }
    } else if (opt == 's') {
      options->squeezeBlank = 1;
    } else if (opt == 'v') {
      options->noPrintSym = 1;
    } else if (opt == 'T') {
      options->tab = 1;
    } else if (opt == 't') {
      options->noPrintSym = 1;
      options->tab = 1;
    } else {
      options->error = 1;
    }
  }
}

int s21_filesManipulation(s21_cat_option options, char *argv[]) {
  int result = 0, LC = 0;
  unsigned char c = '\n';
  #if __linux__
    int ent = 1;
    int ent1 = 0;
    char cch = 'a', c1 = 'b';
  #endif

  for (int i = 1; argv[i]; i++) {
    if (argv[i][0] == '-') {
      continue;
    }
    #if __APPLE__
      LC = 0;
    #endif
    FILE *file = NULL;
    if ((file = fopen(argv[i], "r+")) != NULL) {
      int newLine = 1, flag = 0;
      #if __linux__
        // cch = 'a', c1 = 'b', c = 'c';
        if (ent == 0 && options.numberLine) {
          newLine = 0;
        }
      #endif
      while (!feof(file)) {
        #if __linux__
          c1 = cch;
          cch = c;
          // ent1 = ((!(cch == 10 || cch == 11) || !(c1 == 10 || c1 == 11)) && options.squeezeBlank);
          ent1 = ((cch != 10 || c1 != 10) && options.squeezeBlank);
        #endif
        c = getc(file);
          // printf("___%d___", c);
        #if __linux__
          if (c == 255) {
            c = cch;
            cch = c1;
          }
        #endif

        if (feof(file)) {
          break;
        }
        if (newLine && options.numberLine && !(options.squeezeBlank && flag)) {
          printf("%6d\t", ++LC);
        }
        if (c == '\n') {
          // printf("BBBB");
          if (options.endLine && !(options.squeezeBlank && flag)) printf("$");
          #if __APPLE__
            if (!(options.squeezeBlank && flag)) {
              printf("%c", c);
            } else {
              continue;
            }
          #elif __linux__
            if (!(options.squeezeBlank && flag && !ent1) && !options.squeezeBlank) {
              // printf("BBBB1");
              // ent1 = !(c1 == 10 || c1 == 11);
              printf("%c", c);
            } else {
              if (options.squeezeBlank && ent1) {
                printf("%c", c);
              }
              continue;
          }
          #endif
          #if __APPLE__
          if (newLine)
            flag = 1;
          #endif
          newLine = 1;
          continue;
        } else {
          if ((options.numberNonblank) && newLine) printf("%6d\t", ++LC);
          if (options.tab && c == '\t') {
            printf("^I");
          } else {
            if (options.noPrintSym)
              s21_noPrint(c);
            else
              printf("%c", c);
          }
        }
        flag = 0;
        newLine = 0;
      }
      #if __linux__
      ent = (c == 10 || c == 11) && options.numberLine;
      #endif
    } else {
      result = 1;
    }
    if (file != NULL) fclose(file);
  }
  return result;
}

void s21_noPrint(unsigned char c) {
  int stop = 0;
  if (c == 0x7f) {
    printf("^?");
    stop = 1;
  }
  if (c > 0x7f && c < 0xa0 && !stop) {
    printf("M-");
    c -= 128;
  }
  if (!stop) {
    if (c <= 31 && c != '\t' && c != '\n') {
      printf("^%c", c + '@');
    } else {
      printf("%c", c);
    }
  }
}
