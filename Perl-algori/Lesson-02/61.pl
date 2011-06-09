#!/usr/bin/env perl 

use strict;
use warnings;

my @countries = (
        {
            name            =>      'Finland',
            area            =>      130119,
            language        =>      ['Finnish', 'Swedlish'],
            government      =>      'constitutional republic' 
        },

        {
            name            =>      'Canada',    
            area            =>      3849000,
            language        =>      ['English', 'French'],
            government      =>      'confederation with perliamentary democracy'
        },

        {
            name            =>      'USA',    
            area            =>      3618770,
            language        =>      ['English'],
            government      =>      'federal republic with democracy'
        },

   );

#foreach my $country (@countries) {
#    if (grep ($_ eq "English", @{${$country}{language}})) {
#        foreach my $language (@{${$country}{language}}) {
#            print $ {$country} {name}, " speaks $language\n";
#        }
#    }
#}

foreach my $country (@countries) {
    my @languages = @{ $country->{language} };
    if (@languages > 1) {
        foreach my $language (@languages) {
            print $country->{name}, " speaks $language\n";
        }
    }
}
