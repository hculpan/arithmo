project('arithmo', 'c',
  version : '0.1',
  default_options : ['warning_level=3', '-Wnewline-eof=off']
)

inc = include_directories('include')

executable('arithmo', ['src/main.c', 'src/lexer.c'],
  include_directories : inc,
  install : true
)

# Define the test executable for the lexer.
test_exe = executable('test_lexer', ['tests/test_lexer.c', 'src/lexer.c'],
  include_directories : inc,
)

test('Lexer tests', test_exe)