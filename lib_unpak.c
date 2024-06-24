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
