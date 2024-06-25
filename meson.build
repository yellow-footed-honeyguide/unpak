project('unpak', 'c', version: '1.2.0')

cc = meson.get_compiler('c')
archive_dep = cc.find_library('archive', required: true)
rpm_dep = cc.find_library('rpm', required: true)
rpmio_dep = cc.find_library('rpmio', required: true)

src = ['unpak.c', 'lib_unpak.c', 'handle_options.c']

executable('unpak', 
           src, 
           dependencies: [archive_dep, rpm_dep, rpmio_dep],
           install: true)
