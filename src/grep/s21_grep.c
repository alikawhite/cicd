#include "../grep/s21_grep.h"

int flag_pars(int argc, char *argv[], s21_struct_flag *flag, char *sample_list) {
  int opt_flag = 0, result = 1, num_samples = 0, n;
  sample_list[0] = '\0';
  while ((opt_flag = getopt(argc, argv, "e:ivclnhsf:o")) != -1) {
    switch (opt_flag) {
      case 'e':
        n = 0;
        if (num_samples > 0) {
          strcat(sample_list, "|");
        }
        flag -> flag_e = 1;
        if (strlen(sample_list) + strlen(optarg) < MAXSTRLEN) {
          strcat(sample_list, optarg);
        } else {
          result = 0;
          break;
        }
        n = 1;
        num_samples += n;
        break;

      case 'f':
        n = 0;
        if (num_samples > 0) {
          strcat(sample_list, "|");
        }
        flag -> flag_f = 1;
        n = getstr_file(sample_list + strlen(sample_list), optarg);
        if (n == -1) {
          result = 0;
          break;
        }
        num_samples += n;
        break;
      case 'i':
        flag ->flag_i = 1;
        break;
      case 'v':
        flag ->flag_v = 1;
        break;
      case 'c':
        flag ->flag_c = 1;
        break;
      case 'l':
        flag ->flag_l = 1;
        break;
      case 'n':
        flag ->flag_n = 1;
        break;
      case 'h':
          flag -> flag_h = 1;
        break;
      case 's':
          flag -> flag_s = 1;
        break;
      case 'o':
        flag -> flag_o = 1;
        break;
      default:
        result = 0;
    }
  }
  return result;
}

int make_print_char(char *sample) {
  int result = 1;
  char box[MAXSTRLEN];
  if (sample) {
    int i = 0, j = 0;
    strcpy(box, sample);
    while (box[j] && i < MAXSTRLEN) {
      if (strchr("[]/^$.?*+(){}", box[j])) {
        if (j > 0 && box[j - 1] == '\\') {
          sample[i++] = box[j++];
        } else {
          sample[i++] = '\\';
          sample[i++] = box[j++];
        }
      } else {
        sample[i++] = box[j++];
      }
    }
    if (i == MAXSTRLEN)
      result = 0;
    else
      sample[i] = '\0';
  } else {
    result = 0;
  }
  return result;
}

int s21_grep(s21_struct_flag *flag, int argc, char **argv, char *sample_list) {
  int result = 1;
  char sample[MAXSTRLEN] = {0};
  if (!flag -> flag_f && !flag -> flag_e) {
    snprintf(sample, MAXSTRLEN, "%s", argv[optind++]);
  }
  if (flag -> flag_f || flag -> flag_e) {
    snprintf(sample, MAXSTRLEN, "%s", sample_list);
  }
  if (make_print_char(sample)) {
    int files_number = (argc - optind);
    if (files_number > 1 && !flag -> flag_h && !flag ->flag_l) {
      flag ->  ind_fname = 1;
    }
    for (int i = optind; i < argc; i++) {
      result = mk_reg_f(flag, sample, argv[i]);
      if (!result && !flag -> flag_s) {
        fprintf(stderr, "Hello, world!");
      }
    }
  } else {
    result = 0;
  }
  return result;
}

int getstr_file(char *sample, char *file_name) {
  FILE *fp;
  fp = fopen(file_name, "r");
  int i = 0, num_samples = 0;
  if (fp == NULL) {
    i = -1;
  } else {
    int ch;
    while ((ch = fgetc(fp)) != EOF && i < MAXSTRLEN) {
      if (ch == 13 || ch == 10) {
        sample[i++] = '|';
        num_samples++;
      } else {
        sample[i++] = ch;
      }
    }
    if (i < MAXSTRLEN) {
      if (sample[i - 1] == '|') {
        sample[i - 1] = '\0';
      }
    } else {
      i = -1;
    }
    fclose(fp);
  }
  return i != -1 ? num_samples : -1;
}

int mk_reg_f(s21_struct_flag *flag, char *sample, char *file_name) {
  int cflags = (flag -> flag_i) ? REG_ICASE | REG_EXTENDED : REG_EXTENDED;
  int result = 1;
  regex_t reg;
  FILE *fp;
  fp = fopen(file_name, "r");
  if (fp == NULL) {
    result = 0;
  } else {
    if (regcomp(&reg, sample, cflags)) {
      result = 0;
    } else {
      result = grep_file(flag, fp, reg, file_name);
      regfree(&reg);
      fclose(fp);
    }
  }
  return result;
}

int print_match(FILE *fp, int nline, int indicst, s21_struct_flag *flag,
char *text, regmatch_t *pmatch, char *file) {
  int match = 0;
  if (indicst == 0 && !flag -> flag_v) {
    match = 1;
  }
  if (indicst == REG_NOMATCH && flag -> flag_v) {
    match = 1;
  }
  if (match && !flag -> flag_l && !flag -> flag_c && flag -> ind_fname
      && file != NULL) {
    printf("%s:", file);
  }
  if (match && !flag -> flag_l && !flag -> flag_c && flag -> flag_n) {
    printf("%d:", nline);
  }
  if (match && !flag -> flag_l && !flag -> flag_c && !flag -> flag_o) {
    if (feof(fp) && text[strlen(text)] != '\n') {
      strcat(text, "\n");
    }
    if (isatty(fileno(stdout)) && !flag -> flag_v) {
      printf("%.*s%.*s%s", (int)pmatch[0].rm_so, text,
      (int)pmatch[0].rm_eo - (int)pmatch[0].rm_so, text
             + (int)pmatch[0].rm_so,
      text + (int)pmatch[0].rm_eo);
    } else {
      printf("%s", text);
    }
  }
  if (flag -> flag_o && match) {
    if (isatty(fileno(stdout)))
      printf("%.*s\n", (int)pmatch[0].rm_eo - (int)pmatch[0].rm_so,
             text + (int)pmatch[0].rm_so);
    else
      printf("%.*s\n", (int)pmatch[0].rm_eo - (int)pmatch[0].rm_so,
             text + (int)pmatch[0].rm_so);
  }
  return match;
}

int grep_file(s21_struct_flag *flag, FILE *fp, regex_t reg, char *file) {
  int result = 1;
  char text[MAXSTRLEN] = {0};
  regmatch_t pmatch[1];
  int line_matches = 0, nline = 1;
    while (fgets(text, MAXSTRLEN - 1, fp) != NULL) {
    int indicst = regexec(&reg, text, 1, pmatch, 0);
    if (indicst == 0 || indicst == REG_NOMATCH) {
      line_matches += print_match(fp, nline, indicst, flag,
                                      text, pmatch, file);
      nline++;
    } else {
      result = 0;
      break;
    }
  }
  if (result) {
    if (flag ->flag_l && line_matches > 0) {
      printf("%s\n", file);
    }
    if (flag -> flag_c && !flag -> flag_l && flag -> ind_fname) {
      printf("%s:", file);
    }
    if (flag -> flag_c && !flag ->flag_l) {
      printf("%d\n", line_matches);
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  s21_struct_flag flag;
  int result = 0;
  char sample_list[MAXSTRLEN] = {0};
  memset(&flag, 0, sizeof(flag));
  result = flag_pars(argc, argv, &flag, sample_list);
  if ((argc >= 3) && result) {
    result = s21_grep(&flag, argc, argv, sample_list);
  } else if (!result) {
    fprintf(stderr, "Hello, world!");
  }
  return result == 1 ? 0 : 1;
}
