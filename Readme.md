# unpak - Universal File Extractor

A command-line utility for extracting various archive formats on Unix-like systems.

## Description

unpak is a versatile file extraction tool that seamlessly handles multiple archive formats. With its user-friendly interface and efficient extraction capabilities, unpak simplifies the process of unpacking files on Unix-like operating systems.

## Features
🌋 Multi-Format Mastery 📦

The unpak can unpack files from the following archives:
- `.tar.gz`   
- `.tar.bz2`   
- `.tar.xz`   
- `.zip`
- `.7z` 
- `.deb` 

The unpak can decompress:
- `.gz`   
- `.bz2`   
- `.xz`   


🌋 Command-Line Convenience ⌨️

Experience the power and efficiency of a command-line utility, designed for seamless integration with your favorite Unix-like environment.  

🌋 Almost zero overhead 🦾  

A utility written in pure C with a couple of C shared libraries.

🌋 Cross-Platform Compatibility 🌐

Whether you're on Linux, macOS, or BSD, unpak adapts seamlessly to your Unix-like environment, providing a consistent and familiar experience.

## Getting Started

### Dependencies
- `libarchive`

### Installing
To install unpak, follow these steps:
```
git clone https://github.com/your-username/unpak.git
cd unpak
mkdir build
cd build
meson ..
ninja
```
or 
```sudo ninja install``` (if you want to add unpak to executable path)



### Executing program
To extract an archive, simply run the `unpak` executable with the archive file as an argument:

unpak archive.tar.gz
unpak archive.zip
unpak archive.7z

unpak will automatically detect the archive format and extract its contents to the current directory.

## Issue Templates
If you encounter a bug or have a feature request, please use one of the following templates:

- [Bug Report](.github/ISSUE_TEMPLATE/bug_report.md)
- [Feature Request](.github/ISSUE_TEMPLATE/feature_request.md)

## Contributing

If you'd like to contribute to this project, please read our [Contributing Guidelines](CONTRIBUTING.md) for more information on how to get started.

## Authors
Contributors names and contact info

ex. Sergey Veneckiy 

mail: s.venetsky@gmail.com


## License
This project is licensed under the [MIT License](LICENSE).
