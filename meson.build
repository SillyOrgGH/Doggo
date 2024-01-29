project('doggo', 'c',
          license: 'GPL3+',
          version: '4.2',
    meson_version: '>= 0.62.0',
  default_options: [ 'warning_level=2', 'werror=false', 'c_std=gnu11', ],
)

i18n = import('i18n')
gnome = import('gnome')
fs = import('fs')
cc = meson.get_compiler('c')

if get_option('profile') == 'development'
  profile = '.Devel'
  if fs.is_dir('.git')
    vcs_tag = run_command('git', 'rev-parse', '--short', 'HEAD', check: true).stdout().strip()
    if vcs_tag == ''
      version_suffix = '-devel'
    else
      version_suffix = '-@0@'.format(vcs_tag)
    endif
  else
    version_suffix = '-devel'
  endif
else
  profile = ''
  version_suffix = ''
endif

application_id = 'page.codeberg.SOrg.DogGTK@0@'.format(profile)
application_name = 'Doggo'
developer_name = 'Silly Org, sungsphinx & Contributors'

prefix = get_option('prefix')
datadir = prefix / get_option('datadir')
pkgdatadir = datadir / meson.project_name()

config_h = configuration_data()
config_h.set_quoted('APPLICATION_ID', application_id)
config_h.set_quoted('APPLICATION_NAME', application_name)
config_h.set_quoted('DEVELOPER_NAME', developer_name)
config_h.set_quoted('VERSION', '@0@@1@'.format(meson.project_version(), version_suffix))
config_h.set_quoted('VERSION_NO_SUFFIX', '@0@'.format(meson.project_version()))
config_h.set_quoted('GETTEXT_PACKAGE', 'dog')
config_h.set_quoted('LOCALEDIR', join_paths(get_option('prefix'), get_option('localedir')))
config_h.set_quoted('PROFILE', profile)
configure_file(output: 'config.h', configuration: config_h)
add_project_arguments(['-I' + meson.project_build_root()], language: 'c')

project_c_args = []
test_c_args = [
  '-Wcast-align',
  '-Wdeclaration-after-statement',
  '-Werror=address',
  '-Werror=array-bounds',
  '-Werror=empty-body',
  '-Werror=implicit',
  '-Werror=implicit-function-declaration',
  '-Werror=incompatible-pointer-types',
  '-Werror=init-self',
  '-Werror=int-conversion',
  '-Werror=int-to-pointer-cast',
  '-Werror=main',
  '-Werror=misleading-indentation',
  '-Werror=missing-braces',
  '-Werror=missing-include-dirs',
  '-Werror=nonnull',
  '-Werror=overflow',
  '-Werror=parenthesis',
  '-Werror=pointer-arith',
  '-Werror=pointer-to-int-cast',
  '-Werror=redundant-decls',
  '-Werror=return-type',
  '-Werror=sequence-point',
  '-Werror=shadow',
  '-Werror=strict-prototypes',
  '-Werror=trigraphs',
  '-Werror=undef',
  '-Werror=write-strings',
  '-Wformat-nonliteral',
  '-Wignored-qualifiers',
  '-Wimplicit-function-declaration',
  '-Wlogical-op',
  '-Wmissing-declarations',
  '-Wmissing-format-attribute',
  '-Wmissing-include-dirs',
  '-Wmissing-noreturn',
  '-Wnested-externs',
  '-Wno-cast-function-type',
  '-Wno-dangling-pointer',
  '-Wno-missing-field-initializers',
  '-Wno-sign-compare',
  '-Wno-unused-parameter',
  '-Wold-style-definition',
  '-Wpointer-arith',
  '-Wredundant-decls',
  '-Wstrict-prototypes',
  '-Wswitch-default',
  '-Wswitch-enum',
  '-Wundef',
  '-Wuninitialized',
  '-Wunused',
  '-fno-strict-aliasing',
  ['-Werror=format-security', '-Werror=format=2'],
]
if get_option('buildtype') != 'plain'
  test_c_args += '-fstack-protector-strong'
endif
foreach arg: test_c_args
  if cc.has_multi_arguments(arg)
    project_c_args += arg
  endif
endforeach
add_project_arguments(project_c_args, language: 'c')

subdir('data')
subdir('src')
subdir('po')

summary({
  'Profile': get_option('profile'),
}, section: 'Development')

gnome.post_install(
     glib_compile_schemas: true,
    gtk_update_icon_cache: true,
  update_desktop_database: true,
)
