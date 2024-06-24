#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <archive.h>
#include <archive_entry.h>
#include "handle_options.h"
#include "lib_unpak.h"

#define BUFFER_SIZE 8192

/**
 * Unpacks an archive file using the specified unpacking function.
 *
 * @param filepath The path to the archive file.
 * @param unpack_func The function pointer to the appropriate unpacking function.
 * @return 0 on success, 1 on failure.
 */
int
unpack_archive (const char *filepath, int (*unpack_func) (struct archive *))
{
  struct archive *a = archive_read_new ();
  unpack_func (a);

  if (archive_read_open_filename (a, filepath, BUFFER_SIZE) != ARCHIVE_OK)
    {
      fprintf (stderr, "Error: Failed to open %s\n", filepath);
      archive_read_free (a);
      return 1;
    }

  struct archive_entry *entry;
  while (archive_read_next_header (a, &entry) == ARCHIVE_OK)
    {
      const char *entry_path = archive_entry_pathname (entry);
      archive_entry_set_pathname (entry, entry_path);

      if (archive_read_extract (a, entry, 0) != ARCHIVE_OK)
	{
	  fprintf (stderr, "Error: Failed to extract %s\n", entry_path);
	  archive_read_free (a);
	  return 1;
	}
    }

  archive_read_free (a);
  return 0;
}





/**
 * The main function of the program.
 *
 * @param argc The number of command-line arguments.
 * @param argv An array of command-line argument strings.
 * @return 0 on success, 1 on failure.
 */
int
main (int argc, char *argv[])
{

  handle_options (argc, argv);

  if (argc != 2)
    {
      fprintf (stderr, "Usage: %s <file_path>\n", argv[0]);
      return 1;
    }

  const char *filepath = argv[1];
  const char *ext = strrchr (filepath, '.');

  if (ext == NULL)
    {
      fprintf (stderr, "Error: Invalid file extension\n");
      return 1;
    }

  int result;
  if (strcmp (ext, ".gz") == 0 || strcmp (ext, ".tar.gz") == 0
      || strcmp (ext, ".tgz") == 0)
    {
      result = unpack_archive (filepath, unpack_targz);
    }

  else if (strcmp (ext, ".bz2") == 0 || strcmp (ext, ".tar.bz2") == 0
	   || strcmp (ext, ".tbz2") == 0)
    {
      result = unpack_archive (filepath, unpack_tarbz2);
    }
  else if (strcmp (ext, ".xz") == 0 || strcmp (ext, ".tar.xz") == 0
	   || strcmp (ext, ".txz") == 0)
    {
      result = unpack_archive (filepath, unpack_tarxz);
    }

  else if (strcmp (ext, ".zip") == 0)
    {
      result = unpack_archive (filepath, unpack_zip);
    }
  else if (strcmp (ext, ".7z") == 0)
    {
      result = unpack_archive (filepath, unpack_7z);
    }
    else if (strcmp (ext, ".deb") == 0)
    {
      result = unpack_archive (filepath, unpack_deb);
    }

    else if (strcmp (ext, ".rpm") == 0)
    {
      result = unpack_rpm(argv[1], "./");
    }

  else
    {
      fprintf (stderr, "Error: Unsupported file extension\n");
      return 1;
    }

  return result;
}
