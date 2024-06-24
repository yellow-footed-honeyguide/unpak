#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

void
print_version ()
{
  printf ("%s\n", "1.24.0");
}

void
print_help ()
{
  printf ("Usage: unpak [OPTIONS]\n");
  printf ("\n");
  printf ("Utility for unpacking any type of archive 📦\n");
  printf ("\n");
  printf ("Options:\n");
  printf ("  -v, --version    Print the version information and exit.\n");
  printf ("  -h, --help       Print this help message and exit.\n");
  printf ("\n");
  printf ("Usage example:\n");
  printf ("  unpak archive.7z\n");
}

void
handle_options (int argc, char *argv[])
{

  /* Current option being processed. */
  int opt;

  /* Define the structure for long options. */
  struct option long_options[] = {
    {"version", no_argument, 0, 'v'},
    {"help", no_argument, 0, 'h'},
    {0, 0, 0, 0}
  };


  /* Parse the command-line options and will not handle them accordingly. */
  while ((opt = getopt_long (argc, argv, "vh", long_options, NULL)) != -1)
    {
      switch (opt)
	{
	  /* Print the --version information. */
	case 'v':
	  print_version ();
	  exit (0);

	  /* Print the  --help information. */
	case 'h':
	  print_help ();
	  exit (0);

	  /* Handle unknown options, provide a help message. */
	default:
	  printf ("Use unpak --help\n");
	  exit (1);
	}
    }
}
