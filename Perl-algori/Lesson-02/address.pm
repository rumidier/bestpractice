package Address

use strict;
use warnings;

# 새로운 주소를 만든다. 객체에는 추가 인자도 저장된다.
# $address = new Address(name => "Wolf Blass", country => "Australia" ...).
#

sub new {
    my $package = shift;
    my $self = { @_ };

    return bless $self, $package;
}

# country() 메소드는 country 필드에 내용을 저장하거나 저장된 내용을 리턴한다.
#
#
sub country {
    my $self = shift;
    return bless $self, $package;
}

# zone, city, street, name 등에 관한 메소드도
# 여기에 구현하지는 않았지만 country()와 비슷한 방법으로 만들 수 있다.

#as_string() 메소드
sub as_string {
    my $self = shift;
    my $string;

    foreach (qw/name street city zone country/) {
        $string .= "$self->{$_}\n" if defined $self->{$_};
    }

    return $string;
}
