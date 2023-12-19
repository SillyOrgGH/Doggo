subdir('icons')

app_conf = configuration_data()
app_conf.set('appid', application_id)

blueprints = custom_target('blueprints',
  input: files(
    'ui/window.blp',
    'ui/shortcuts.blp',
  ),
  output: '.',
  command: [find_program('blueprint-compiler'), 'batch-compile', '@OUTPUT@', '@CURRENT_SOURCE_DIR@', '@INPUT@'],
)

resources = gnome.compile_resources(
  'doggo',
  configure_file(
    input: 'doggo.gresource.xml.in',
    output: 'doggo.gresource.xml',
    configuration: app_conf,
  ),
  dependencies: blueprints,
)

desktop_file = i18n.merge_file(
          input: configure_file(
            input: files('app.desktop.in.in'),
            output: 'app.desktop.in',
            configuration: app_conf,
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

appstream_file = i18n.merge_file(
        input: configure_file(
          input: files('app.metainfo.xml.in.in'),
          output: 'app.metainfo.xml.in',
          configuration: app_conf,
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

configure_file(
  input: 'app.gschema.xml.in',
  output: '@0@.gschema.xml'.format(application_id),
  configuration: app_conf,
  install: true,
  install_dir: get_option('datadir') / 'glib-2.0/schemas',
)

compile_schemas = find_program('glib-compile-schemas', required: false)
if compile_schemas.found()
  test('Validate schema file',
       compile_schemas,
       args: ['--strict', '--dry-run', meson.current_source_dir()])
endif