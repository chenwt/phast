/* $Id: indel_history.h,v 1.1 2005-08-23 17:24:18 acs Exp $
   Written by Adam Siepel, 2005
   Copyright 2005, Adam Siepel, University of California */

#ifndef IND_HIST
#define IND_HIST

typedef enum {INS, DEL, BASE} indel_char;

typedef struct {
  indel_char type;
  int start;
  int len;
} Indel;

typedef struct {
  TreeNode *tree;
  int ncols;
  List **indels;
} CompactIndelHistory;

typedef struct {
  TreeNode *tree;
  int ncols;
  char **indel_strings;            /* make bin vector later */
} IndelHistory;

IndelHistory *ih_new(TreeNode *tree, int ncols);
void ih_free(IndelHistory *ih);
CompactIndelHistory *ih_new_compact(TreeNode *tree, int ncols);
void ih_free_compact(CompactIndelHistory *cih);
IndelHistory *ih_expand(CompactIndelHistory *cih);
CompactIndelHistory *ih_compact(IndelHistory *ih);
void ih_print(IndelHistory *ih, FILE *outf, char *msa_name, char *prog_name);
void ih_print_compact(CompactIndelHistory *cih, FILE *outf, char *msa_name, 
                      char *prog_name);
MSA *ih_as_alignment(IndelHistory *ih, MSA *msa);
CompactIndelHistory *ih_read_compact(FILE *inf);
IndelHistory *ih_new_from_file(FILE* inf);
IndelHistory *ih_extract_from_alignment(MSA *msa, TreeNode *tree);
IndelHistory *ih_reconstruct(MSA *msa, TreeNode *tree);

#endif