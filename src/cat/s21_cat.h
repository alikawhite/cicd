#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdio.h>
#include <string.h>

#if __linux__
#define S21_longOption                             \
  const struct option longOptions[] = {            \
      {"number-nonblank", no_argument, NULL, 'b'}, \
      {"number", no_argument, NULL, 'n'},          \
      {"squeeze-blank", no_argument, NULL, 's'}};  \
  const char *cat_options = "benstvET"
#elif __APPLE__
#define S21_longOption                     \
  const struct option *longOptions = NULL; \
  const char *cat_options = "benstv"
#endif

typedef struct {
  int numberNonblank;
  int endLine;
  int numberLine;
  int squeezeBlank;
  int tab;
  int error;
  int noPrintSym;
} s21_cat_option;

void s21_insertOptions(s21_cat_option *options, int argc, char *argv[]);
int s21_filesManipulation(s21_cat_option options, char *argv[]);
void s21_noPrint(unsigned char c);
#endif  // SRC_CAT_S21_CAT_H_
