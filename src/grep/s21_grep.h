#ifndef SRC_GREP_S21_GREP_H_
#define SRC_GREP_S21_GREP_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex.h>
#include <getopt.h>
#define MAXSTRLEN 9999

typedef struct s21_flag {
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
  int flag_h;
  int flag_s;
  int flag_f;
  int flag_o;
  int  ind_fname;
} s21_struct_flag;

int flag_pars(int argc, char *argv[], s21_struct_flag *flag, char *sample);
int grep_file(s21_struct_flag *flag, FILE *fp, regex_t reg, char *file);
int mk_reg_f(s21_struct_flag *flag, char *sample, char *file_name);
int getstr_file(char *sample, char *file_name);
int s21_grep(s21_struct_flag *flag, int argc, char **argv, char *sample);
int make_print_char(char *sample);
int print_match(FILE *fp, int nline, int indicst, s21_struct_flag *flag, char *text,
regmatch_t *pmatch, char *file);

#endif  // SRC_GREP_S21_GREP_H_
