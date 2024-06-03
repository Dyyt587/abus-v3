Import('rtconfig')
from building import *
import os

cwd = GetCurrentDir()
src = Glob('src/*.c')
inc = [cwd]
inc += [cwd+"/src"]



CXXFLAGS = ''


group = DefineGroup('abus', src, depend = ['PKG_USING_AUNITY'], CPPPATH = inc, CXXFLAGS = CXXFLAGS)

Return('group')
