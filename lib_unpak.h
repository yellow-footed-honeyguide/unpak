#ifndef ACTIONS_H
#define ACTIONS_H

int unpack_targz (struct archive *a);

int unpack_zip (struct archive *a);

int unpack_7z (struct archive *a);


int unpack_tarbz2 (struct archive *a);


int unpack_tarxz (struct archive *a);

int unpack_xz (struct archive *a);

int unpack_bz2 (struct archive *a);

int unpack_deb (struct archive *a);

int unpack_rpm (const char *rpm_file, const char *output_dir);
#endif
