/**
 * Initializes the archive structure for unpacking tar.gz files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_targz (struct archive *a)
{
  archive_read_support_filter_all (a);
  archive_read_support_format_all (a);
  return 0;
}


/**
 * Initializes the archive structure for unpacking zip files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_zip (struct archive *a)
{
  archive_read_support_format_zip (a);
  return 0;
}


/**
 * Initializes the archive structure for unpacking 7z files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_7z (struct archive *a)
{
  archive_read_support_format_7zip (a);
  return 0;
}


/**
 * Initializes the archive structure for unpacking tar.bz2 files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_tarbz2 (struct archive *a)
{
  archive_read_support_filter_bzip2 (a);
  archive_read_support_format_tar (a);
  return 0;
}

/**
 * Initializes the archive structure for unpacking tar.xz files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_tarxz (struct archive *a)
{
  archive_read_support_filter_xz (a);
  archive_read_support_format_tar (a);
  return 0;
}

/**
 * Initializes the archive structure for unpacking xz files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_xz (struct archive *a)
{
  archive_read_support_filter_xz (a);
  archive_read_support_format_raw (a);
  return 0;
}

/**
 * Initializes the archive structure for unpacking bz2 files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_bz2 (struct archive *a)
{
  archive_read_support_filter_bzip2 (a);
  archive_read_support_format_raw (a);
  return 0;
}

/**
 * Initializes the archive structure for unpacking .deb files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
int
unpack_deb (struct archive *a)
{
  archive_read_support_format_ar (a);
  archive_read_support_format_tar (a);
  archive_read_support_filter_gzip (a);
  archive_read_support_filter_xz (a);
  return 0;
}



/**
 * Initializes the archive structure for unpacking .rpm files.
 *
 * @param a The archive structure to initialize.
 * @return Always returns 0.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <rpm/rpmlib.h>
#include <rpm/rpmts.h>
#include <rpm/rpmio.h>
#include <rpm/rpmpgp.h>
#include <rpm/rpmdb.h>

int unpack_rpm(const char *rpm_file, const char *output_dir) {
    rpmts ts = NULL;
    FD_t fd = NULL;
    Header hdr = NULL;
    rpmRC rc;
    int result = 0;

    // Initialize RPM library
    rpmReadConfigFiles(NULL, NULL);
    ts = rpmtsCreate();

    // Disable signature checking
    rpmtsSetVSFlags(ts, _RPMVSF_NOSIGNATURES);

    // Open the RPM file
    fd = Fopen(rpm_file, "r.ufdio");
    if (fd == NULL) {
        fprintf(stderr, "Failed to open RPM file: %s\n", rpm_file);
        result = -1;
        goto cleanup;
    }

    // Read the RPM header
    rc = rpmReadPackageFile(ts, fd, rpm_file, &hdr);
    if (rc != RPMRC_OK) {
        fprintf(stderr, "Failed to read RPM header (error code: %d)\n", rc);
        result = -1;
        goto cleanup;
    }

    // Create the output directory
    char cmd[1024];
    snprintf(cmd, sizeof(cmd), "mkdir -p %s", output_dir);
    system(cmd);

    // Extract the contents
    snprintf(cmd, sizeof(cmd), "rpm2cpio %s | (cd %s && cpio -idmv)", rpm_file, output_dir);
    if (system(cmd) != 0) {
        fprintf(stderr, "Failed to extract RPM contents\n");
        result = -1;
        goto cleanup;
    }

    printf("RPM unpacked successfully to: %s\n", output_dir);

cleanup:
    if (hdr) headerFree(hdr);
    if (fd) Fclose(fd);
    if (ts) rpmtsFree(ts);
    return result;
}
