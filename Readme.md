# unpak - Universal File Extractor

A powerful command-line utility for extracting various archive formats on Unix-like systems.

## Description

unpak is a versatile file extraction tool that seamlessly handles multiple archive formats, including `.tar.gz` and `.zip`. With its user-friendly interface and efficient extraction capabilities, unpak simplifies the process of unpacking files on Unix-like operating systems.

## Features
🌋 Multi-Format Mastery 📦

unpak effortlessly tackles `.tar.gz` and `.zip` archives, ensuring you never get stuck with an unsupported format again!

🌋 Command-Line Convenience ⌨️

Experience the power and efficiency of a command-line utility, designed for seamless integration with your favorite Unix-like environment.

🌋 Robust and Reliable 🛡️

Built with industry-standard libraries (`zlib` and `libarchive`), unpak delivers rock-solid performance and unwavering reliability.

🌋 Efficient Extraction 🚀

Optimized algorithms and streamlined processes ensure lightning-fast extraction times, saving you precious time and effort.

🌋 Cross-Platform Compatibility 🌐

Whether you're on Linux, macOS, or BSD, unpak adapts seamlessly to your Unix-like environment, providing a consistent and familiar experience.

## Getting Started

### Dependencies
- `zlib`
- `libarchive`

### Installing
To install unpak, follow these steps:

git clone https://github.com/your-username/unpak.git
cd unpak
mkdir build
cd build
meson ..
ninja


Optionally, you can install unpak system-wide:

sudo ninja install


### Executing program
To extract an archive, simply run the `unpak` executable with the archive file as an argument:

./unpak archive.tar.gz
./unpak archive.zip


unpak will automatically detect the archive format and extract its contents to the current directory.

## Issue Templates
If you encounter a bug or have a feature request, please use one of the following templates:

- [Bug Report](.github/ISSUE_TEMPLATE/bug_report.md)
- [Feature Request](.github/ISSUE_TEMPLATE/feature_request.md)

## Contributing

If you'd like to contribute to this project, please read our [Contributing Guidelines](CONTRIBUTING.md) for more information on how to get started.

## Authors
- Your Name - your@email.com

## License
This project is licensed under the [MIT License](LICENSE).
