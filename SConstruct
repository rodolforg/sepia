VariantDir('build', 'src', duplicate = 0)

env = Environment( tools = ['default', 'gettext'] )

env['PACKAGE'] = 'br.eng.rodolfo.sepia'
env['GETTEXT_PACKAGE'] = env['PACKAGE']

env.ParseConfig("pkg-config gtkmm-3.0 --cflags --libs")

SConscript('src/SConscript', variant_dir='build', exports = 'env')

VariantDir('build/locale', 'po', duplicate = 0)
SConscript('po/SConscript.i18n', exports = 'env')
SConscript('po/SConscript', variant_dir='build/locale', exports = 'env')
