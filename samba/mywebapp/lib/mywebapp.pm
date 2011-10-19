package mywebapp;
use Template;
use Dancer ':syntax';

our $VERSION = '0.1';

get '/hello/:name' => sub {
    my $name = params->{name};
    template 'hello', { name => $name };
};

get '/gksdud' => sub {
    template 'gksdud';
};

get '/' => sub {
    template 'index';
};

any '/test' => sub {
    template 'test';
};

get '/select' => sub {
    template 'select';
};

post '/sum' => sub {
    "I say a number:".params->{number};
};

get '/add' => sub {
    template 'test', {
        action => '/add',
        num1   => 0,
        num2   => 0,
        sum    => 0,
    };
};

post '/add' => sub {
    my $num1 = param('num-1') || 0;
    my $num2 = param('num-2') || 0;
    template 'test', {
        action  => '/add',
        num1    => $num1,
        num2    => $num2,
#        sum     => $num1 + $num2,
    };
};

true;
