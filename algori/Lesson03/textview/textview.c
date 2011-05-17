void
load_file (void)
{
  FILE *fp;
  char buf[256];
  line *t;

  if ((fp = fopen (filename, "rt")) == NULL)
    {
      printf ("\n Error : Can't read that file.");
      exit (EXIT_FAILURE);
    }

  total = 0;
  printf ("\n File loading...");

  while (!feof (fp))
    {
      fgets (buf, 255, fp);

      if (strlen (buf) > 80)
        {
          buf[80] = 0;
        }

      if ((t = (line *) malloc (sizeof (line))) == NULL)
        {
          printf ("\n Error : Out of Memory.");
          exit (EXIT_FAILURE);
        }

      if ((t->buf = (char *) malloc (strlen (buf))) == NULL)
        {
          printf ("\n Error : Out of Memory.");
          exit (EXIT_FAILURE);
        }

      strcpy (t->buf, buf);
      t->prev = tail->prev;
      t->next = tail;
      tail->prev->next = t;
      tail->prev = t;
      total++;
    }

  fclose (fp);
}

void
show_header (void)
{
  textattr ((LIGHTGRAY<< 4) | BLACK);
  gotoxy (1, 1);
  cprintf (" TVIEW : %-12s   Loc : %6d of %6d   By Lee jaekyu   ",
           filename, now, total);
  textattr ((BLACK<< 4 | LIGHTGRAY);
}

