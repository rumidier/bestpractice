#!/usr/bin/env perl 

use 5.010;
use utf8;
use strict;
use warnings;

use Encode;
use LWP::UserAgent;
use HTML::TreeBuilder;
use HTML::Element;
use Data::Dumper;

binmode(STDOUT, ":utf8");

die "인자가 모자라\n" unless @ARGV;

my ( $language, $word ) = @ARGV;

my %dic_data;
if ($word) {
    %dic_data = full_data();
    for my $da ( keys %dic_data ) {
        say "@{ $dic_data{$da} }";
    }
    search_continue($word);
}
else {
    %dic_data = full_data();
    while ( chomp(my $word = <STDIN>) ) {
        search_continue($word);
    }
}

sub full_data {
    open my $fh, "<:encoding(UTF-8)", "cache.data"
        or die "connet open < cache.data: $!"; 

    my %full_data;
#$_ = enconding_utf8($_);
    while (<$fh>) {
        chomp(my $list = $_);
        $list =~ m!<word id="(?<word>[^"]+)">(?<data>[^<]+)</word>!;

        my $word  = $+{word};
        my $data  = $+{data};

        push @{ $full_data{$word} }, $data;
    }

    close $fh;

    return %full_data;
}

sub search_continue {
    my $word = shift;
    my $ua = LWP::UserAgent->new;
    $ua->timeout(10);
    $ua->env_proxy;

    my $response =
        $ua->get("http://endic.naver.com/popManager.nhn?m=search&searchOption=&query=$word");

    my $lists;
    if ($response->is_success) {
        $lists = $response->decoded_content;
    }
    else {
        die $response->status_line;
    }

    my $tree = HTML::TreeBuilder->new;
    $tree->parse($lists);
    $tree->eof;

    my $dic_select = $tree->look_down('class', 'list_select');

    if ($language eq 'ek') {
        if (!$dic_select) {
            my @body_selects = $tree->look_down('class', qr/word_num word_num2 .*?$/);

            for my $body_select (@body_selects) {
#print_body($body_select);
                parser_bonmun($body_select, $word);
            }
        }
        else {
            my $select_value = $dic_select->look_down('class', "underlink N=a:pos.tab");
            $select_value->as_text ? parser_word($tree) : print_idiom($tree);
        }
    }
    elsif ($language eq 'ke') {
        if (!$dic_select) {
            my $word_num 
        }
        else {
            my $tt_24 = $tree->look_down('class', qr/box_wrap24/);
            if ($tt_24) {
                my @tt_body = $tt_24->look_down('_tag', 'dt');
                say $_->as_text for @tt_body;
            }

            my $tt_21 = $tree->look_down('class', qr/box_wrap21/);
            if ($tt_21) {
                my @tt_21_body = $tt_21->look_down('_tag', 'dt');
                say $_->as_text for @tt_21_body;
            }
        }
    }
    else {
        say "그거 아니야";
    }
}

#sub print_body {
#    my $body_select = shift;
#
#    my $body_check = $body_select->look_down('alt', '본문');
#
#    if ( $body_select->look_down('alt', '본문') ) {
#        say "[본문]";
#        my @body_text = $body_select->look_down('class', 'fnt_e30');
#        say $_->as_text for @body_text;
#    }
#}

sub parser_bonmun {
    my ( $body_select, $word ) = @_;

    die "parser_bonmun error\n" unless $body_select;

    if ( $body_select->look_down('alt', '본문') ) {
        say "[본문]";
        my @body_text = $body_select->look_down('class', 'fnt_e30');
        say $_->as_text for @body_text;
    }
}

sub print_idiom {
    my $tree = shift;
    say "[뜻]";
    my $mean = $tree->look_down('class', "first align_px mean_on");
    say $mean->as_text;
}

sub parser_word {
    my $tree       = shift;
    my @words      = $tree->look_down('class', qr/box_wrap1 .*?/);
    my $dic_select = $tree->look_down('class', 'list_select');

   
    my $full_words = qq{};
    for my $word (@words) {
        my $dic_title   = $word->look_down('class', 'dic_tit6');
        my @align_lines = $word->look_down('class', qr/ mean_on/);
        $full_words .= $dic_title->as_text."\n";
#         say $dic_title->as_text;

        for my $align_line (@align_lines) {
#            say $align_line->as_text;
            $full_words .= $align_line->as_text."\n";
        }
    }
    chomp $full_words;

    open my $fh, ">>:encoding(UTF-8)", "cache_2.data"
        or die "connet open >> cache_2.data: $!"; 
    my $result_word = sprintf(qq(<word id="naver">%s<word>),$full_words);

    print $fh $result_word;
    close $fh;
}
