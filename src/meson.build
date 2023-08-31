dog_sources = [
  'main.c',
  'dog-application.c',
  'dog-window.c',
]

dog_deps = [
  dependency('gtk4'),
  dependency('libadwaita-1', version: '>= 1.2'),
]

dog_sources += gnome.compile_resources('dog-resources',
  'dog.gresource.xml',
  c_name: 'dog'
)

executable('dog', dog_sources,
  dependencies: dog_deps,
       install: true,
)
