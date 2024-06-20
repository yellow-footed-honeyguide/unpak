#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <zlib.h>
#include <archive.h>
#include <archive_entry.h>

#define BUFFER_SIZE 8192

int unpack_targz(const char* filepath) {
    struct archive* a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);

    if (archive_read_open_filename(a, filepath, BUFFER_SIZE) != ARCHIVE_OK) {
        fprintf(stderr, "Error: Failed to open %s\n", filepath);
        archive_read_free(a);
        return 1;
    }

    struct archive_entry* entry;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char* entry_path = archive_entry_pathname(entry);
        archive_entry_set_pathname(entry, entry_path);

        if (archive_read_extract(a, entry, 0) != ARCHIVE_OK) {
            fprintf(stderr, "Error: Failed to extract %s\n", entry_path);
            archive_read_free(a);
            return 1;
        }
    }

    archive_read_free(a);
    return 0;
}

int unpack_zip(const char* filepath) {
    struct archive* a = archive_read_new();
    archive_read_support_format_zip(a);

    if (archive_read_open_filename(a, filepath, BUFFER_SIZE) != ARCHIVE_OK) {
        fprintf(stderr, "Error: Failed to open %s\n", filepath);
        archive_read_free(a);
        return 1;
    }

    struct archive_entry* entry;
    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char* entry_path = archive_entry_pathname(entry);
        archive_entry_set_pathname(entry, entry_path);

        if (archive_read_extract(a, entry, 0) != ARCHIVE_OK) {
            fprintf(stderr, "Error: Failed to extract %s\n", entry_path);
            archive_read_free(a);
            return 1;
        }
    }

    archive_read_free(a);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    const char* filepath = argv[1];
    char* ext = strrchr(filepath, '.');

    if (ext == NULL) {
        fprintf(stderr, "Error: Invalid file extension\n");
        return 1;
    }

    int result;
    switch (ext[1]) {
        case 'g':
            if (strcmp(ext, ".gz") == 0) {
                result = unpack_targz(filepath);
            } else {
                fprintf(stderr, "Error: Unsupported file extension\n");
                return 1;
            }
            break;
        case 'z':
            if (strcmp(ext, ".zip") == 0) {
                result = unpack_zip(filepath);
            } else {
                fprintf(stderr, "Error: Unsupported file extension\n");
                return 1;
            }
            break;
        default:
            fprintf(stderr, "Error: Unsupported file extension\n");
            return 1;
    }

    return result;
}
