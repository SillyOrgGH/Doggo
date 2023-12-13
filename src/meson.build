prefix = get_option('prefix')
datadir = prefix / get_option('datadir')
pkgdatadir = datadir / meson.project_name()

dog_sources = [
  'main.c',
  'application.c',
  'window.c',
  'debug-info.c',
  resources,
]

dog_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.2'),
]

executable('doggo', dog_sources,
  dependencies: dog_deps,
       install: true,
)
