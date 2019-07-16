#include treePublic.h

#define OK 1
#define KO 0

int
main (
  void
   )
{
  node_t root, tmp;
  data_t d;
  int retValue, end = 0;
  char row[MAXC];
  FILE fp = NULL;

  root = NULL;
  root = createEmptyTree();

  while (!end) {

    fprintf (stdout, User selectionn);
    fprintf (stdout, t1) Insert one single nodent2) Cancel one single nodent3) Search a noden);
    fprintf (stdout, t4) Print BST on stdoutnt5) Write BST on filent6) Read BST from filen);
    fprintf (stdout, t7) Compute min and maxnt8) Endnt );
    scanf (%1s, row);

    switch (atoi(row)) {

      case 1
        fprintf (stdout, data );
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, Input erro.n);
          exit (0);
        }
	root = insert (root, d);
	break;

      case 2
        fprintf (stdout, data );
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, Input erro.n);
          exit (0);
        }
	root = delete (root, d);
	break;

      case 3
        fprintf (stdout, data );
	retValue = readData (stdin, &d);
        if (retValue==0) {
          fprintf (stderr, Input error.n);
          exit (0);
        }

	tmp = searchI (root, d);
	if (tmp != NULL) {
	  fprintf (stdout, Iterative Search Found - );
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, Iterative Search Not Foundn);
        }
	tmp = searchR (root, d);
	if (tmp  != NULL) {
	  fprintf (stdout, Recursive Search Found - );
          writeData (stdout, getData(tmp));
	} else {
	  fprintf (stdout, Recursive Search Not Foundn);
        }
	break;

      case 4
	writeTree (stdout, root, INORDER);
	break;

      case 5
	fprintf (stdout, File Name );
	scanf (%s, row);

        if (strcmp (row, stdout) == 0) {
          fp = stdout;
        } else {
   	  fp = fopen (row, w);
        }

        if (fp == NULL) {
         fprintf (stderr, Error Opening File %sn, row);
         break;
	}

	writeTree (fp, root, PREORDER);

        if (strcmp (row, stdout) != 0) {
	  fclose(fp);
	}
	break;

      case 6
	fprintf (stdout, File Name );
	scanf (%s, row);

	fp = fopen (row, r);
	if (fp == NULL) {
	  fprintf (stderr, Error Opening File %sn, row);
	} else {
	  freeTree (root);
	  root = readTree (fp);
	}
	break;

      case 7
        fprintf (stdout, Tree minimum iterative ); 
        tmp = treeMinI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, Tree minimum recursive ); 
        tmp = treeMinR (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, Tree maximum iterative );
        tmp = treeMaxI (root);
        writeData (stdout, getData(tmp));
        fprintf (stdout, Tree maximum recursive ); 
        tmp = treeMaxR (root);
        writeData (stdout, getData(tmp));
	break;

      case 8
	end = 1;
	break;

      default
	fprintf (stderr, Unknown Option.n);
	break;
    }
  }

  freeTree(root);

  return (OK);
}
