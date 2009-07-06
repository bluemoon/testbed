VERSION='0.0.1'
APPNAME='stateTest'

# these variables are mandatory ('/' are converted automatically)
srcdir = '.'
blddir = 'build'

def set_options(opt):
	# options provided by the modules
	opt.tool_options('compiler_cxx')

def configure(conf):
	conf.check_tool('compiler_cxx')
	#conf.write_config_header('config.h')
	#conf.check_cfg(path='pkg-config', args=' --cflags --libs', package='gtk+-2.0', uselib_store='GTK')


def build(bld):
	staticlib = bld.new_task_gen(
		features = 'cxx cprogram',
		source   = 'main.cpp',
		target   = 'stateTest',
		)
		
