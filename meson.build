project('unpak', 'c', version: '0.1.0')

cc = meson.get_compiler('c')
archive_dep = cc.find_library('archive', required: true)

src = ['unpak.c', 'lib_unpak.c']

executable('unpak', 
           src, 
           dependencies: [archive_dep],
           install: true)
