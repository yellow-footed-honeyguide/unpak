project('unpak', 'c', version: '0.1.0')

cc = meson.get_compiler('c')

zlib_dep = cc.find_library('z', required: true)
archive_dep = cc.find_library('archive', required: true)

src = ['unpak.c']

executable('unpak', src, dependencies: [zlib_dep, archive_dep])
