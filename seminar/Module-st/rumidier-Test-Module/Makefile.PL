use inc::Module::Install;

# Define metadata
name     'rumidier-Test-Module';
all_from 'lib/rumidier/Test/Module.pm';
author   q{rumidier - 조한영 <rumidier@gmail.com>};
license  'perl';

build_requires 'Test::More';

auto_install;

WriteAll;

