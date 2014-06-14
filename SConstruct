import sys, os

env = Environment()
pybase = 'python%s' % sys.version[0:3]
env.Append(CPPPATH=[os.path.join(sys.prefix, 'include', pybase)],
           LIBPATH=[os.path.join(sys.prefix, 'lib', pybase, 'config')],
           LIBS=['lib%s' % pybase])

if env['PLATFORM'] not in ['cygwin', 'win32']:
    env.Append(LIBS=['util'])

env.Append(CPPDEFINES=['BOOST_PYTHON_STATIC_LIB', 'BOOST_PYTHON_STATIC_MODULE'],
           CPPPATH=['$boostIncludes'] )

env.Append( LIBS=['boost_iostreams', 'boost_python-py27'] )

env.Replace(SHLIBPREFIX = '')
fitpy = env.SharedLibrary('somelib', ['somelib.cpp'] + Glob('somelib/*.cpp'))
