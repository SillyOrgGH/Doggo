app_conf = configuration_data()
app_conf.set('appid', application_id)

configure_file(
  input: 'POTFILES.in',
  output: 'POTFILES',
  configuration: app_conf,
)

i18n.gettext('doggo', preset: 'glib')