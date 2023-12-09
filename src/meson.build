prefix = get_option('prefix')
datadir = prefix / get_option('datadir')
pkgdatadir = datadir / meson.project_name()

dog_sources = [
  'main.c',
  'dog-application.c',
  'dog-window.c',
  'dog-debug-info.c',
  resources,
]

dog_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.2'),
]

executable('dog', dog_sources,
  dependencies: dog_deps,
       install: true,
)
