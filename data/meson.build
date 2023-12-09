subdir('icons')

blueprints = custom_target('blueprints',
  input: files(
    'ui/window.blp',
    'ui/shortcuts.blp',
  ),
  output: '.',
  command: [find_program('blueprint-compiler'), 'batch-compile', '@OUTPUT@', '@CURRENT_SOURCE_DIR@', '@INPUT@'],
)

resources_conf = configuration_data()
resources_conf.set('appid', application_id)

resources = gnome.compile_resources(
  'dog',
  configure_file(
    input: 'dog.gresource.xml.in',
    output: 'dog.gresource.xml',
    configuration: resources_conf,
  ),
  dependencies: blueprints,
)

desktop_conf = configuration_data()
desktop_conf.set('appid', application_id)
desktop_file = i18n.merge_file(
          input: configure_file(
            input: files('page.codeberg.SOrg.DogGTK.desktop.in.in'),
            output: 'page.codeberg.SOrg.DogGTK.desktop.in',
            configuration: desktop_conf,
          ),
          output: '@0@.desktop'.format(application_id),
         type: 'desktop',
       po_dir: '../po',
      install: true,
  install_dir: get_option('datadir') / 'applications',
)

desktop_utils = find_program('desktop-file-validate', required: false)
if desktop_utils.found()
  test('Validate desktop file', desktop_utils, args: [desktop_file])
endif

appstream_conf = configuration_data()
appstream_conf.set('appid', application_id)
appstream_file = i18n.merge_file(
        input: configure_file(
          input: files('page.codeberg.SOrg.DogGTK.metainfo.xml.in.in'),
          output: 'page.codeberg.SOrg.DogGTK.metainfo.xml.in',
          configuration: appstream_conf,
        ),
        output: '@0@.metainfo.xml'.format(application_id),
       po_dir: '../po',
      install: true,
  install_dir: get_option('datadir') / 'metainfo',
)

appstreamcli = find_program('appstreamcli', required: false)
if appstreamcli.found()
  test('Validate appstream file', appstreamcli, args: ['validate', '--no-net', appstream_file])
endif

install_data('page.codeberg.SOrg.DogGTK.gschema.xml',
  install_dir: get_option('datadir') / 'glib-2.0/schemas',
)

compile_schemas = find_program('glib-compile-schemas', required: false)
if compile_schemas.found()
  test('Validate schema file',
       compile_schemas,
       args: ['--strict', '--dry-run', meson.current_source_dir()])
endif